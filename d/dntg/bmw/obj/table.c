//

#include <ansi.h>

inherit ITEM;


void create()
{
  set_name("����", ({ "table"}));
  set_weight(30000);
  set("long", "һ�ų����Ĺ���������ѵĹ����ѱ�Ū�����߰��㣬
ֻ���м�һ���Ĳ�(book)����������á�\n" );


  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("material", "stone");
    set("value", 2000);
    set("no_get", 1);
    set("no_sell", 1);
  }
  setup();
}

