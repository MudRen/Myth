    //xueqin.c
    //by dewbaby

#include <weapon.h>
#include <ansi.h>
       inherit SWORD; 

       void create() 
       { 
          set_name(HIW"ѩ����Ц"NOR,({"xue qin","xueqin"})); 
           set_weight(4000); 
              if( clonep() ) 
                       set_default_object(__FILE__); 
              else { 
                      set("unit","��"); 
                      set("value",40000); 
                      set("no_drop","1");
                      set("no_sell","1"); 
                      set("material","silver"); 
                      set("long",HIW"��˵���Ǵ�ѩɽ�����������ͨ����ѩ���ף�ɢ���������â��"NOR); 
                     set("wield_msg",HIW"$N����һЦ��$n"HIW"�Ѿ���$N�������У����ܶ�ʱ��ѩ�׷ɡ�\n"NOR); 
                      set("unwield_msg",HIW"$N˫��΢�գ�գ�ۼ��ѽ�$n"HIW"������䡣\n"NOR); 
                      set("no_drop","���ǲ�Ҫ���ɣ�С�Ĵ�ѩɽ��Ҫ�����С����\n"); 

                set("weapon_prop/courage", 20); 
                    } 
          init_sword(130); 
           setup(); 
      } 
/*
    mixed hit_ob(object me, object victim)  
    {
       int damage_bonus = 0;  

       if( (string)me->query("family/family_name") == "��ѩɽ"  
                           && me->query_skill("bainiao-jian",1) > 1)  
       damage_bonus = me->query_skill("bainiao-jian",1);  
       damage_bonus = (damage_bonus+random(damage_bonus))/2;  

       victim->receive_wound("kee",damage_bonus);  
       return HIW"ѩ����Ц��ʱɢ��������ѩ֮��! \n" NOR;  
    }
*/
