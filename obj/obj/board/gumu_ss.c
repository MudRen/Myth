inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIY"��Ĺ�ؼ�"NOR, ({ "mi ji" }) );
           set("location", "/d/gumu/zhongting");
             set("board_id", "gumu_ss");
          set("long",     "��������з���һ���ؼ������̲�ס�뷭�����¡�\n" );
        setup();
          set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
