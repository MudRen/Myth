// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ʦ���԰�", ({ "board" }) );
        set("location", WIZARD_ROOM);
	set("board_id", "wizard_b");
    set("wiz_board",1);
	set("long",
		"����һ���������Լ��µ����԰塣\n" );
	setup();
        set("capacity", 1000);
	set("env/invisibility",1);
	replace_program(BULLETIN_BOARD);
}
