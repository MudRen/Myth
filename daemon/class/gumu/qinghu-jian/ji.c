#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("qinghu-jian",1);
        if ( extra < 50) return notify_fail("���[�������]���������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۼ�������У�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        msg = MAG  "$N��������ؼ���ǧ��ħ���ޱ���������ʱ������ӿ��һʽ�� ��������� ���缱�������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N����"+ weapon->name()+ HIB "�ó�����Ĺ⻪����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "$N����"+ weapon->name()+ HIR "�����������ǵĺ�Х��$n��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "$N����"+ weapon->name()+ HIW "��Ȼ��������Ե���������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "��������ħ���֣�$N����"+ weapon->name()+ HIC "����Ī����Ȼ����$n����ǰ��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(1+random(2));       

        return 1;
}

