inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIR"��˿�����԰�"NOR, ({ "board" }) );
           set("location", "/d/dntg/hgs/entrance");
             set("board_id", "pansi_ss");
          set("long",     "������԰������ǹ�ͬ�������Եĵط����ſ�����ػ���˵�ϼ���ɡ�\n" );
        setup();
          set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
