    //��������
    //by dewbaby@sk


#include <weapon.h>
#include <ansi.h>
//  inherit UNIQUE;

inherit STICK;
void create()
{
       set_name(WHT"��������"NOR,({"xiaohan stick","xiaohan","stick","bang"}));
       set_weight(20000);
    if( clonep() )
          set_default_object(__FILE__);
       else {
    set("long",WHT"һ�������׵������һ����֪�൱��Ѱ�����������������������ޣ���Ө͸����\n"NOR);
       set("unit","��");
       set("value",12000);
       set("wield_msg",WHT"$Nһ��ת������һ�ӣ�ֻ��$n"WHT"�ѱ�$N�������С�\n"NOR);
       set("unwield_msg",WHT"$NĬ���ľ�������������Ϊһ�Ƴ�����������ʧ�ˡ�\n"NOR);
    set("do_put",1);

      set("weapon_prop/courage", 20); 
     }
       init_stick(130);
       setup();
}
/*
    mixed hit_ob(object me, object victim) 
{

         int damage_bonus = 0; 

          if( (string)me->query("family/family_name") == "����ɽ���Ƕ�" 
           && me->query_skill("qianjun-bang",1) > 1) 
      damage_bonus = me->query_skill("qianjun-bang",1); 
       damage_bonus = (damage_bonus+random(damage_bonus))/2; 

    victim->receive_wound("kee",damage_bonus); 
    return HIW"����������ɢ�����̹Ǻ���! \n" NOR; 

}
*/
