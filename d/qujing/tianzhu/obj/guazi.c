// by snowcat dec 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�����", ({"gua zi", "guazi", "zi", "seed"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ������ĳ����ӡ�\n");
    set("eat_msg", "$Nץ��һ�Ź���������һ�ӣ�ž��һ�����졣\n");
    set("unit", "��");
    set("value", 120);
    set("food_remaining", 25);
    set("food_supply", 1);
  }
}


