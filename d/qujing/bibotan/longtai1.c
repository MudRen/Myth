#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ɳ̨");
  set ("long", @LONG

��ɳ̨Լ��һ�ɼ�����������ϸɳ�̾ͣ�����̨��ǳ���ƽ����
̨�Ķ������һ��ͭ�ӣ�������ˮ�д�Ѷ���õġ��м���С����
̨���赶Ūǹ���Ȼ�ȭ�š�ǰ���Ϳ���ˮ�����ˡ�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  "/d/sea/npc/soldier2" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"tandi1",
  "north" : __DIR__"yujie",
]));
//      
        set("water", 1);
//  
  setup();
}

