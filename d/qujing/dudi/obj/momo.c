// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "��������",
  "��������",
  "��������",
  "��ɳ����",
  "��ɳ����",
  "��������",
  "��������",
  "�л�����",
  "��������",
});

void create()
{
  string name = names[random(sizeof(names))];
  set_name(name, ({"mo mo", "mo"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻ����������������ɡ�\n");
    set("unit", "ֻ");
    set("food_remaining", 6);
     set("value", 1000); 
    set("food_supply", 35);
  }
}

