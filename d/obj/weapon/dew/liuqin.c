//���ײ���
//by dewbaby@sk

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SPEAR;
#include <ansi.h>
void create()
{
       set_name(HIB"���ײ���"NOR, ({"liuqin qiang","liuqin","qiang"}));
       set_weight(20000);
if( clonep() )
              set_default_object(__FILE__); 
        else { 
      set("long",HIB"�׷���������Я�������꣬��������Ҳ��ð�������һ����ʵ��ͽ�ܡ���ϧ...\n"NOR);
              set("unit", "��"); 
                set("value", 12000);
            set("wield_msg",HIB "$N����һЦ�������Ȼ�ؽ�$n"HIB"�������С�\n"NOR); 
              set("unwield_msg",HIB "գ�ۼ䣬$n"HIB"�Ѿ���$N��������Ȼ��ʧ��!\n"NOR); 
           set("no_sell","�����������ɣ��ⶫ���㶼������\n");  
              set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");  

              set("weapon_prop/courage", 20); 
}
            init_spear(130); 
              setup(); 
}
/*
mixed hit_ob(object me, object victim) 
{
    int damage_bonus = 0; 

       if( (string)me->query("family/family_name") == "������" 
                     && me->query_skill("bawang-qiang",1) > 1) 
    damage_bonus = me->query_skill("bawang-qiang",1); 
     damage_bonus = (damage_bonus+random(damage_bonus))/2; 

    victim->receive_wound("kee",damage_bonus);
     return HIB"���ײ��϶�Ȼһ��ɢ������������֮��!\n" NOR; 

}
*/
