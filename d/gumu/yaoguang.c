//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"ҡ��"NOR);
        set("long", @LONG

���������βһ����������С���䣬����ʲô��û��
ǰ��һƬ���룬ʲôҲ�������������һƬ�ž�......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kaiyang.c",
  "out" : __DIR__"passroom.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

