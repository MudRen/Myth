
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("���Ȳ�", ({"hong xiancai", "xiancai", "cai"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�Ѽ�Ϊ���ʵĺ��Ȳˡ�\n");
    set("unit", "��");
    set("value", 80);
    set("food_remaining", 3);
    set("food_supply", 30);
  }
}

