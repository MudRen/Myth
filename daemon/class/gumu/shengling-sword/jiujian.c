#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        object weapon;
        extra = me->query_skill("shengling-sword",1);

        if (!PFM_D->valid_family(me, "��ԯ��Ĺ"))
                return notify_fail("�۾Ž������ֻ����ԯ��Ĺ���Ӳſ���ʹ�ã�\n");

        if ( extra < 200) return notify_fail("���ʥ�齣�����������죡\n");     
       
        if( (int)me->query("force") < 800 )      
                return notify_fail("�������������\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۾Ž������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        me->add("force", -300);
        weapon = me->query_temp("weapon");
        if(!target->is_busy()) target->start_busy(2);
        message_vision(RED  "\n\n$N�ڿ�Ծ�𣬱任���Σ�˲�Ʊ�������λ�����е�"+ weapon->name() +RED"����ɭȻ��������������$n ��\n\n" NOR, me, target);
        message_vision(HIC  "���������졹��$N����"+ weapon->name() +HIC"����һ����ֱ��$n��" NOR, me, target);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n�������ɢ����$N����"+ weapon->name() +HIR"��������Ľ���б��$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n���������졹��$N����"+ weapon->name() +HIY"��Ҷ���ɨ$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\n��ʮ����ħ����$N����"+ weapon->name() +HIW"���������$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(MAG  "\n��Ⱥħ���衹��$N����"+ weapon->name() +MAG"Я��������ֱ��$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n��������������$N����"+ weapon->name() +HIY"Ѹ�װ����$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIG  "\n�������˼䡹��$N����"+ weapon->name() +HIG"��Ȼ��Ϊһ����������$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC  "\n��ħӰ��������$N����"+ weapon->name() +HIC"������������$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM  "\n��ħ����Ӱ����$N����"+ weapon->name() +HIM"��Ϊ��ǧ��Ӱ����$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(RED  "\n$N�ս����ˣ�����"+ weapon->name() +RED"����������������,��һ��"+HIW"���Ž����ꡱ��" NOR, me, target);
        me->start_busy(2);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        return 1;
}

