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

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"southseashore",
  "east" : __DIR__"seashore2",
]));
  set("outdoors", 2);

  setup();
}
