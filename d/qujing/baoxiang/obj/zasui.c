// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("��������", ({"za sui", "zasui"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ���Ⱥ������������顣\n");
    set("unit", "��");
    set("value", 100);
    set("food_remaining", 4);
    set("food_supply", 50);
  }
}
