//���㻨̳
//������д�ְ�

inherit BULLETIN_BOARD; 
#include <ansi.h> 

void create()
{
set_name(MAG "���㻨̳" NOR, ({ "board" }) );
         set("location", "/u/flash/workroom");
        set("board_id", "flash_b");
        set("long",
                  "�����Ļ�̳,���������˶��㻨��\n" );
        setup();
        set("capacity", 200);
// 16          set("env/invisibility",1)
        replace_program(BULLETIN_BOARD);
}

