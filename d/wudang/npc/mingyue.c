
// mingyue.c

inherit NPC;

void create()
{
	set_name("����", ({ "ming yue", "ming", "yue" }));
	set("long", 
		"�����䵱ɽ��С��ͯ��\n");
	set("gender", "����");
	set("age", 16);
	set("attitude", "peaceful");

	set("str", 20);

	set("combat_exp", 5000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	create_family("�䵱��", 4, "����");

	setup();
	
	carry_object("/d/wudang/obj/greyrobe")->wear();
}
