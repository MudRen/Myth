// sanjie tianyilu1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "��һ·");
  set ("long", @LONG
	
·�Գ����ɻ���ݣ������˱ǣ������Ŀ����ӣ�����ɽ֮·
����Ԩ֮�𡣶����������ƣ�һ�ɰ��꾰���ƺ���ϴ���˼�
���գ����˶���
LONG);

  set("exits", ([
  "northup" : __DIR__"tianyilu2",
  "southdown" : __DIR__"sanjiedao",
]));
  set("outdoors", 1);

  setup();
}
