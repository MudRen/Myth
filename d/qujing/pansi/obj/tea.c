// by snowcat 11/20/1997

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("��յ", ({"cha zhan", "cha", "zhan", "tea"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��С������Ĳ�յ��\n");
    set("unit", "��");
    set("value", 80);
    set("max_liquid", 5);
  }

  set("liquid", ([
    "type": "tea",
    "name": "���",
    "remaining": 5,
    "drunk_supply": 6,
  ]));
}
