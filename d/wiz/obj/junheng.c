// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���ɾ���������", ({ "board" }) );
        set("location", "/d/wiz/tanake");
        set("board_id", "junheng");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
        set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
