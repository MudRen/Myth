// ctitle.c
// by mudring Oct/23/2002.

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string tmp;
    object ob;

    if (!me->query("club_master") && !wizardp(me))
        return notify_fail("ֻ�а���쵼�˲ſ������ð���Ա��title��\n");

    if (!arg)
        return notify_fail("Usage��ctitle <sb> <title>\n");

    if (sscanf(arg, "%s %s", tmp, arg) == 2)
        ob = present(tmp, environment(me));
    else 
        return notify_fail("Usage��ctitle <sb> <title>\n");

    if (!ob)
        return notify_fail("����û������ˡ�\n");

    if (ob == me && !wizardp(me))
        return notify_fail("�㲻�ܸ����Լ��İ��ͷ�Ρ�\n");

    if (!userp(ob) && !wizardp(me))
        return notify_fail("��������ǲ������ˣ�\n");

/*
    if (metep(ob) && !wizardp(me))
        return notify_fail("������������죬�����������ա�\n");
*/

    if (ob->query("club") != me->query("club") && !wizardp(me))
        if (arg != "-cancel")
        return notify_fail("��ֻ�Ա��������ʹ���������\n");

    if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���أ�\n");

    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("�Է���æ���أ�\n");

    if (arg == "-cancel")
    {
        if (ob->query("new_title"))
        {
            ob->delete("new_title");
            return notify_fail("ͷ�������ϣ�\n");
        }
        else return notify_fail("�뵷�ң���\n");
    }

    if (strlen(arg) > 20 || strlen(arg) < 4)
        return notify_fail("��ˢ��Ļ���ҷ���ȥ��\n");

    arg = HIW "[" + ob->query("club") + "] " + trans_color(arg) + NOR;

    message_vision("$N��$n�İ��ͷ�θ�Ϊ" + arg + "��\n",
        me, ob);

    ob->set("new_title", arg);

    return 1;
}

