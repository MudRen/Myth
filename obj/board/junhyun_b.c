// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("Ů������������¼", ({ "board" }) );
        set("location", "/u/junhyun/workroom");
        set("board_id", "junhyun_b");
	set("long",
		"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 200);
	set("env/invisibility",1);
	replace_program(BULLETIN_BOARD);
}
