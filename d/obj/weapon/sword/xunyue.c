       //xunyue.c 
       //by dewbaby

#include <ansi.h> 
#include <weapon.h> 
inherit SWORD; 

       void create() 
       { 
          set_name(HIC"�˷�Ѱ��"NOR,({"xunyue sword","xunyue"})); 
           set_weight(4000); 
              if( clonep() ) 
                       set_default_object(__FILE__); 
              else { 
                      set("unit","��"); 
                      set("value",40000); 
                      set("material","silver"); 
                      set("long",HIC"��������ĸ�İ��ı�����������ɢ����ҫ�۵Ĺ�â��\n"NOR); 
                 set("wield_msg",HIM"$N��ȻһЦ��$n"HIM"�Ѿ���$N�������С�һƬ�¹�˲���Χ��$N��\n"NOR); 
                      set("unwield_msg",HIC"$N˫��΢�գ�գ�ۼ��ѽ�$n"HIC"������䡣\n"NOR); 
                      set("no_sell","�����������ɣ��ⶫ���㶼������\n");  
                      set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");  
                      set("weapon_prop/courage",20);  
                    } 
          init_sword(130); 
           setup(); 
      } 
        mixed hit_ob(object me, object victim) 
        {
            int damage_bonus = 0; 

            if( (string)me->query("family/family_name") == "�¹�" 
                        && me->query_skill("snowsword",1) > 1) 
            damage_bonus = me->query_skill("snowsword",1); 
            damage_bonus = (damage_bonus+random(damage_bonus))/2; 

            victim->receive_wound("kee",damage_bonus); 
            return HIM"�˷�Ѱ����ɢ����������֮��! \n" NOR; 
            }
