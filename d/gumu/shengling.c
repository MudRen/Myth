//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"ʥ���"NOR);
        set("long", @LONG

�������Ů������ʥ�

LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  "d/gumu/npc/nuwa1" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"xuanyuan2.c",
//  "east" : __DIR__"xuanyuan3.c",
  "south" : "/d/dntg/sky/lingxiao",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

