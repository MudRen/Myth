// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("花哥留在蛇口的大嘴巴", ({ "board" }) );
        set("location", "/u/koker/workroom");
        set("board_id", "koker_b");
	set("long",
		"这是一个供人留言记事的留言板。\n" );
	setup();
	set("capacity", 200);
	set("env/invisibility",1);
	replace_program(BULLETIN_BOARD);
}
