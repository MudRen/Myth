inherit NPC;

void create()
{
	set_name("Ů��",({ "girl" }) );
        set("gender", "Ů��" );
        set("age", 12);
	set("long", "���Ǹ������ǵĵ�����Ů����Ȼֻ��ʮ�������꣬�����Ѿ������ʱ��\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("str", 14);
        set("dex", 15);
	set("per", 25);
	set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
	setup();
	carry_object("/d/obj/cloth/pink_cloth")->wear();
	add_money("coin", 50);
}

