//By exp
//changed by wuyou@sk_xyj 2002-12-6

#include <condition.h>
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string str;
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("qingxia-jian",1);
        if ( extra < 60) 
                return notify_fail("�����ϼ�������������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۻý���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!PFM_D->valid_family(me, "��˿��"))
            return notify_fail("�����͵ѧ����?\n");
        if( (int)me->query_skill("sword", 1) < 60 )
            return notify_fail("��Ļ�������̫�ͣ�\n");
        if( (int)me->query_skill("force", 1) < 60 )
            return notify_fail("����ڹ�������죬ʹ�����ۻý��ݣ�\n");
        if( (int)me->query("max_force") < 500 )
            return notify_fail("������������Ϊ���㣬ʹ�����ۻý��ݣ�\n");    
        if( (int)me->query("force") < 100 )
            return notify_fail("�������������㣬ʹ�����ۻý��ݣ�\n");         
        weapon = me->query_temp("weapon");
        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra*2);
        message_vision(HIW"$N���е�"+ weapon->name()+  "һ���ʣ��ͻ���һ���⻪����$n��
һ�����εĹ⻪�����á��Ի͡�������\n" + HIG"�⻪����������á��߸����ϣ�����Ʈ����$n
ֻ��������⻪�ݷ�����Լ�ü�޼䣬ȴ�ֲ���ȷ���������
���ı仯�������ѳ�Խ�����������ļ��ޣ������������޷����š�"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY"������ȷʵ����������޴����ڡ�
���Ǿ���$n��ȷ��������ʱ������Ȼ�ֲ����ˡ�"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(WHT"���漣���Ȼ���֣����漣���Ȼ��ʧ��"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"���еĶ����ͱ仯��������һɲ�Ǽ���ɣ���ֹ��
���������ǣ�ȴ���������磬ȴ�ֱ����Ǻ�������ӽ��漣��
��Ϊ�߶���仯������������$N�������ġ�"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->add_temp("apply/damage",-extra*2);
       me->add_temp("apply/attack",-extra*2);
       me->add("force", 100);
       me->start_busy(1+random(2));

       return 1;
}

