// sjsboard.c ����ɽ���԰�

inherit BULLETIN_BOARD;

void create()
{
        set_name("����ɽ���԰�", ({ "board" }) );
        set("location", "/d/sanjie/langerdian1.c");
        set("board_id", "sjsboard");
        set("long",     "����ɽ���԰塣��¼�˿ͺ�����ɽ���˶��������ڴˡ�\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

