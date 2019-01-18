//by koker@sjsh
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�����ѩ�꡹��\n");
        
        if (!PFM_D->valid_family(me, "��ѩɽ"))
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á�����ѩ�꡹?\n");

        if(!me->is_fighting())
                return notify_fail("������ѩ�꡹ֻ����ս����ʹ�ã�\n");

        weapon = me->query_temp("weapon");
        
        if( (string)weapon->query("skill_type") != "blade" )
                   return notify_fail("�������޵�������ʹ�����������ı���ѩ�꣡\n");

        if((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("aohan-liujue", 1) < 200)
                return notify_fail("��������������𻹲�����ʹ����һ�л�ɥ���ģ�\n");

        if (me->query_temp("ah_pfm_busy")) 
                return notify_fail("�����õ�̫��̫�ľͲ����ˡ�\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIC"\n$NͻȻ�͵�����������ɲ�Ǽ亮��̹ǣ�$n���������У�\n"NOR,me,target);

        me->set_temp("AOHAN_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("AOHAN_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("AOHAN_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("AOHAN_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("AOHAN_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("AOHAN_perform", 4);
        target->start_busy(2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 200);
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else me->kill_ob(target);
                }
        }

        me->set_temp("ah_pfm_busy",1); 
        me->set_temp("no_move",1); 
        call_out("remove_effect",2+random(3),me); 
        call_out("remove_no_move",1,me); 
        return 1;
}

void remove_effect(object me) 
{ 
        if (me)  me->delete_temp("ah_pfm_busy"); 
} 
void remove_no_move(object me) 
{ 
        if (me) me->delete_temp("no_move"); 
} 

