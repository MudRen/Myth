// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("���", ({"mian jin", "mian", "jin"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�̴�ƿ����\n");
    set("unit", "�̴�ƿ");
    set("value", 90);
    set("food_remaining", 4);
    set("food_supply", 30);
  }
}
