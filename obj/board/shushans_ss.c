inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIW"��������"NOR, ({ "board" }) );
           set("location", "/d/shushan/jinglou");
             set("board_id", "shushans_ss");
          set("long",     "������԰��ǽ����ǹ�ͬ�������Եĵط����ſ�����ػ���˵�ϼ���ɡ�\n" );
        setup();
          set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
