inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("����", ({"ju zi", "juzi", "zi"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ���ƳȳȵĽ��ӡ��\n");
    set("unit", "��");
    set("value", 100);
    set("food_remaining", 4);
    set("food_supply", 20);
  }
}

