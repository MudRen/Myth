//Cracked by Roath
// dizi.c

inherit NPC;

void create()
{
	int skill;

	set_name("����������", ({ "changan tudi", "tudi"}) );
	set("gender", "����" );
	set("age", 80);
	set("long", "һλ�׺����Ϲ�����\n");

	set("combat_exp",4000);
	set("daoxing", 4000);

	set_skill("dodge", 10);
	set_skill("unarmed", 10);

	setup();
	carry_object("/d/qujing/biqiu/obj/staff")->wield();
	carry_object("/d/obj/cloth/baipao")->wear();
}
