// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���������߿ڵĴ����", ({ "board" }) );
        set("location", "/u/koker/workroom");
        set("board_id", "koker_b");
	set("long",
		"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 200);
	set("env/invisibility",1);
	replace_program(BULLETIN_BOARD);
}
