       //��������
       //by dewbaby@sk


#include <ansi.h> 
#include <weapon.h> 
inherit STAFF;

void create() 
{
          set_name(WHT"��������"NOR,({"long staff","staff","long"})); 
           set_weight(20000); 
              if( clonep() ) 
                       set_default_object(__FILE__); 
              else { 
                      set("unit","��"); 
                      set("value",12000); 
                      set("material","gold"); 
                      set("long",WHT"һ�����Ʊ��ص����ȣ���������ҫ�Ű��ҵĹ�â��\n"NOR); 
                 set("wield_msg",WHT"$N����һ�ӣ�$n"WHT"ɲ�Ǽ������$N���С�\n"NOR); 
                      set("unwield_msg",WHT"$N˫��΢�գ�ת�ۼ�$n"WHT"����ʧ������\n"NOR); 
                      set("no_sell","�����������ɣ��ⶫ���㶼������\n");  
                      set("weapon_prop/courage",30);
                    } 
          init_staff(130); 
           setup(); 
      } 
/*
             mixed hit_ob(object me, object victim)  
     {
                   int damage_bonus = 0;
                   if( (string)me->query("family/family_name") =="�Ϻ�����ɽ"
                              && me->query_skill("lunhui-zhang",1) > 1)  
                   damage_bonus = me->query_skill("lunhui-zhang",1);  
                   damage_bonus = (damage_bonus+random(damage_bonus))/2;  

                   victim->receive_wound("kee",damage_bonus);  
                   return WHT"��������ͻȻ�䷢���������֮��!\n" NOR;
     }
*/
