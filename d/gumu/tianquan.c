//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"��Ȩ"NOR);
        set("long", @LONG

������������Ŀ���������С���䣬����ʲô��û��
ǰ��һƬ���룬ʲôҲ�������������һƬ�ž�......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yongdao2.c",
  "south" : __DIR__"yuheng.c",
  "east" : __DIR__"shui.c",
  "west" : __DIR__"huo.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

