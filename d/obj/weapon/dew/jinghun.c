    //ʮ�澪��
    //by dewbaby@sk


#include <weapon.h>
//  inherit F_UNIQUE;

#include <ansi.h>
inherit BLADE;

void create()
{
    set_name(RED"ʮ�澪��"NOR,({"ghost blade","ghost","blade"}));
    set_weight(20000);
if( clonep() )
       set_default_object(__FILE__);
else {
    set("long",RED"��һ�����˱�����˫�־Ͳ�ס�ز�����������˵��������ӵ���߻�þ��˵�����!\n"NOR);
    set("unit","��");
    set("value",12000);
    set("wield_msg",RED"$N���쳤Ц���·𵽴���"HIW"��ϲ�գ��������Ѫ�ŵ�"RED"�ľ���!\n"NOR);
    set("unwield_msg",HIB"$NͻȻ��������������������������ϲ֮���ֽ����糱ˮ����...\n"NOR);
    set("no_sell",1);
    set("no_drop",1);

 }
   init_blade(130);
   setup();

}
/*
      mixed hit_ob(object me, object victim) 
{
          int damage_bonus = 0; 

         if( (string)me->query("family/family_name") == "�ݿ�ɽ�޵׶�" 
                    && me->query_skill("kugu-blade",1) > 1) 
          damage_bonus = me->query_skill("kugu-blade",1); 
         damage_bonus = (damage_bonus+random(damage_bonus))/2; 

         victim->receive_wound("kee",damage_bonus); 
         return HIW"ʮ�澪������������!\n" NOR; 

}
*/
