// tong-nan.c

inherit NPC;

void create()
{
	set_name("ͯ��", ({ "tong-nan", "boy" }) );
	set("gender","����" );
	set("long",
		"����һ��ʮ�����ҵ�С�к�������ü��Ŀ�㣬\n"
		"�ǳ�����ϲ����\n"
	);
	set("age",10);
	set("per",30);
	set("combat_exp", 5000);
	set("score",500);
	set("force",100);
	set("max_force",100);
	set_skill("unarmed",30);
	set_skill("dodge",30);
	set_skill("parry",30);
	set_skill("force",40);

	setup();
	carry_object("/d/obj/cloth/linen")->wear();
}
