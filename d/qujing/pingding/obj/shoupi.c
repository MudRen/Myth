// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("��Ƥ", ({"shou pi", "pi"}));
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ�����õĻ���Ƥ��\n");
    set("material", "cloth");
    set("unit", "��");
    set("value", 600);
  }
  setup();
}

