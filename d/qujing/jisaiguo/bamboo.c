#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

�����а����˸�������Ʒ���ѵĵ������ǣ������޷��½š�����
С�������һ�Ա���������ϰ��ȥ��֣�����Щ͵��������
�����ﻹ�Ǹ�����������˻�ͦ�ࡣ
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
"/obj/boss/jisaiguo_huoji" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"eastmarket",
]));

  setup();
}

