//by dewbaby@sk_sjsh
//��������
#include <ansi.h> 
#include <combat.h>
inherit SSERVER; 
        
        
       int perform(object me, object target) 
       { 
               object weapon, ob; 
               string msg; 
               string str; 
               int damage;
               int myexp,youexp;

              if( !target ) target = offensive_target(me); 
       
              if( !target 
              ||      !target->is_character() 
              ||      target->is_corpse() 
              ||      target==me) 
                      return notify_fail("��Ҫ��˭ʩչ���С���������\n"); 
       
       
              if( !me->is_fighting() ) 
                  return notify_fail("��������ֻ����ս����ʹ�á�\n"); 

              if((string)me->query("family/family_name")!="�躣��")
                       return notify_fail("�㲻���躣�����ˣ�����͵ѧ����?\n");      
       
              if (!objectp(weapon = me->query_temp("weapon")) 
                      || (string)weapon->query("skill_type") != "sword") 
                              return notify_fail("��ʹ�õ��������ԡ�\n"); 
       
              if( environment(me)->query("no_fight") ) 
                      return notify_fail("�����ﲻ�ܹ������ˡ�\n"); 
       
              if( (int)me->query_skill("huanyue-jianfa",1) < 200 ) 
                      return notify_fail("��Ļ��½����ȼ�����������ô��ʹ��������������\n"); 
       
              if (me->query("force") < 890) 
                      return notify_fail("���������̣�����ʹ������������\n"); 
       
              myexp = (int) me->query("combat_exp");
              youexp = (int) target->query("combat_exp");
                      
              msg = HIW "$Nʹ���躣�񹬾���"HIB"��������"WHT+"���б��������ֳ�˿˿"HIB+"����"WHT+"֮��\n\n" NOR; 
              message_vision(msg, me); 
       
              me->clean_up_enemy(); 
              ob = me->select_opponent(); 
    
              message_vision(HIY"$N����Ѹ�����磬ȦȦ�������ϵ�ӿ��$n��\n\n"HIB"$N������ɽ�����Ϫˮ�ǣ���ҡ���������ʡ� 
��\n"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
       
              message_vision(HIY"$Nһ��֮��ڶ����漴����$n"HIY+"��������æ���ҡ�\n\n"HIB"$N��Ȼ��:������Ӧ˯Ϊ�������������ڹ�˭�͡���"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
       
              message_vision(HIY"$N�Ų����������н���ȴ����ͣ�١�$n"HIY+"ֻ�ܰ��Խпࡣ\n\n"HIB"$N�����������������ÿҹԲ�����Ĳ��Ǽ���������"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
 
              message_vision(HIY"$Nת���ƹ�$n��"HIY+"��������һ��������������ꡣ\n\n"HIB"$Nӽ:������ֻ˵������������ƫ���롣��"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
       
              message_vision(HIW"$N�����������֣���������Ӱ��$n�������Ƶ��޷�������\n"NOR, me, ob); 
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
       
              target->start_busy(3); 
              target->add("force", -200);
              target->add("kee", -200);
              target->add("sen", -200);
       
       
              return 1;   
       
      } 








