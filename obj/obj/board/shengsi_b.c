inherit BULLETIN_BOARD;

void create()
{
	set_name("������", ({"board"}) );
set("location", "/d/death/zhengtang");
set("board_id", "shengsi_b");
set("capacity", 100);
set("long", "����ܿܿ�������������������¼��\n");
        setup();
        replace_program(BULLETIN_BOARD);
}

