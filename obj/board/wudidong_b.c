// wudidong_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�ʱ�", ({ "board" }) );
        set("location", "/d/qujing/wudidong/kitchen.c");
        set("board_id", "wudidong_b");
        set("long", "�����޵׶����ʱ����ǳ�����������˭Т�������������õġ�\n");
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
