
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name("��÷С�������ռǱ�", ({ "board" }) );
           set("location", "/u/leoy/workroom");
             set("board_id", "fplum_b");
          set("long",     "���Ǻ���÷�������ռǱ���\n" );
	setup();
          set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}
