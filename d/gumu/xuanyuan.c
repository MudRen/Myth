//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"��ԯħ��"NOR);
        set("long", @LONG
��������ˮ�µ�һƬƽ���Ͻ���Ĺ�����һ��
��������Χ��


LONG
        );



        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xuanyuan1.c",
  "south" : __DIR__"shuidi4.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

