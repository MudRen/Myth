// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("��ľб����", ({"yi zi", "yizi", "seat"}));
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ�ѵ�ľб���Ρ�\n");
    set("material", "wood");
    set("unit", "��");
    set("value", 900);
  }
  setup();
}

