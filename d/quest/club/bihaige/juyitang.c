inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","������");
  set ("long", @LONG
  
		��	��	��

�����ǡ��̺��󡽵���̳���ã����и�����ţ���������ɾ�����¯
�ٳ��������㣬�������˾���һ��ƽʱ��������ڶ�ϲ���������
��һ�ã��л��ҳ������ʱ������ش����Ҳ��������С�

LONG);

  set("exits",([
  "southdown" : __DIR__"dayuan",
  "west" : __DIR__"liangong",
//  "east" : __DIR__"leitai",
  "enter" : __DIR__"woshi",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_time", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
