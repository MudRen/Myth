// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("������", ({"huasheng mi", "huashengmi", "huasheng", "mi"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�����λ����ס�\n");
    set("eat_msg", "$N����һ�Ż�����������һ�ӣ��������������\n");
    set("unit", "��");
    set("value", 170);
    set("food_remaining", 15);
    set("food_supply", 2);
  }
}

