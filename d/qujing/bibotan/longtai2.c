#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ɳ̨");
  set ("long", @LONG

��ɳ̨Լ��һ�ɼ�����������ϸɳ�̾ͣ�����̨��ǳ���ƽ����
̨�Ķ������һ��ͭ�ӣ�������ˮ�д�Ѷ���õġ��м���С����
̨���赶Ūǹ���Ȼ�ȭ�š���������һ���¶��ţ�������Ǳ̲�
̶ˮ���ĺ�Ժ�ˡ�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"obj/rack" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shuijg",
  "north" : __DIR__"yuemen",
  "east" : __DIR__"sleeproom",
]));
//      
        set("water", 1);
//  
  setup();
}

