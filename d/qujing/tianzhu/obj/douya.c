
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("��ѿ", ({"dou ya", "douya", "ya"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�Ѹշ����Ķ�ѿ��\n");
    set("unit", "��");
    set("value", 70);
    set("food_remaining", 3);
    set("food_supply", 20);
  }
}

