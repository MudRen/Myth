
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ʥȪ��");
  set ("long", @LONG

·�߲�ľ��ϡ����·������һȪ��Ȫ����һ������Χɽ������
���ƣ���Ϊ�����ǰ�Ķ���Ͱ������У������ϰٵ����䡣
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/zhang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : "/d/meishan/fenglin1",
  "east" : __DIR__"fenglin2",
  "southeast" : __DIR__"longwan",
  "northup" : __DIR__"zhaoyun",
]));

  setup();
}


