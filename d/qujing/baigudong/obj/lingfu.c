// created by smile 12/24/1998

inherit ITEM;

void create()
{
  set_name("�������", ({"lingfu", "fu"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ������Щ��ֵ����ֵķ���\n");
  }
  set("is_monitored",1);
  setup();
}
