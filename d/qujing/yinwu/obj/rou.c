// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "ɽ��",
  "����",
  "����",
  "�ں�",
  "����",
  "Ұ��",
  "Ұ¹",
  "Ұ¿",
  "ɽ��",
  "����",
  "ɽ��",
  "��ѻ",
  "����",
});

string *pieces = ({
  "���",
  "���",
  "����",
  "���",
  "���",
});

void create()
{
  string name = names[random(sizeof(names))]
                + pieces[random(sizeof(pieces))];
  set_name(name, ({"rou", "meat"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ���ɹ�ɵ����⡣\n");
    set("unit", "���");
    set("food_remaining", 6);
    set("food_supply", 35);
     set("value",150); 
  }
}
