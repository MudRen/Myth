// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "��ը����",
  "������",
  "����",
  "���㻨��",
  "�滨��",
  "±����",
  "��ˮ����",
  "ϸ�ǻ���",
});

void create()
{
  set_name("��ʽ����", 
          ({"hua sheng", "huasheng", "sheng", "peanut"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��������\n");
    set("unit", "��");
    set("value", 90);
    set("food_remaining", 10);
    set("food_supply", 9);
  }
//  set("no_sell",1);
}

void init()
{
  if (query("name")=="��ʽ����")
    set_name(names[random(sizeof(names))], 
            ({"hua sheng", "huasheng", "sheng", "peanut"}));
  ::init();
}
