// bagua.c  ���ذ���

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIC"���ذ���"NOR, ({ "fuxi bagua" }));
  set_weight(1000);
  set("long", "����һ��ˮ�����ɵİ���ͼ����֪����ʲô�á�\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

