// lanling_b1.c
inherit BULLETIN_BOARD;

void create()
{
        set_name("���������", ({ "board" }) );
        set("location", "/d/calvin/lanling/clubroom");
        set("board_id", "clubroom_b");
        set("long",     "����һ������������ɵ�����塣\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
