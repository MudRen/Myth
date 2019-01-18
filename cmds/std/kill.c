// kill.c
// modify by mudring

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;
void do_kill(object,object);

int main(object me, string arg)
{
    object obj, guard_ob;
    string *killer, callname;

    if (me->is_chatter())
        return 0;

    if (environment(me)->query("no_fight"))
        return notify_fail("���ﲻ׼ս����\n");

    if (environment(me)->query("name")=="�ٻ���")
        return notify_fail("����֮Σ,��̫�ðɣ�\n");

    if (!arg)
        return notify_fail("����ɱ˭��\n");

    if (!objectp(obj = present(arg, environment(me))))
        return notify_fail("����û������ˡ�\n");

    if (!obj->is_character() || obj->is_corpse())
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

    if(obj==me)
        return notify_fail("�� suicide -fָ���ȽϿ�:P��\n");

    if (arrayp(me->query_team())
        && member_array(obj, me->query_team()) != -1)
        return notify_fail("�����Լ������е���ҲҪɱ��̫���˵��˰ɣ�\n");

/*
    if (wizardp(me) && !wizardp(obj) && userp(obj))
        return notify_fail(":P\n");
*/

/*
    if (userp(obj)  && environment(obj)->query("short")!="������" && (newbiep(me) || newbiep(obj)) )
        return notify_fail("ϵͳ�������֣�:P\n");
*/

//modify by seng@2005-2-3

    if (userp(obj)  && environment(obj)->query("short")!="������" )       return notify_fail(HIW"��ɮ˵:ϵͳ������ң�:P\n"NOR);

    if (!valid_kill(me, obj, 0))
        return 0;

    // flood kill mudring Dec/12/2002
    if (me->is_fighting(obj) && me->is_killing(obj->query("id")))
        return notify_fail("���ͣ����ͣ�\n");

    callname = RANK_D->query_rude(obj);

    message_vision("\n$N����$n�ȵ�����"
        + callname + "�����ղ������������һ��\n\n", me, obj);        

    if (obj->query_temp("protected")
        && objectp(guard_ob = present(obj->query_temp("protect_ob"), environment(obj)))
        && (string)guard_ob->query_temp("protect") == obj->query("id")
        && guard_ob != me )
    {
        message_vision(HIC"$N����$n����˵�������ڴˣ����õ��ģ�\n"NOR,guard_ob,obj);
        message_vision(HIC"$N����ǰȥ��ס��$n�Ĺ�����\n"NOR, guard_ob, me);
        guard_ob->fight_ob(me);
        return 1;
    }

    do_kill(me, obj);

    return 1;
}

void do_kill(object me, object obj)
{
    me->kill_ob(obj);
    if (!userp(obj))
    {
        if (!obj->accept_kill(me))
            obj->kill_ob(me);
    }
    else
    {
/*
        // ת�����ѵ������۸�������
        // mudring Dec/08/2002
        if (metep(obj) && !metep(me))
            me->start_busy(1);
*/
/*
            me->start_busy(3);
        if (metep(me) && !metep(obj))
            obj->start_busy(3);
*/

        obj->fight_ob(me);
        tell_object(obj, HIR"�����Ҫ��" + me->name() 
            + "�����ಫ������Ҳ���������һ�� kill ָ�\n"NOR);
        me->set_temp("killed_time",time());
    	
    	if (environment(me)->query("short") != "��̨")
    	{
        	log_file("static/ATTEMP_KILL",sprintf("%s(%s) attempt kill %s(%s) at %s(%s) on %s\n",
            		me->name(1), getuid(me),obj->name(1),getuid(obj),
            		environment(me)->query("short"), file_name(environment(me)),ctime(time()) ));
        }

    }
}

int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ��������ҡ���ɱ���Է���kill �� fight ����
��ͬ����˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ����� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬����һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}

