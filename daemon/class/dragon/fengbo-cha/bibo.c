#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "fork")
                return notify_fail(RED"��ʲô��Ц��ûװ������ôʹ���̲���ӿ����\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���̲���ӿ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query_skill("fengbo-cha", 1) < 150 )
                return notify_fail(WHT"��粨ʮ���治����죬ʹ�������̲���ӿ����\n"NOR);
        if(me->query_skill_mapped("force")!="dragonforce")
                return notify_fail("�������ķ������ã����±��������ˣ�\n");    
        if ((int)me->query_skill("dragonstep", 1) < 150 )
                return notify_fail(RED"����������򲻹������̲���ӿ��������ʽ��\n"NOR);
        if (!PFM_D->valid_family(me, "��������"))
                return notify_fail("������壬�����ô��У�\n");
        if ((int)me->query_skill("dragonforce", 1) < 150 )
                return notify_fail(WHT"�������ķ����������ʹ���̲���ӿ�����߻���ħ��\n"NOR);

        if ((int)me->query("max_force")<1800)
                return notify_fail(RED"���������Ϊ���㣬�޷����㡸�̲���ӿ����������\n"NOR);
        if(me->query_temp("bibo_busy"))
                return notify_fail("�㲻�º�ˮ̫������ƽ�񰡣�\n");    
        if ((int)me->query("force")<400)        
                return notify_fail(HIC"����������������û�ܽ����̲���ӿ��ʹ�꣡\n"NOR);
    
        msg = HIC "$N������֮����̤�̲�������$nֻ����$N����������Ӱ,\n"NOR;
        msg += HIC"�����Ӱϯ�������$n����һ�ܣ���$N�����·��$nֻ��סһ�棡\n"NOR;
        message_vision(msg, me, target);

        me->clean_up_enemy();
        target = me->select_opponent();

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        me->add("force", -100);
        //me->set_temp("bibo_busy",6);
        me->start_busy(1+random(1));
        //target->kill_ob(me);
        //call_out("remove_effect",3+random(5),me);
    
        return 1;
}
/*
void remove_effect(object me) 
{
        if (!me) return;
        me->delete_temp("bibo_busy");
}
*/


