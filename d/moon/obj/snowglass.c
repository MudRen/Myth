inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("ѩ����", ({ "snowglass", "glass" }) );
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "�������ͨ͸������ɰ���\n");
    set("unit", "��");
    set("value", 120);
    set("max_liquid", 100); 
    set("liquid_supply", 80);
  }

  set("liquid", ([
    "type": "water",
    "name": "���ز�",
    "remaining": 90,
  ]) );
  setup();
}

