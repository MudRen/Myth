// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"���ļ���"NOR, ({ "board" }) );
        set("location", "/u/yanyang/workroom");
        set("board_id", "yanyang_b");
	set("long",
                "���ǻ��������һ�����Լ��µ����Ա���\n" );
	setup();
	set("capacity", 200);
	set("env/invisibility",1);
	replace_program(BULLETIN_BOARD);
}
