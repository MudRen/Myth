// dizi.c

inherit NPC;

void create()
{
	int skill;

	set_name("��ݵ���", ({ "wuguan dizi", "dizi", "trainee" }) );
	set("gender", "����" );
	set("age", 18+random(10));
	set("long", "�㿴��һλ��ĸߴ�ĺ��ӣ���������ز����š�\n");

	set("combat_exp",4000);


	set_skill("dodge", 10);
	set_skill("unarmed", 10);

	setup();
	carry_object("/d/obj/cloth/linen")->wear();
}
