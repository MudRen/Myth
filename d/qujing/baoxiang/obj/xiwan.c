// by snowcat oct 15 1997

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("����", ({"xi wan", "xiwan", "wan"}));
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("long", "һֻ������룮\n"),
    set("value", 800);
    set("max_liquid", 5);
    set("liquid", ([
	"type": "water",
	"name": "��ˮ",
	"remaining": 5,
	"drunk_supply": 5,
    ]));
  }
  setup();
}

int is_container()
{
  return 1;
}
