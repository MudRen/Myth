// guige.c
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "���");
  set ("long", @LONG

�����Ǹ�С��Ĺ�¥������װ�ε��ţ��Ҿ�ȫ���Ϸ�������������
ǽ�ϵ�һ���ֻ������Ϊ���ף����忴����Ҳ�൱��Ư����
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"houyuan",
"up" :__DIR__"yashi",
]));
create_door("up", "������", "down", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


