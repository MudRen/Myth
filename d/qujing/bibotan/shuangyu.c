#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "˪����");
  set ("long", @LONG

����װ�ε��ţ��Ҿ�ȫ�������ɣ��������൱�����¡����ܰ�
�Ų��ٹ���������������ǽ�ϵ�һ���ֻ������Ϊ���ף����顰
˪�������������֣��������㣬���ǳ���Ů��֮�֡�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/gongzhu" : 1,
  __DIR__"npc/fuma" : 1,
]));
//  set("outdoors", 1);
  

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"yuetai2",
]));
//      
        set("water", 1);
//  
  setup();
}

