#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����и�ɫ�ӻ�ŭ�ţ������˱ǣ�����Ҫ�������ˡ����۱���
��ڴ�Ļ��䣬��ɫ�ʶ�䣬��֮��Ů��֮Ц������ľ�Գ���ɫ
��ī������һ�����⡣
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/xing" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north": __DIR__"shiya",
  "east": __DIR__"bolin",
  "west": __DIR__"huilin",
  "southeast": __DIR__"zhulin",
  "southwest" : __DIR__"songlin",
]));

  setup();
}


