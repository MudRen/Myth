// fanting.c

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

�����з���һ�Ű����������ϱ����Ǽ���һ����˸ճԹ����ˣ�С
Ѿ������ɨ��ʣ��ʣ����˵��ʣ��ʣ������ʵ��Щ��û������
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"zhting",
]));
set("objects", ([
                __DIR__"npc/yahuan": 1,
]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


