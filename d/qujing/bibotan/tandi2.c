#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "̶��С��");
  set ("long", @LONG

�����Ǳ̲�̶��ϸɳ�̾͵�һ��С��������ˮ���ܲ�������ˮ��
����Ʈ�ڡ�̶ˮ�ɱ���ɫ��ˮ�¹��߲��Ǻܺã���·�ѱ硣
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tandi1",
  "south" : __DIR__"tandi3",
]));
//      
        set("water", 1);
//  
  setup();
}

