#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

ʯ��������ƽ̹����ɨ��Ҳʮ�ָɾ���û��ʲô�����������
���ڴ��߶����±���һʯ���������ĸ�ʯ�ʡ�������һС�ݣ���
ǰʯ���Ͽ��С�ľ���֡����֡�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/hunter" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"ping",
  "southwest": __DIR__"huilin",
  "southeast": __DIR__"bolin",
  "south" : __DIR__"xinglin",
]));

  setup();
}


