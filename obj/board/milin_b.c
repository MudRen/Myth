// ���ֱ��� ���԰� by Calvin
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIG"�������ְ�"NOR, ({ "board" }) );
        set("location", "/d/milin/qy/7");
       set("board_id", "milin_b");
        set("long",
                "������ڴ�����<post>��̸̸�Լ����ĵ�,�Թ����˹�Ħ��\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
