#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���к�����ģ����ϵ����͵Ʋ�֪�����˶������ˡ���ϡ������
Χ������ܣ�����Ҳ�����˻ҳ������а����������ҳ���ľ����
����ľ�����ҵĵ���һ�ߡ�
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west": __DIR__"inner2",
]));

  setup();
}

