//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"������"NOR);
        set("long", @LONG

�������ߺܶ�������������Ҫ���ðɡ�


LONG
        );

  set("objects", ([ /* sizeof() == 4 */
  "d/obj/weapon/sword/qingfeng.c" : 1,
  "d/obj/weapon/blade/fengdao" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhongting.c",
//  "east" : __DIR__"xuanyuan3.c",
//  "south" : "/d/dntg/sky/lingxiao",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

