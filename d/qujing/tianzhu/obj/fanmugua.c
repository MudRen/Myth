inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("��ľ��", ({"fanmu gua", "fanmugua", "papaya"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��˶��ķ�ľ�ϡ��\n");
    set("unit", "��");
    set("value", 110);
    set("food_remaining", 4);
    set("food_supply", 30);
  }
}

