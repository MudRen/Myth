// by snowcat dec 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("���㳴��", ({"chao dou", "chaodou", "dou", "beans"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ������ĳ����ӡ�\n");
    set("eat_msg", "$Nץ��һ��������������һ�ӣ�����������\n");
    set("unit", "��");
    set("value", 110);
    set("food_remaining", 20);
    set("food_supply", 1);
  }
}


