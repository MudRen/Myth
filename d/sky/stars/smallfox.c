
//note: this is created from player data.
//smallfox.c with foxer.c
inherit NPC;

void create()
{
	set_name("С����", ({"smallfox"}));
	set("long", "�����СѾ����\n");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "friendly");
	set("per", 20);

	setup();

	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/cloth/skirt")->wear();
}

