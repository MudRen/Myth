inherit BULLETIN_BOARD;

void create()
{
        set_name("�����ĺ����԰�", ({ "board" }) );
        set("location", "/d/sea/yujie2");
        set("board_id", "dragon_b");
	set("long", "
������������������������������������������������������������������������\n");
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

