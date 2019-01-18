// mark.c
// pickle 10-27-97

#include <skill.h>

#define SYNTAX "ָ���ʽ��mark [-r] <����> \n"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string msg, *marks, flag, iden;
    string *spells_systems=({"yaofa"});
    int allowed, i;
    object room;
    
     if (! SECURITY_D->valid_grant(me, "(immortal)")) return 0;
       if (me != this_player()) return 0;
    seteuid(getuid());

    if (member_array(me->query_skill_mapped("spells"), spells_systems) == -1)
	allowed=0;
    else allowed=1;
    if (!me->query_skill("spells")
     || !allowed)
        return notify_fail("����ѧ�ķ���ϵͳ��������ʩ�ö������������˼Ǻ�Ҳû�á�\n");
    if (environment(me)->query("no_mark"))
        return notify_fail("�㲻�����������¼Ǻš�\n");

    if (!arg)
    {
        if (!sizeof(me->query("�Ǻ�")))
	    return notify_fail("��Ŀǰ��û�������κμǺš�\n");
	msg="������Ŀǰ���µļǺţ�\n";
        marks=keys(me->query("�Ǻ�"));
	for(i=0; i<sizeof(marks); i++)
	{
	    msg+=marks[i]+"\t";
	    room=find_object(me->query("�Ǻ�/"+marks[i]));
	    msg+=room->query("short")+"\n";
	}
	msg+="\n";
	tell_object(me, msg);
	return 1;
    }
    if (!sscanf(arg, "-%s %s", flag, iden)) iden=arg;

    if (!flag)
    {
        if(sizeof(keys(me->query("�Ǻ�"))) >= 9)
	    return notify_fail("�����ֻ�ܼ�ס�Ÿ��ط���\n");
        me->set("�Ǻ�/"+arg, file_name(environment(me)));
	tell_object(me, "��׼������"
		+environment(me)->query("short")
		+"����Ϊ��"+iden+"����\n");
	return 1;
    }
    if (flag && flag != "r")
        return notify_fail("ֻ���� mark -r��\n");
    if (member_array(iden, keys(me->query("�Ǻ�"))) == -1)
	return notify_fail("�㲢û���á�"+iden+"�������κεط���\n");
    me->delete("�Ǻ�/"+iden);
    tell_object(me, "��ɾ����"+iden+"������Ǻš�\n");
    

    return 1;
}

int help (object me)
{
        write(SYNTAX + @HELP
 
����������ָ���ڷ����������Լ��ļǺţ������������
����ֱ�Ӷ���������䡣ֻ��ĳЩ���ɵķ����ж���������
���ָ���û�ж��������������õġ�

һ���˿��Լ�ס�����ط��������Լ������ĵȼ��йأ�����
���۷����ж�ߣ����ֻ�ܼ�ס�Ÿ��ط���

�������ʩ�ö�������Ŀ�ĵأ��뿴�������ɵ���ϸ���ͣ�
��������ܵĽ��͡�
HELP
        );
        return 1;
}
