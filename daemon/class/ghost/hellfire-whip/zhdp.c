#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int hellfirewhip,tonsillit,gouhunshu,times,extra,damage;
        string desc_msg="";
        int bellicosity_num,lhb_level;
        
        hellfirewhip = (int)me->query_skill("hellfire-whip", 1);
        tonsillit = (int)me->query_skill("tonsillit", 1);
        gouhunshu = (int)me->query_skill("gouhunshu", 1);
        damage=hellfirewhip;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��׷����ǡ���\n");

        if(!me->is_fighting())
                return notify_fail("��׷����ǡ�ֻ����ս����ʹ�ã�\n");
        
        bellicosity_num = (int)me->query("bellicosity");
        
        if( hellfirewhip < 80)
                return notify_fail("����һ�޼��𻹲������޷�������ǵ����⣡\n");

        if (!PFM_D->valid_family(me, "���޵ظ�"))
                return notify_fail("[׷�����]��׷����ǲ���֮�ܣ�\n");
        
        if( tonsillit < 80)
                return notify_fail("�����������Ϊ�������޷���������\n");
        
        if( gouhunshu < 80)
                return notify_fail("��Ĺ��������𻹲������޷����˻��ǣ�\n");
                
        if (bellicosity_num<(tonsillit+gouhunshu)) 
                return notify_fail("��ɱ���������뵽��ʳ���ǲ��ɵ�ɪɪ����!");
              
        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");
        
        if((int)me->query("kee") < 300 || (int)me->query("sen") <300)
                return notify_fail("���չ˺����Լ��Ļ��ǰɣ�\n");

                
        if( time()-(int)me->query_temp("zhdp_end") < 3 )
                return notify_fail("�����ö�Ͳ����ˣ�\n");
          
        message_vision(HIC"\n$NͻȻ����������������ζ������г����ĸ���������б��Գ�����ԩ�껷�ƣ�
  ����ϰϰ��ʹ�����һ��ʧ���Ѿõľ�ѧ**׷�����**��\n"NOR,me);
        extra=(int)(bellicosity_num/30);
        me->add_temp("apply/attack", hellfirewhip+extra);
        me->add_temp("apply/damage", hellfirewhip+extra);
        if(!target->is_busy())
                target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->add_temp("apply/attack", -(hellfirewhip+extra));
        me->add_temp("apply/damage", -(hellfirewhip+extra));
        if( hellfirewhip > 120 && tonsillit > 120 && gouhunshu > 120 )
        {   
                message_vision(HIR"\n$N��������е��һ𣬲��ɵ���Ѫ��ӿ��ƴ�����һ�ޡ�\n"NOR,me);
 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                message_vision(HIR"\n$N�޷��ƺ��Ѿ����ϣ�ͻȻ��ͷ���һ���һ�$n�������Ҳ�㲻��ȥ�ˡ�\n"NOR,me,target);
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage,me,"pfm");

        }
        if( hellfirewhip > 160 && tonsillit > 160 && gouhunshu > 160 )
        {    
                message_vision(HIR"\n$N�·�����������������������Χ��һ˿��Ц�����һ�����һ����
           �ľ�������һʽ�о��֡�\n"NOR,me);
                me->add_temp("apply/attack",hellfirewhip*2+extra);
                me->add_temp("apply/damage",hellfirewhip*2+extra);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                me->add_temp("apply/attack",-(hellfirewhip*2+extra));
                me->add_temp("apply/damage",-(hellfirewhip*2+extra));
                target->receive_damage("kee",damage,me,"pfm"); 
                target->receive_damage("sen",damage,me,"pfm"); 
                target->receive_wound("sen",damage/2,me,"pfm"); 
                target->receive_wound("kee",damage,me,"pfm"); 
        }
           
        message_vision(HIR"\n$N˫Ŀ�����˸��������� ������ȥ���������־͸�����\n"NOR,me);
        if ((bellicosity_num/3*2)<random(((int)target->query("max_mana")+(int)target->query("max_force") )/3))
        {
                message_vision(HIR"\n�Է���Ԫ��һ��˿����Ϊ��������\n"NOR);
//                me->start_buzy(2);
        }   
        else 
        {   
                message_vision(HIC"\n$N������䣬$n�����ɢ����������!\n"NOR,me,target);

                target->start_busy(3+random(3));

        }
                                
 
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->set_temp("zhdp_end",time());
        return 1;
}

