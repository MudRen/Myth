// Void.c

inherit ROOM;

void create()
{
        set("short", "ʮ�˲����");
        set("long", @LONG

Ѫ��Ѫ�� Ѫ�� ����������������Ѫ��
LONG
        );


        set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/city/center",
]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
        replace_program(ROOM);
}

