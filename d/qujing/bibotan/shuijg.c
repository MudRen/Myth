#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�̲�̶ˮ����");
  set ("long", @LONG

������Ǳ̲�̶�����ľ���ˮ����������֮�ϸ����������飬��
�����յ���ͬ���硣���ڵİ���Ҳ�Ǿ����������Ŀ֮���޲���
�˼����У�������Ѱ�������챦��һȺ���¹����������裬��
����������ǰ���к����ò����֡�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/longwang" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"yujie",
  "north" : __DIR__"longtai2",
  "east" : __DIR__"hanyu",
  "west" : __DIR__"lengxiang",
]));
//      
        set("water", 1);
//  
  setup();
}

