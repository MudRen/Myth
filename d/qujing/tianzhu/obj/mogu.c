
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("ҰĢ��", ({"mo gu", "gu"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�Ѹմ�ɽ�ϲ�����Ģ����\n");
    set("unit", "��");
    set("value", 75);
    set("food_remaining", 3);
    set("food_supply", 35);
  }
}

