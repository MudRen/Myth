// created by angell 1/1/2001
// room: /d/qujing/huangfeng/obj/dingfengzhu.c

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
  set_name(HIC "������" NOR, ({ "dingfeng zhu","zhu" }));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ�ŵ���ɫ�����ӣ������ƺ��й�Ӱ����. \n");
    set("unit", "��");
    set("material", "gold");
    set("no_get",1);
    set("no_give","���Ǳ����������ˣ�\n");
    set("no_sell",1);
    set("no_put","������ӷŲ���ȥ��\n");
    set("is_monitored",1);
    set("replace_file","/d/qujing/huangfeng/obj/fake-zhu");
  }
    setup();
}
