//Cracked by Roath

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
set_name(BLK"��֥����Բ"NOR, ({"blackty", "tangyuan"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��ʮ�����˵���Բ,�㲻����ˮ���˺ó�.\n");
    set("unit", "��");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}
