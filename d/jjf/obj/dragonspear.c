//��ת����ǹ 
//by junhyun@SK 

#include <weapon.h> 
//  inherit F_UNIQUE; 

inherit SPEAR; 
#include <ansi.h> 
void create() 
      { 
              set_name(HIC"��ת����ǹ"NOR, ({"jiuzhuan dragonspear","spear","qiang"})); 
              set_weight(5000); 
      if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
      set("long","һ�˳�ǹ��ǹ�����ת�������ƣ�ǹ����Ƕһ�������ı�ʯ\n"); 
                      set("unit", "��"); 
                      set("value", 12000); 
                      set("wield_msg",HIC "$N���������ŵ��⻷���������������һ�����λεĳ�ǹ�������У�\n"NOR); 
                      set("unwield_msg",HIC "$N���еĳ�ǹ����һ��������ʧ�ˡ�\n"); 
                      set("no_sell","�����������ɣ��ⶫ���㶼������\n");  
                      set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");  
       
                      set("weapon_prop/courage", 20); 
                      } 
              init_spear(120); 
              setup(); 
      } 
      mixed hit_ob(object me, object victim) 
      { 
          int damage_bonus = 0; 
           
          if( (string)me->query("family/family_name") == "������" 
                      && me->query_skill("bawang-qiang",1) > 1) 
          damage_bonus = me->query_skill("bawang-qiang",1); 
          damage_bonus = (damage_bonus+random(damage_bonus))/2; 
       
          victim->receive_wound("kee",damage_bonus); 
          return HIC"��ת����ǹ������һ��������\n" NOR; 
       
      }

