//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���");
        set("long", @LONG

����������������������С���䣬����ʲô��û��
ǰ��һƬ���룬ʲôҲ�������������һƬ�ž�......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yongdao3.c",
  "south" : __DIR__"huo.c",
  "west" : __DIR__"yongdao2.c",
  "east" : __DIR__"mu.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

