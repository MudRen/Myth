// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����֮�����԰�", ({ "board" }) );
	set("location", "/d/ourhome/kedian");
	set("board_id", "common_a");
	set("long",	"д����ĸ��ܰɣ���������\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}
