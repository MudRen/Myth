//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"������"NOR);
        set("long", @LONG

�����������ϰ�书��Ҳ����ڤ˼����


LONG
        );

//  set("objects", ([ /* sizeof() == 4 */
//  "d/obj/armor/gujia.c" : 1,
//  "d/obj/cloth/baipao.c" : 1,
//]));

        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"zhongting.c",
  "east" : __DIR__"qianting.c",
//  "south" : "/d/dntg/sky/lingxiao",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

