//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"��̶�"NOR);
        set("long", @LONG

�����ˮ�²�����ô�䣬������ԼԼ����ǰ����΢΢
�����⣬����ææ�������⴦��ȥ......

LONG
        );

//  set("objects", ([ /* sizeof() == 2 */
//  "d/gumu/npc/daji" : 1,
//]));

        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xuanyuan.c",
  "east" : __DIR__"shuidi3.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

