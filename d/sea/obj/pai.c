inherit ITEM;

void create()
{
  set_name("ˮ������", ({ "yao pai" }));
  set_weight(1000);
  set("long", "����һ��ˮ���Ƴɵ����ƣ��Ͽ��С������������ĸ��֡�
��ֵ��Ǳ߷�����Щͻ�ۣ�����Կ��һ�㡣\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

