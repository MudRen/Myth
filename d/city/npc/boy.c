// kid.c

inherit NPC;

void create()
{
	set_name("�к�",({ "boy" }) );
        set("gender", "����" );
        set("age", 13);
	set("long", "���Ǹ����͵ĳ������꣬��Ͳ��󣬳��úܻ��顣\n");
	set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 100);
	set("attitude", "peaceful");

        setup();

        carry_object("/d/obj/cloth/linen")->wear();
	add_money("coin", 40);
}

