// xueshan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("		ѩɽ���԰�", ({ "wall" }) );
        set("location", "/d/xueshan/restroom.c");
        set("board_id", "xueshan_b");
        set("long",     "ѩɽ���԰塣\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

