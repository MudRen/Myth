// created by angell 1/1/2001
// room: /d/qujing/huangfeng/obj/fake-zhu.c

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIC"ҹ����"NOR, ({ "yeming zhu","zhu" }));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ�ſ���ҹ�䷢������ӣ���˵��ֵ���ǣ�\n");
    set("unit", "��");
    set("material", "gold");
    set("value", 60000);
  }
  setup();
}
