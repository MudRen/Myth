inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("����", ({"you zi", "youzi", "zi"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�Ŵ����ӡ��\n");
    set("unit", "��");
    set("value", 80);
    set("food_remaining", 3);
    set("food_supply", 20);
  }
}

