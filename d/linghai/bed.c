//by dewbaby
#include <ansi.h>
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", HIY"��ľ�����"NOR);
        set("long", @LONG

һ�Ÿɾ��������ľ��齡�����ȥ��Ϊ���ʣ�
���ḧ����ȥ����ֻ����˯�����ࡣ
LONG
        );
        
        set("exits", ([
                "out": "/u/dewbaby/wangxian/jade2",
            ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("sleep_room",1);
        set("if_bed",1);
                                              
        setup();
}
void init() {
  add_action("do_sleep","sleep");
  ::init();
}
int do_sleep() {
  if (this_player()->query("gender")!="Ů��")
  write("��ͻȻ�����Լ�һ�������ˣ�ʵ�ڲ������Դ���˵ء�\n");
  this_player()->start_busy(random(3));
  this_player()->add("sen",-150);
  return 1;
}

