// meet_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��������", ({ "board" }) );
        set("location", "/d/wiz/meeting");
        set("board_id", "meet_b");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
        set("capacity", 400);
	replace_program(BULLETIN_BOARD);
}
