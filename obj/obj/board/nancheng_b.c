// nancheng_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�ϳǿ�ջ���԰�", ({ "board" }) );
	set("location", "/d/city/kezhan");
	set("board_id", "nancheng_b");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
        set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
