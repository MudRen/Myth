// Room: /changan/southseashore.c
//cglaem...12/12/96.
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����û�����ԵĴ��ͨ���ڵء�����һ����һƬ����󺣡���
ֻ�����ź������ߣ�ϣ�����ҳ�һ����·����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/sea/npc/long1.c" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"seashore1",
  "east" : __DIR__"eastseashore",
]));

  setup();
}
