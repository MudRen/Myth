// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("С����", ({"dan gao", "gao"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һС���кõĵĵ��⡣\n");
    set("unit", "��");
    set("value", 90);
    set("food_remaining", 4);
    set("food_supply", 18);
  }
}

