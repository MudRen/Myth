
#include <ansi.h>

inherit ITEM;

void create()
{
set_name(HIW"������"NOR, ({ "tianliu ling" }));
  set_weight(1000);
set("long", "���ǿ��������������ɽ�����ơ�\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

