// feng.c �������� ��Ѩ
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        object ob;
        string msg;
        ob=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��Ѩֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "whip")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

        if (!PFM_D->valid_family(me, "��˿��"))
                return notify_fail("��Ƕ���֮�ˣ������ô��У�\n");
        if((int)me->query_skill("jiuyin-xinjing",1) < 100)
                return notify_fail("������ľ��Ĺ����������ܷ�ס����Ѩ��!\n");

        if((int)me->query_skill("yinsuo-jinling",1) < 150)
                return notify_fail("�������������Ϊ����,Ŀǰ�����ܷ�ס����Ѩ��!\n");
        if((int)me->query("force") < 800)
                return notify_fail("���������ڲ���, ���ܷ�Ѩ! \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "��Ѩ���Ѿ������ס�ˣ��㻹��ʲô\n");

        msg = HIC "$Nʹ��"HIY"��������"HIC"���ϳ˵�Ѩ��������"+ ob->name() +""HIC"��ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";

        if((me->query_skill("whip")+random(me->query_skill("whip"))) >= ((int)target->query_skill("dodge")*3/4+random((int)target->query_skill("dodge")))) {
                msg += "���$p��̴�д�Ѩ���㣬���ܶ�����\n" NOR;
                target->start_busy( (int)me->query_skill("yinsuo-jinling",1) / 20 + 2);
                me->add("force", -150);
        } else {
                msg += HIG "����$p�����������ڶ����$P�Ĺ�����\n" NOR;
                me->start_busy(1+random(2));
        }
        message_vision(msg, me, target);

        return 1;
}

