
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIB"�����������������԰�"NOR, ({ "board" }) );
           set("location", "/d/city/xqt");
             set("board_id", "sjsh_ss");
          set("long",     "������԰������ǹ�ͬ�������Եĵط����ſ�����ػ���˵�ϼ���ɡ�\n" );
        setup();
          set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}
