//  kuku_b.c 

inherit BULLETIN_BOARD;

void create()
{
        set_name("˿������", ({ "board" }) ); 
        set("location", "/u/kuku/workroom"); 
        set("board_id", "kuku_b");
        set("long", "һ��ǳ��ɫ��˿�����磬����������¼һЩ������\n" ); 
        setup();
        set("capacity", 300); 
        replace_program(BULLETIN_BOARD); 
}
