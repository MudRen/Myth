#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

void check_fight(object me, object target, object victim, int amount);
int remove_effect(object me, object target, int amount);

int perform(object me, object target)
{
        int skill, skill1, skill2;
        object victim = offensive_target(me);

        if( !target )
                return notify_fail("������˭���е��ƣ�\n");
        if( target->query("id") == me->query("id") )
                return notify_fail("�������Լ����е��ƣ�\n");
        if( !victim || victim->query("id") == target->query("id") )
                return notify_fail("��������Ķ��ֽ��е��ơ�\n");

        if( !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("ֻ�ܶ�������ս���еĶ���ʹ�õ��ơ�\n");
        if( !target->is_fighting(victim) )
                return notify_fail("���ͬ�鲻�������ս���С�\n");
        if( target->query_skill_mapped("unarmed") != "baihua-zhang" )
                return notify_fail("���ͬ��û����ʹ�ðٻ��ơ�\n");
        if( (int)target->query_temp("diezhang") )
                return notify_fail("���ͬ���Ѿ���ʹ�õ����ˡ�\n");
        if( (int)me->query_temp("diezhang") )
                return notify_fail("���Ѿ���ʹ�õ����ˡ�\n");
        if((int)me->query("force") < 25+(int)me->query("force_factor") )
                return notify_fail("�������������\n");
        if (!PFM_D->valid_family(me, "�¹�"))
                return notify_fail("�����¹�����֮�ܣ�\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
        if((int)target->query("force") < 25+(int)me->query("force_factor") )
                return notify_fail("���ͬ������������\n");
        if((int)target->query("kee") < 100 )
                return notify_fail("���ͬ����Ѫ���㣬û����ʩ���⹦��\n");

        if( !(int)target->query_temp("diezhang_request") ) {
                me->set_temp("diezhang_request", 1);
                tell_object(target, me->query("name")+"���㷢����������\n");
                return 1;
        }
        target->delete_temp("diezhang_request");

        me->add("force", -25-(int)me->query("force_factor"));
        target->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);
        target->receive_damage("kee", 100, me, "pfm");

        skill1 = me->query_skill("baihua-zhang");
        skill2 = target->query_skill("baihua-zhang");
        skill = (skill1 + skill2)/8;
        message_vision(HIY
                "$N��$n˫��һ�ģ�������ʱ���ʮ��Ϭ��������Ҳ�ϵ�����ࡣ\n"
                NOR, me, target);
        me->add_temp("apply/attack", skill);
        me->add_temp("apply/dodge",  skill);
        me->set_temp("diezhang", 1);
        target->add_temp("apply/attack", skill);
        target->add_temp("apply/dodge",  skill);
        target->set_temp("diezhang", 1);

        me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, victim, skill:), 1);
        return 1;
}

void check_fight(object me, object target, object victim, int amount)
{
        object weapon;

        if( !living(victim) || !present(victim->query("id"), environment(me)) ) 
                remove_effect(me, target, amount);

        else if( (!present(victim->query("id"), environment(me)) 
                  && target->is_fighting(victim))
                || (!present(target->query("id"), environment(me)) 
                    && me->is_fighting(victim)) ) 
                remove_effect(me, target, amount);

        else if( !present(target->query("id"), environment(me))
                || !target->is_fighting() || !me->is_fighting() 
                || !living(target) )
                remove_effect(me, target, amount);

        else if( target->query_skill_mapped("unarmed") != "baihua-zhang" )
                remove_effect(me, target, amount);

        else if( me->query_skill_mapped("unarmed") != "baihua-zhang" )
                remove_effect(me, target, amount);

        else call_out("check_fight", 1, me, target, victim, amount);
}

int remove_effect(object me, object target, int amount)
{
        me->add_temp("apply/attack", -amount);
        me->add_temp("apply/dodge", -amount);
        target->add_temp("apply/attack", -amount);
        target->add_temp("apply/dodge", -amount);
        me->delete_temp("diezhang");
        target->delete_temp("diezhang");
        message_vision(GRN"$N��$n�ĵ��Ʋ��ٷ��ӹ�Ч����Χ����Ҳ������һ������\n"NOR, me, target);
        return 0;
}


