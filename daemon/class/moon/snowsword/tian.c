#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        string str;
        int snowsword,moonforce,moondance,ini_damage_apply,times,damage;
        string desc_msg="";
        int sword_level;
        
        snowsword = (int)me->query_skill("snowsword", 1);
        moonforce = (int)me->query_skill("moonforce", 1);
        moondance = (int)me->query_skill("moondance", 1);
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�������ѩ����\n");

        if(!me->is_fighting())
                return notify_fail("�������ѩ��ֻ����ս����ʹ�ã�\n");
                
        sword_level=(int)(snowsword/50);
        if( snowsword < 50)
                return notify_fail("��ķ��ѩ�轣�����𻹲�����ʹ����һ�л������ѣ�\n");

        if (!PFM_D->valid_family(me, "�¹�"))
                return notify_fail("[�����ѩ]���¹�����֮�ܣ�\n");
        
        if( moonforce < 50)
                return notify_fail("���Բ���ķ���Ϊ������ʹ����һ�л������ѣ�\n");
        
        if( moondance < 50)
                return notify_fail("������������輶�𻹲�����ʹ����һ�л������ѣ�\n");
                
        if( me->query("force_factor") > 0)
                return notify_fail("�������ѩ���������в������������������ܽ������飿\n");
        
        if( time()-(int)me->query_temp("wuxue_end") < 3 )
                return notify_fail("�����ö�Ͳ����ˣ�\n");
                
        if ( sword_level <= 1 ) desc_msg = "" ; 
        else desc_msg = chinese_number(sword_level);
        if ( sword_level > 9 ) desc_msg = "��";
        ini_damage_apply = me->query_temp("apply/damage");
        
        message_vision(HIW"\n$N��߳һ�����ż�һ�㣬���弱���������ڰ����һ��������
ͬʱ�����ᶶ�������������������ѩ����$n��\n"NOR,me,target);
        target->start_busy(2);
        damage=1;
        //ǰ����
        message_vision(HIC"\n$Nͬʱʹ�����ѩ�轣��ǰ���У��ڰ����ѹ��$n��\n"NOR,me,target);
        
        me->set_temp("WX_perform", 5);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        if (damage < 1) me->add_temp("apply/damage",50);
        me->set_temp("WX_perform", 0);  
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
        if (damage < 1) me->add_temp("apply/damage",50);
        else me->set_temp("apply/damage",ini_damage_apply);
        me->set_temp("WX_perform", 6);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //������
        if( snowsword > 99 && moonforce > 99 && moondance > 99 )
        {
                message_vision(HIC"\n$N����бб����Ʈ����Ҳ����ͷ�����־ʹ̳������С�\n"NOR,me);
                
                if (damage < 1) me->add_temp("apply/damage",60);
                else  me->set_temp("apply/damage",ini_damage_apply);
                me->set_temp("WX_perform", 7);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             
                if (damage < 1) me->add_temp("apply/damage",60);
                else  me->set_temp("apply/damage",ini_damage_apply);
                me->set_temp("WX_perform", 8);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
      
        //�������
        if( snowsword > 149 && moonforce > 149 && moondance > 149 )
        {
                message_vision(HIC"\n$Nббһ�ٸ�������������ǧ��֧����������һ�ɺ�������$n��\n"NOR,me,target);
                    
                if (damage < 1) me->add_temp("apply/damage",100);
                else  me->set_temp("apply/damage",ini_damage_apply);
                me->set_temp("WX_perform", 9);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                if (damage < 1) me->add_temp("apply/damage",150);
                else  me->set_temp("apply/damage",ini_damage_apply);
                me->set_temp("WX_perform", 10);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
            
/*            
                if (target->query("eff_kee")<0 || !living(target))  
                {
                        str=target->name()+"��"+me->name()+"���¹����С������ѩ��ɱ���ˡ���˵ʬ������"+desc_msg+"ʮ�����ɼ��ǵ��˺ۣ�";
                        message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());
        
                }
*/                      
        }
                        
        me->delete_temp("WX_perform");
        me->set_temp("apply/damage",ini_damage_apply);
        

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->set_temp("wuxue_end",time());
        return 1;
}


