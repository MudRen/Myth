
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("�̲�", ({"lu cha", "cha"}));
  set_weight(900);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�������ݵ��̲衣\n");
    set("unit", "����");
    set("value", 30);
    set("max_liquid", 5);
  }

  // because a container can contain different liquid
  // we set it to contain water at the beginning
  set("liquid", ([
    "type": "water",
    "name": "�̲�",
    "remaining": 5,
  ]));
}

