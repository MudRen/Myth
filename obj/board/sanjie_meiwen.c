
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIR"������"HIC"��̶���ļ���"NOR, ({ "board" }) );
           set("location", "/d/city/liwuroom");
             set("board_id", "sanjie_meiwen");
          set("long",     "������԰��������񻰷����Լ����µĵط����ſ�����ػ���д�ϼ�ƪ�ɡ�\n" );
        setup();
          set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}
