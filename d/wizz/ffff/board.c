// xueshan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("		ѩɽ���԰�", ({ "wall" }) );
         set("location", "/u/ffff/workroom.c");
set("board_id", "ffff_b");
 set("long",     "ffff�����԰塣\n" );
 setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

