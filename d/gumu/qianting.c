//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"��Ĺǰ��"NOR);
        set("long", @LONG

������Ĺ�ĵ�һ��ʯ�ң��ıھ��Ǽ�Ӳ����ʯ����Ĺ
�ڹ���ʮ��������������Ϊ���ˣ�������������֮��
����ɪɪ����,���ͨ��ڤ˼�ң��������Ǵ����ҡ�


LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/bei" : 1,
  "/obj/zhangmen/gumu.c" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"mingsi.c",
  "east" : __DIR__"dazuo.c",
  "north" : __DIR__"zhongting.c",
  "south" : __DIR__"yongdao4.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


