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
  "/d/sea/npc/soldier1" : 2,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"longtai1",
  "south" : __DIR__"tandi2",
]));
//      
        set("water", 1);
//  
  setup();
}

