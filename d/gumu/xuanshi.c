//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"������ʯ��"NOR);
        set("long", @LONG

������϶�����ʱ����ʯͷ��ÿһ�鶼͸���������һ��
����ʯ��ɵĹ����η��ڿ��ϵ�ǽ�£�һ�����޵�Ů�Ӱ���
��ʯ���ϣ�����ɢ�������ĵ���Ϣ......

LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wang" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"sleeproom.c",
  "northeast" : __DIR__"beiji.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


