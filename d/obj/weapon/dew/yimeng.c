    //һ�θ���
    //by dewbaby@sk


#include <weapon.h>
//  inherit UNIQUE;

#include <ansi.h>
inherit SPEAR;

void create()
{
       set_name(HIW"һ�θ���"NOR,({"fusheng spear","fusheng","spear"}));
       set_weight(20000);
     if( clonep() )
     set_default_object(__FILE__);
    else{
       set("unit","��");
       set("value",12000);
       set("material","silver");
       set("long",HIW"���ǻƷɻ���������ǹ���Ѹ��������ꡣ\n"NOR);
       set("wield_msg",HIW"һ��������$n"HIW"�ѱ�$N������������!\n"NOR);
        set("unwield_msg",HIW"��֪��ʲôʱ��$n"HIW"����Ȼ��ʧ�ˡ�$N��Ц��Ц�ؿ������ܡ�\n"NOR);
       set("no_sell","������������? �ⶫ����Ҳ����? \n");
       set("no_drop","ȥ�����Ѷ���, ���ӻ���Ⱦ����! \n");
  }
    init_spear(130);
    setup();
  }
/*
    mixed hit_ob(object me, object victim)    
  {
    int damage_bonus = 0;    

     if( (string)me->query("family/family_name") == "���ƶ�"    
             && me->query_skill("wuyue-spear",1) > 1) 
       damage_bonus = me->query_skill("wuyue-spear",1);    
     damage_bonus = (damage_bonus+random(damage_bonus))/2;    

       victim->receive_wound("kee",damage_bonus);    
       return HIG"һ�θ����ڿ���з������֮��! \n" NOR;    

}
*/
