//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIB"��"NOR);
        set("long", @LONG

��ʯ�̵أ�ǽ�������ʯ��⻬����Զ���ĵ���
�и�Сʯ�ţ���������ɭ�ĵط�����һ��Ҳ����
��ͣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"tianji.c",
  "south" : __DIR__"tianquan.c",
  "north" : __DIR__"jin.c",
  "west" : __DIR__"shui.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

