// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("������", ({"zui niluo", "zuiniluo", "zuiluo", "luo"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�������ݣ��ú�Ҷ���š�\n");
    set("eat_msg", "$N����һ�������ݣ�����һ�����µ��տǡ�\n");
    set("unit", "��");
    set("value", 125);
    set("food_remaining", 15);
    set("food_supply", 2);
  }
}

