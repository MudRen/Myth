// by snowcat oct 15 1997

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("����", ({"xi hu", "xihu", "hu"}));
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ��ϸ��������\n"),
    set("value", 1000);
    set("max_liquid", 10);
    set("liquid", ([
	"type": "water",
	"name": "��ˮ",
	"remaining": 10,
	"drunk_supply": 10,
    ]));
  }
  setup();
}

int is_container()
{
  return 1;
}
