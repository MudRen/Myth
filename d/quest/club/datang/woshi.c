inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","����--����");
  set ("long", @LONG
  
����ҲҪ˯�������ο���Ҳ�������ɣ�����������͵��һ����Ϣ��Ϣ��

����һ���Ƴ�........

Ϊ�

LONG);

  set("exits",([ "out" : __DIR__"juyitang", ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_time", 1);
  set("sleep_room",1);
  set("if_bed",1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
