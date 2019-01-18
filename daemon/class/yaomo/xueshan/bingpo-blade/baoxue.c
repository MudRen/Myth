
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage,extra;
        string msg,str; 
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ѩ��������\n");
        if (!PFM_D->valid_family(me, "��ѩɽ"))
                return notify_fail("��ı��Ǻ����Ǵ�����͵ѧ���ģ�\n");
        if(!me->is_fighting())
                return notify_fail("����ѩ������ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("bingpo-blade", 1) < 100)
                return notify_fail("��ı��Ǻ������𻹲�����ʹ����һ�л������ѣ�\n");

        message_combatd(HIW"\n$N������������һת�����ܶ�ʱ�������ߣ������к������ˣ�$nֻ�������ǵĵֿ���\n"NOR,me,target,"");
        me->set_temp("noauto",1);
        target->start_busy(1);
        damage=random(((int)me->query_skill("blade")))+(int)me->query_skill("blade");

        message_combatd(HIW"\n$N�ٺ�һ����Ц����Ȼ����ѩ��֮�С�$n�󼱣�������Ѱ$N����Ȼ����һ��������\n"NOR,me,target,"");
        message_combatd(HIW"\n�����Ϯ����������\n"NOR,me,target,"");
        
        extra=(int)me->query_skill("bingpo-blade", 1)/2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra); 
                
        message_combatd(HIY"Ʈѩʽ---$N����$n"HIY"˳��ѩ��ʹ��һ�У�\n"NOR,me,weapon,"");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_combatd(HIC"��ѩʽ---$N����$n"HIC"�����˷�׷Ӱ���ã�\n"NOR,me,weapon,"");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_combatd(HIB"��ѩʽ---$N����$n"HIB"�������浶��������\n"NOR,me,weapon,"");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
                
        if(random(me->query("combat_exp"))>random(target->query("combat_exp"))/4)
        {
                message_combatd(HIY"\n����,һֻ��ɫ������ԶԶ������$N��$n�������ˣ�\n"NOR,me,target,"");
                message_combatd(HIY"\nͻȻ�������ó��һ��,��ʱ��������\n"NOR,me,target,"");
                if(random(me->query("force_factor"))>target->query("force_factor")/4)
                {
                        message_combatd(HIR"\n$N��������ʧ,��æ����һ�У�\n"NOR,me,target,"");
                        target->receive_damage("kee",damage*2,me,"pfm"); 
                        target->receive_damage("sen",damage*2,me,"pfm"); 
                        message_combatd(HIR"\n����������ʯ�������,��$n�ҵñ������ˣ�\n"NOR,me,target,"");
                        target->receive_wound("kee",damage,me,"pfm");
                        target->receive_wound("sen",damage,me,"pfm");
                        COMBAT_D->report_status(target);
                        COMBAT_D->report_sen_status(target);
                }  
                else 
                if(random(me->query("force_factor"))>target->query("force_factor")/2)
                {
                        message_combatd(HIR"\n����������ʯ�������,��$n�ҵñ������ˣ�\n"NOR,me,target,"");
                        target->receive_wound("kee",damage,me,"pfm");
                        COMBAT_D->report_status(target);
                }
                else  
                {
                        message_combatd(HIR"\n����������ʯ�������,��$N��$n�ҵñ������ˣ�\n"NOR,me,target,""); 
                        target->receive_wound("kee",damage,me,"pfm");
                        target->receive_wound("sen",damage,me,"pfm");
                        COMBAT_D->report_status(target);
                        me->receive_damage("kee",damage/10);
                        COMBAT_D->report_status(me);
                }        
        }
        me->delete_temp("noauto");
        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else me->kill_ob(target);
                }
        }

/*
        if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
        {
                str=target->name()+HIM"��"+me->name()+"��ѩɽ�ش�"NOR+HIW"����ѩ������"+HIM"ɱ���ˣ���˵"+target->name()+"��ʬ�屻��ӡ��һ���޴��"NOR+HIW"����"+HIM"���棡";
                message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());
        }
*/        
        me->start_busy(2);
        
        return 1;
}


