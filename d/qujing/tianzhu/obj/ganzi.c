inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("����", ({"gan zi", "ganzi", "zi"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ���Ƴȳȵĸ��ӡ��\n");
    set("unit", "��");
    set("value", 100);
    set("food_remaining", 4);
    set("food_supply", 20);
  }
}

