// neishi.c
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

���䲻��ȴ��ʯ��ʯ�������ϻ�����������ӣ�Ҫ�Ǵ���
������������û����ȥ�ģ�
LONG);

set("exits", ([ /* sizeof() == 4 */
"west" : "/d/gao/room",
]));

 set("objects", ([ /* sizeof() == 2 */
"/d/gao/obj/xiaojie" : 1,

]));

	create_door("west", "ʯ��", "east", DOOR_CLOSED);

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

