// Ӧdxh���� �Ķ������ʺ��˺�

#include <ansi.h>
inherit SSERVER;
#include <combat_msg.h>;

int def;
int perform(object me, object target)
{       
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
        || !me->is_fighting(target) || !living(target) )
                return notify_fail("���׶����졹ֻ����ս����ʹ�á�\n");
        if (!PFM_D->valid_family(me, "��������"))
                return notify_fail("������壬�����ô��У�\n");
        if( (int)me->query_skill("dragonfight", 1) < 100 
        ||  (int)me->query_skill("unarmed", 1) < 100 )
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á��׶����졹��\n");
        if(me->query_skill("force", 1) <100)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�������׶����졹��\n");        
        if (me->query_skill_mapped("unarmed") != "dragonfight")
                return notify_fail("�������޷�ʹ�á��׶����졹���й�����\n");                                                                                 
        if( (int)me->query("max_force") < 1200 )
                return notify_fail("���������Ϊ̫��������ʹ�á��׶����졹��\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n");
        msg = RED "\n ͻȻ$N���һ��:���׶���,��ɫ৵ı��ͨ��,�뷢�Է�,�������³���ɱ��,\n" NOR;
        message_vision(msg, me, target); 
        msg = YEL "\n        ���ˡ���һ����һ����ջ���$n���ؿڣ�\n" NOR;
        //if (random(me->query("combat_exp")) > random((target->query("combat_exp")/2))
        if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)))
        {
                me->start_busy(1);
                target->start_busy(2);
                damage = (int)me->query_skill("dragonfight", 1);
                damage = damage + random(damage/2);
                def=(int)target->query_temp("apply/armor_vs_force");
                damage -=damage*def/3000;
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage/2, me, "pfm");               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                target->set_temp("last_damage_from", me);
                if(me->query_skill("dragonfight", 1) > 119)
                        call_out("perform2", 1, me, target);    
        } 
        else 
        {       
                //me->start_busy(3);
                me->start_busy(2);
                me->add("force", -200);                
                msg += HIY"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
        int damage, p,skill;
        string msg,weapon;
        weapon = me->query_temp("weapon");  
        if(!living(target)) 
                return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
        msg = MAG "\nֻ��$N���۹������Է��裬������շ�������һ����𡸾��졹��\n" NOR;
        message_vision(msg, me, target); 
        msg = CYN "\n       �������Ļӳ��Ÿ���Ȧ���Ӹ����£�ֱ��$n������\n" NOR;
        me->start_busy(1);
        target->start_busy(2);
        damage = (int)me->query_skill("dragonfight", 1);
        damage = damage+(int)me->query_skill("unarmed", 1);
        damage = damage+(int)me->query_skill("dragonforce", 1);
        damage = (damage + random(damage))/2;
                
        def=(int)target->query_temp("apply/armor_vs_force");
        damage -=damage*def/4000;
        target->receive_damage("kee", damage, me, "pfm");
        target->receive_wound("kee", damage/2, me, "pfm");
        me->add("force", -random(damage/10));
        p = (int)target->query("kee")*100/(int)target->query("max_kee");
        msg += damage_msg(damage, "����");
        msg += "( $n"+eff_status_msg(p)+" )\n";
        target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}

