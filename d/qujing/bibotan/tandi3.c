#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "̶��С��");
  set ("long", @LONG

�����Ǳ̲�̶��ϸɳ�̾͵�һ��С��������ˮ���ܲ�������ˮ��
����Ʈ�ڡ�̶ˮ�ɱ���ɫ��ˮ�¹��߲��Ǻܺã���·�ѱ硣
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/dadu" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tandi2",
  "up" : __DIR__"gudu",
]));
//      
        set("water", 1);
//  
  setup();
}

