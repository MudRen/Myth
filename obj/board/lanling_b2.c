inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIG"���NPC����"NOR, ({ "board" }) );
        set("location", "/d/calvin/lanling/npcroom");
       set("board_id", "lanling_b2");
        set("long",
                "����һ�������������NPC������ϸλ�õĹ���档\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
