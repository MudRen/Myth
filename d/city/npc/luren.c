//Last Create  By PKYOU@DHXY 2002/05/25
inherit NPC;

void create()
{
	set_name("路人",({ "luren" }) );
        set("gender", "男性" );
        set("age", 33);
	set("long", "这是路经长安的一些过客，年纪在三十左右，象是些商人。\n");
	set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 10000);
	set("attitude", "peaceful");

        setup();

       carry_object("/d/obj/cloth/linen")->wear();
	add_money("coin", 40);
}

