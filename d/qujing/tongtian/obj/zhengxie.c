// by snowcat dec 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("���з", ({"zheng pangxie", "zhengpangxie", "pangxie", "crab"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻ����ͨ��Ĵ��з��\n");
    set("unit", "ֻ");
    set("value", 650);
    set("food_remaining", 9);
    set("food_supply", 50);
  }
}
