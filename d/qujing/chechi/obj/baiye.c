// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("ţ��Ҷ", ({"niu baiye", "niubaiye", "baiye"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�����������͵�ţ��Ҷ˿��\n");
    set("unit", "����");
    set("value", 240);
    set("food_remaining", 5);
    set("food_supply", 30);
  }
}
