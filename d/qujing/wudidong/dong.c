#include <room.h>
inherit ROOM;

int do_dive(string arg);
void reset();

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ����ͺͺ�ģ�һ�û���Ҳ�ޣ�ֻ��һ��ƽ̹�ľ�ʯ���߽�һ������
ʯ������һ���׿ڴ�С�Ķ�(dong)���ѱ�ĥ�ù⻬�ޱȡ�
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "dong" : "
������޵׶��ˣ���չ�ȥһ������ֱ��������ס�
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"shanlu4",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
  add_action("do_dive", "dive");
  add_action("do_dive", "tiao");
}
int do_dive(string arg)
{
  object me;
  me=this_player();
  if ( !arg || ((arg !="dong") ))
    return notify_fail("��Ҫ���Ķ����� \n");
  message_vision("$Nһ�������붴�У����²�������������������ǧ�㡣\n", me);
  me->move(__DIR__"dong1");
  return 1;
}
