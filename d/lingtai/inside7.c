// Room: some place in ��ţ����
// inside7.c

inherit ROOM;

void create()
{
        set ("short", "������");
        set ("long", @LONG

���о����ĵģ���λ�������ڴ���������
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "west": __DIR__"inside2",
        ]));
        set("objects", ([
                __DIR__"npc/huiliu": 1,
                __DIR__"npc/huigang": 1,

        ]) );
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

