// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("ϡ��", ({"xi fan", "fan", "rice"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ����ϡ����\n");
    set("unit", "��");
    set("value", 30);
    set("food_remaining", 4);
    set("food_supply", 15);
  }
}
