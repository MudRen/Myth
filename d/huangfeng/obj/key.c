// key.c
// created by angell 1/1/2001

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIY "��Կ��" NOR, ({ "jin yaoshi","key","golden key","yaoshi" }));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ�Ѵ�����ƶ��ɵ�Կ��. \n");
    set("unit", "��");
    set("material", "gold");
    set("no_give", 1);
//    set("name_recognized", "golden key");
  }
  setup();
}

void init ()
{
  call_out ("destruct_me",600,this_object());
}

void destruct_me (object me)
{
  message_vision(HIY "ֻ��һ�������������Կ��ͻȻ������!\n" NOR,me);
  destruct (me);
}

