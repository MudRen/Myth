// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("����", ({"gong guo", "gong", "guo"}));
  set_weight(2400);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һС��������������Ĺ�����\n");
    set("unit", "С������");
    set("value", 340);
    set("food_remaining", 10);
    set("food_supply", 20);
  }
}
