//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short", "����������");
        set("long", @LONG

���ͨ����ɫ��һ��Ů���ڵ����������裬�������������
��һ�ֹ�������գ�����е�����������ʯ��̵���������
����������ͼ������������������ë���ɽ���......

LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ximei" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sleeproom.c",
  "northwest" : __DIR__"beiji.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

