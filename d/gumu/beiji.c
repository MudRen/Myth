//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"��������"NOR);
        set("long", @LONG

���������˸�ƻ�Ի��������ƣ������ǵ���������ƶ��
������һ��ɫˮ����̶��ɱ�����槼���Ȼ�������������飬
��ס�Ĵ�������

LONG
        );
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/daji.c" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"yongdao4.c",
  "south" : __DIR__"tianshu",
  "southwest" : __DIR__"xuanshi.c",
  "southeast" : __DIR__"tianzhi.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

