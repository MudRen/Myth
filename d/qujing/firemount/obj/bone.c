// created by snowcat
#include <dbase.h>

inherit ITEM;

void create()
{
  set_name("�Ž���", ({ "palm bone", "bone"}) );
  set_weight(150);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ��ϸʵ�İŽ��ǣ���֪��ʲô�á�\n");
    set("unit", "��");
  }
  setup();
}

