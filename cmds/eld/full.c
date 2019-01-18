// full.c
// modify by mudring

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
    object ob;

    if (! SECURITY_D->valid_grant(me, "(immortal)"))
        return 0;

    seteuid(getuid(me));

    if (! arg) ob = me;
    else {
        ob = present(arg, environment(me));
        if (! ob) ob = find_player(arg);
        if (! ob) ob = find_living(arg);
    }

    if (! ob) return notify_fail("��Ҫ�ָ�˭��״̬��\n");

/*
    // if pker and no wizard cant full
    if (ob->is_pker() && ! wizardp(ob))
         return notify_fail("��ָ�ͨ�������ף���\n");
*/

    // player only can full self
    if (! wizardp(me) && ob != me)
         return notify_fail("��ֻ�ָܻ��Լ���״̬����\n");

    if (! wizardp(ob) && ob != me)
        message("channel:chat",
            HIG"���ָ����顿ĳ�ˣ�" + "��˵" + me->name(1) +
            "�ָ���"HIW + ob->name(1) + HIG" �ĸ������塣\n"NOR, users());
    if (ob->is_pker() && ! wizardp(ob))
        NPC_D->full_hp_status(ob);
    else
        NPC_D->full_hp_status(ob, 1);
    if (me == ob)
        message_vision(HIY "$N" HIY "���������дʣ���һ����ͱ��"
            "���������������ȡ�\n" NOR, me);
    else {
        message_vision(HIY "$N" HIY "����һָ��$n" HIY "���̾����"
            "����������ȡ�\n" NOR,
            me, ob);
    log_file("cmds/full",
        sprintf("%s full %s at %s\n",
            geteuid(me), geteuid(ob),log_time() ));
    }

    return 1;
}

int help()
{
    write(@HELP
ָ���ʽ : full <��������>
 
���ָ����Իָ���(��)��ָ������(������)������״̬��
 
HELP );
    return 1;
}


