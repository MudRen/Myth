//Cracked by Roath
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "�����",
  "�������",
  "��ͷ��",
  "��������",
  "���ظ���",
  "��������",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"rou", "meat"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��鿾������⡣\n");
    set("unit", "���");
    set("food_remaining", 6);
    set("food_supply", 35);
    set("value",50);
  }
}
