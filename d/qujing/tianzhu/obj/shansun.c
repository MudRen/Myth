
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("ɽ��", ({"shan sun", "shansun", "sun"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�Ÿմ�ɽ�ϰ��µ�ɽ��\n");
    set("unit", "��");
    set("value", 75);
    set("food_remaining", 3);
    set("food_supply", 35);
  }
}

