#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "̶��С·");
  set ("long", @LONG

С·��Ϊ��������߶��Ĺ�ϵ���ѱ��ݻƵ���Ҷ�����ˡ�·�ߵ�
�Ĳݼ����˸ߣ���紵��������һƬƬ�Ŀ�Ҷ���ݴ���Ҳ������
�죬�������޷����ĺ�����
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xiaolu1",
  "east" : __DIR__"luhua1",
]));

  setup();
}

