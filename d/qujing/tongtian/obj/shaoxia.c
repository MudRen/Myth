// by snowcat dec 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("����Ϻ", ({"shao longxia", "shaolongxia", "longxia", "lobster"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻ�յ�ͨ��Ĵ���Ϻ��\n");
    set("unit", "ֻ");
    set("value", 750);
    set("food_remaining", 8);
    set("food_supply", 45);
  }
}
