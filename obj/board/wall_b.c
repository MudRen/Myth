inherit BULLETIN_BOARD;

void create()
{
set_name("���Ա�", ({"wall"}) );
set("location", "/d/nanhai/gate");
set("board_id", "wall_b");
set("capacity", 100);
set("long", "һ�����Աڣ����������������ߵ����ԡ�\n");
        setup();
        replace_program(BULLETIN_BOARD);
}

