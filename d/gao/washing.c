// washing.c

inherit ROOM;

void create()
{
  set ("short", "ϴ�·�");
  set ("long", @LONG

���µ���������ˮ��һ����������ϴ��һ���·���
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" :__DIR__"houyuan",
]));
set("objects", ([ 
		__DIR__"npc/washer": 1]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


