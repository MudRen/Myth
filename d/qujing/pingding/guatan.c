// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("��̺", ({"gua tan", "guatan", "rug"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ����̺��\n");
    set("material", "cloth");
    set("unit", "��");
    set("value", 700);
  }
  setup();
}

