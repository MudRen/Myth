
//

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name("��", ({ "shell" }));
  set_weight(8000);
  set("long", "����һֻ���ڷ绯�ĳ�ǡ�\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("material", "bone");
  }
  setup();
}

void init ()
{
  object me = this_object();
  if (me->query("is_disappearing"))
    return;
  me->set("is_disappearing",1);
  call_out ("disappear",20,this_object());
}

void disappear (object me)
{
  destruct (me);
}

