// seng_b.c
//created by seng@2005/1/15
//�ռ���Ϣ

#include <ansi.h> 
inherit BULLETIN_BOARD;

void create()
{
       set_name(HIY "��������������"NOR, ({ "board" }) );
        set("location", "/d/wiz/quests");
        set("board_id", "seng_b");
        set("long",     "��2005��1��15���𣬿�ʼͳ�������������������еĶ��������������ݡ�by seng\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
