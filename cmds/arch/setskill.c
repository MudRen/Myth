// setSkill.c
// 25th, March 1997. - SPY

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i,j,level;
        mapping skill_status;
        object ob;
        string skill,obj;
        string *skills;

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

        if( !arg )      return notify_fail("setskill <ĳ��> <����>/all <������>��\n");
        if( !arg || sscanf(arg, "%s %s %d", obj, skill, level)!=3 )
                return notify_fail("setskill <ĳ��> <����>/all <������>��\n");
        ob = find_player(obj);
        if( !ob )       ob = find_living(obj);
        if( !ob )       ob = present(obj, environment(me));
        if( !ob ) return notify_fail("�Ҳ����������.\n");
        if( (wiz_level(me) < wiz_level(ob)) && userp(ob) )
                return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");
        if( level == 0 && wizardp(ob) )
                return notify_fail("�����ô������ʦ�Ĺ���ɾ����\n");
        if( (wiz_level(me) < wiz_level("(admin)")) && me!=ob )
                return notify_fail("��û������" + ob->name() + "���ܵ�Ȩ����\n");
        write(WHT"begin setting skills for "NOR + ob->short(1) + WHT"��\n"NOR);
        if( skill == "all" ) {
                if ( !(skill_status = ob->query_skills()) || !sizeof(skill_status) )
                        return notify_fail("�����û��ѧ���κμ��ܣ������� all ���������\n");
                skills  = keys(skill_status);
                j = sizeof(skill_status);
                for(i=0; i<j; i++) {
                        if( level ==0 ) {
                                ob->delete_skill(skills[i]);
                                write("deleting->" + to_chinese(skills[i]) + 
                                        "(" + skills[i] + ")\n");
                        }
                        else {
                                ob->set_skill(skills[i], level);
                                printf("setting-> %-36s%d\n", to_chinese(skills[i]) + 
                                        "(" + skills[i] + ")", level);
                        }
                }
        }
        else {
                if( level ==0 ) {
                        write("deleting->" + to_chinese(skills[i]) + "(" + skills[i] + ")\n");
                        ob->delete_skill(skill);
                }
                else    {
                        ob->set_skill(skill, level);
                        printf("setting-> %-36s%d\n", to_chinese(skill) + 
                                "(" + skill + ")", level);
                }
        }
        if( userp(ob) && ob!=me ) log_file("cmds/setskill",
                sprintf("%s(%s) setskill %s(%s) %s to level %d at %s.\n", me->name(1),
                        me->query("id"), ob->name(1), ob->query("id"), skill, level,
                        ctime(time()) ) );
        write(WHT"Done.\n"NOR);
        return 1;
}

int help()
{
        write(@LONG
ָ���ʽ��setskill  <ĳ��> <����>/all <������>��

�����趨ĳ�˵�ĳ�ּ��ܵļ�����, ����ڶ����� all �������е�
���ܸ�Ϊ�趨�ļ����������ѡ���˼�����Ϊ 0 ��ɾ�����˴���ܡ�

���棺�����ô����
LONG    );
        return 1;
}

