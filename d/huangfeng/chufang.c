// created by angell 1/1/2001
// room: /d/qujing/huangfeng/chufang.c

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�峤�ҵĳ��������������������˱ǡ�һ���곤�ĸ�����æ
��׼����������������ƺ�����һ����

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"minju2",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/woman" : 1,
  __DIR__"obj/shanyao" : 1,
  __DIR__"obj/yutou" : 1,
]));
  setup();
}
