inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
          set_name(HIR"�������԰�"NOR, ({ "board" }) );
        set("location", "/d/calvin/lanling/xingyuejiulou2");
       set("board_id", "bangpai_b");
        set("long",
                "�������������¸���������Եĵط������ɵ�������˵��(post)��\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
