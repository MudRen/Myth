#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�ؾ���");
  set ("long", @LONG

����ԭ���ǰ����²ؾ���ĵط�,������Ȼ��Щ�ƾ�
��������ľ���ȴ��Ȼ��������İڷ���... ...
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
                "north" : "/d/calvin/milin/bailong",
]));

  setup();
}
