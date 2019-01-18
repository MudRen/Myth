//clublevel.c
//Edited by wuyou@sk_sjsj 2003-4-8

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string id, type, res;
    object ob;
    int level_me, level_ob, level;

    if (!me->query("club_master") && !wizardp(me))
        return notify_fail("ֻ�а���쵼�˲ſ������ð���Ա�ĵȼ���\n");

    if (!arg)
        return notify_fail("ָ���ʽ��clublevel <ĳ��> <����(0-10)>\n");

    if (sscanf(arg, "%s %s", id, level) == 2)
        ob = present(id, environment(me));
    else 
        return notify_fail("ָ���ʽ��clublevel <ĳ��> <����(0-10)>\n");

    if (!ob)
        return notify_fail("����û������ˡ�\n");

    if (ob == me && !wizardp(me))
        return notify_fail("�㲻���޸��Լ��İ��ɵȼ���\n");

    if (!userp(ob) && !wizardp(me))
        return notify_fail("��������ǲ������ˣ�\n");

    if (ob->query("club") != me->query("club") && !wizardp(me))
        return notify_fail("��ֻ�Ա��������ʹ���������\n");

    if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���أ�\n");

    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("�Է���æ���أ�\n");

    if (level > 10 || level < 0)
        return notify_fail("��ֻ������0��10�ļ���\n");

    if (level = 10)
        return notify_fail("���ѵ�����"+ob->query("name")+"�����������λ�ã���\n");
    
    level_me = me->query("club_level");
    level_ob = ob->query("club_level");

    if( level > level_ob )
        {
            type="����";
            res ="����$n��������һ��";
        }
    else
        {
            type = "��";
             res ="������$n�ļ������$n�ܽ�������";
        }

    message_vision("$N��$n�İ���ְλ�ȼ�"+type+"Ϊ"+chinese_number(level)+"����"+res+"��\n",me,ob);

    ob->set("club_level", level);

    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : clublevel <ĳ��> <����(0-10)>

���ð���Ա��ְλ�ȼ���
HELP
    );
    return 1;
}


