
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("����", ({"hua cai", "huacai", "cai"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�ż�Ϊ���ʵĻ��ˡ�\n");
    set("unit", "��");
    set("value", 80);
    set("food_remaining", 3);
    set("food_supply", 30);
  }
}

