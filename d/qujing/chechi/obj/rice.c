// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("���׷�", ({"caomi fan", "rice", "fan"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ����øɸɵĲ��׷���\n");
    set("unit", "��");
    set("value", 40);
    set("food_remaining", 3);
    set("food_supply", 20);
  }
}
