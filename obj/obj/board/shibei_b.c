inherit BULLETIN_BOARD;

void create()
{
        set_name("  ʯ��  ", ({ "shibei" }) );
        set("location", "/d/lingtai/gate");
        set("board_id", "shibei_b");
	set("long", "һ���ʯ������д����̨����ɽ��б�����Ƕ���
������������������������������������������������������������������������\n");
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

