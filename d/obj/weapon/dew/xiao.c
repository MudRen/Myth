    //xiao.c
    //dewbaby@sk


#include <ansi.h> 
#include <weapon.h> 
inherit F_UNIQUE; 
inherit SWORD; 

void create() 
{
          set_name(HIM"һЦ����"NOR,({"qing sword","sword","qing"})); 
           set_weight(20000); 
              if( clonep() ) 
                       set_default_object(__FILE__); 
              else { 
                      set("unit","��"); 
                      set("value",12000); 
                      set("material","silver"); 
                      set("long",HIM"������ɽ�����İ��ı�����������ɢ����ҫ�۵Ĺ�â��\n"NOR); 
                 set("wield_msg",HIM"$N��ȻһЦ��$n"HIM"�Ѿ���$N�������С�һƬ�¹�˲���Χ��$N��\n"NOR); 
                      set("unwield_msg",HIM"$N˫��΢�գ�գ�ۼ��ѽ�$n"HIM"������䡣\n"NOR); 
                      set("no_sell","�����������ɣ��ⶫ���㶼������\n");  
                      set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");  

                 set("weapon_prop/courage", 20); 
}
          init_sword(130); 
           setup(); 
}
/*
    mixed hit_ob(object me, object victim)  
    {
       int damage_bonus = 0;

       if( (string)me->query("family/family_name") == "��ɽ��"
                            && me->query_skill("yujianshu",1) > 1) 
       damage_bonus = me->query_skill("yujianshu",1);
       damage_bonus = (damage_bonus+random(damage_bonus))/2;

       victim->receive_wound("kee",damage_bonus);
       return HIM"һЦ���鶶Ȼһ�𣬹�â����! \n"NOR;
    }
*/
