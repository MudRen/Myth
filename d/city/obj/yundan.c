// jiudai.c  �ƴ�

#include <ansi.h> 
 inherit COMBINED_ITEM; 
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
add_action("do_eat", "eat");
}
void create()
{
set_name(HIG"�����Ƶ�"NOR, ({"yun dan","dan"}));
set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
  set("long", "��ȫ���ָ�����ҩ��\n");
 set("base_unit", "��"); 
 set("unit", "Щ"); 
set("value", 20000);
      set("no_sell", 1);
      set("no_drop", 1);
	}
 set_amount(1); 
    setup(); 
}
int do_eat(string arg)
{
  object me = this_player();
if (arg!="yun dan") return 0;
        if( me->query("combat_exp")> 5000000) return 1;
 me->set("eff_sen", (int)me->query("max_sen"));
me->set("sen", (int)me->query("max_sen"));
me->set("eff_kee", (int)me->query("max_kee"));
me->set("kee", (int)me->query("max_kee"));
me->set("mana", (int)me->query("max_mana"));
me->set("force", (int)me->query("max_force"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
message_vision(""HIR"$N������һ�Ż����Ƶ����ٸл������������"NOR"\n", me);
 add_amount(-1); 
  return 1;
}
