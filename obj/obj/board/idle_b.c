//Cracked by Roath
// idle_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("����������", ({ "board" }) );
        set("location", "/d/city/misc/idleroom");	
       set("board_id", "idle_b");
	set("long",	"����һ������ҽ�����ϰ�����󷨾���Ľ����塣\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
