//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"����"NOR);
        set("long", @LONG

������������ڶ�����������С���䣬����ʲô��û��
ǰ��һƬ���룬ʲôҲ�������������һƬ�ž�......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yuheng.c",
  "south" : __DIR__"yaoguang.c",
"east" : __DIR__"jin.c",
  "west" : __DIR__"mu.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

