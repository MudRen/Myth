
inherit NPC;
void create()
{
	set_name("����", ({ "cheng yuhuan", "cheng", "yuhuan" }));
	set("long", 
		"�����ǳ�֪���Ķ���Ů���������绨����ò�����ɵĳ��񻷡�\n"
		"��˵���������䵱����ѧ��������\n");
		
	set("title", "֪��ǧ��");
	set("nickname", "���ɹ�");
	set("gender", "Ů��");
	set("age", 18);
       set("per",25);

	set("force", 400);
	set("max_force", 400);
	set("max_kee", 400);
	set("max_sen", 200);

	set_skill("force", 50);
	set_skill("unarmed", 40);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set("combat_exp", 50000);
	setup();
}
