// moon_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�¹����԰�", ({ "board" }) );
      set("location", "/d/moon/xiaoyuan");
        set("board_id", "moon_b");
        set("long",     "�¹����԰塣\n" );
set("capacity", 80);
        setup();
        replace_program(BULLETIN_BOARD);
}

