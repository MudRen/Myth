// lost_b.c
#include <ansi.h>


inherit BULLETIN_BOARD;

void create()
{
        set_name(HIW"�������"NOR, ({ "story" }) );
        set("location", "/u/lost/workroom.c");
        set("board_id", "lost_b");
        set("long",     "��������£\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}


