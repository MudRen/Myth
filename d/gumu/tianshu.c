//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
         set("short", "����");
        set("long", @LONG

��������ǣ��ߵ����������ǰͻȻһ������
ǰ������и��ƻ�ͨ���Ĵ��......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beiji.c",
  "south" : __DIR__"jin.c",
  "west" : __DIR__"shui.c",
  "east" : __DIR__"tianxuan.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

