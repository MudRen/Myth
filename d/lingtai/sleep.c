// Room: some place in ��ţ����
// sleep.c

inherit ROOM;

void create()
{
        set ("short", "����");
        set ("long", @LONG

������ҲҪ˯����������;����˯�ɣ�

LONG);
        set("exits", ([ /* sizeof() == 4 */
                "north": __DIR__"inside2",
        ]));
        set("objects", ([
               "/d/obj/weapon/stick/bang": 1]));

        set("no_clean_up", 0);
        set("sleep_room",1);
        set("if_bed",1);

        setup();
        replace_program(ROOM);
}

