//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"��ԯħ��"NOR);
        set("long", @LONG
��������ԯħ�����������ɢ����һ������
���ж���һ�ˣ����ǿ��촴������ԯ��ۡ�


LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  "d/gumu/npc/xuanyuan" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"xuanyuan2.c",
//  "east" : __DIR__"xuanyuan3.c",
  "south" : __DIR__"xuanyuan.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

