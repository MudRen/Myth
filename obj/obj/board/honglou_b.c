// honglou_b.c by none on 96/10/25

inherit BULLETIN_BOARD;

void create()
{
        set_name("��ʯ", ({ "jade" }) );
        set("location", "/d/ourhome/honglou/main.c");
        set("board_id", "honglou_b");
        set("long",     "һ����ʯ������д��¥���¡�:)\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

