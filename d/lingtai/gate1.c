// Room: some place in ��ţ����
// gate1.c

inherit ROOM;
#include <room.h>
void create()
{
  set ("short", "СԺ");
  set ("long", @LONG

СԺ���з���һ�ڼ������¯�����ǻ�ͭ���죬������������
���顣¯�ϵ�С�ڷ���һ�����̣�Ժ���������ơ��������᷿��
��ǰ�߾͵�����Ժ��
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"inside1",
"south": __DIR__"gate",
"east": __DIR__"inside2",
"west": __DIR__"inside3",
]));
create_door("south", "ʯ��", "north", DOOR_CLOSED);
set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


