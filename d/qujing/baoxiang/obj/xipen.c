// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("����", ({"xi pen", "xipen", "pen"}));
  set_weight(1100);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("long", "һֻӡ�������裮\n"),
    set("value", 2000);
  }
  setup();
}

int is_container()
{
  return 1;
}
