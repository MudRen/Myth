// lanling_b1.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�����ջ���԰�", ({ "board" }) );
        set("location", "/d/calvin/kezhan2");
        set("board_id", "lanling_b1");
        set("long",     "����һ���������Լ��µ����԰塣\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
