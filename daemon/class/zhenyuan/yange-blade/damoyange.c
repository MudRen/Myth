//wuyou@sanjie
//damoyange.c you can add it to the directory /daemon/skill/yange-blade/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
//void damoyange_ok(object);
int perform(object me, object target)
{
        object weapon;
        string msg;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���Į��衹��\n");

        if(!me->is_fighting())
                return notify_fail("����Į��衹ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("yange-blade", 1) < 100)
                return notify_fail("�����赶�����𻹲�����ʹ����һ�л������ѣ�\n");
              
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("��Į�����������Ԫ�񹦲���ʹ�á�\n");
/*
        if (me->query_temp("damoyange_busy"))
                return notify_fail("������ʹ�Ͳ����ˣ�\n");
*/                
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_combatd(HIR"\n$N���һ��,ֻ����ɳ��ʯ,��������,����Į��衹һ��һ���ǳ�!!!\n"NOR,me,target,"");

        message_combatd( HIY  "�³����գ�\n" NOR,me,target,"");
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_combatd( HIC  "��Į���\n" NOR,me,target,"");
        me->set_temp("QJB_perform", 1);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        message_combatd( HIG  "�߷�Ʈҡ��\n" NOR,me,target,"");
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_combatd( HIW  "ɽ��������\n" NOR,me,target,"");
        me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));        

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);
        //me->set_temp("no_damoyange",1);
        //call_out("damoyange_ok",2+random(2),me);


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        
        me->start_busy(2+random(1));

        return 1;
}
/*
void damoyange_ok(object me)
{ 
        if (!me) return;
        me->delete_temp("no_damoyange");
}         
*/

