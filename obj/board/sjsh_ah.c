
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name("�����񻰷�չ���۰�", ({ "board" }) );
           set("location", "/d/wiz/entrance");
             set("board_id", "sjsh_ah");
          set("long",     "���ǹ���ʦ����һ��ཻ������ͬ�ٽ������񻰷�չ�����۰塣\n" );
	setup();
          set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}
