// Room: some place in ��ţ����
// gate.c
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "ɽ��");
  set ("long", @LONG

�ſ���һʯ����Լ�������Ÿߣ��˳�����������һ��ʮ�����֣�
���ǡ���̨����ɽ��б�����Ƕ�����ɽ������һ��ͯ���������
Ӣΰ����ò���棬��Ѱ�����Ӳ�ͬ��
LONG);
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"gate1",
"southdown": __DIR__"uphill6",
]));

set("objects", ([
                __DIR__"npc/yingke": 1 ]) );
        create_door("north", "ʯ��", "south", DOOR_CLOSED);
         set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        "obj/board/shibei_b"->foo();
}


