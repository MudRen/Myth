// ���ֱ��� ����Կ�� by Calvin

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"����Կ��"NOR, ({ "yao shi","key" }));
  set_weight(1000);
  set("long", "����һ�������Ƴɵ�Կ��,���Ӻ��Ǳ��¡�\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}
