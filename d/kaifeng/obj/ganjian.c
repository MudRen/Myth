// by snowcat

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�۳��μ�", ({"gan jian", "ganjian", "gan", "jian"}));
  set_weight(600);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�ոճ��������Ȳˡ�\n");
    set("unit", "��");
    set("value", 400);
    set("food_remaining", 8);
    set("food_supply", 25);
  }
}

