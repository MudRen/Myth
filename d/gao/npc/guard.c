// xiaojie.c

inherit NPC;
void create()
{
       set_name("����ͷĿ", ({"bandit leader", "bandit", "leader"}));
       set("long","���կ��СͷĿ��\n");
       set("gender", "����");
       set("age", 28);
       set("attitude", "aggressive");
	set("per", 25);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 15);
        set("shen_type", 1);
	set("combat_exp", 15000+random(3000));
	set_skill("throwing", 40);
	set_skill("parry", 40);
	set_skill("dodge", 40);
        set("chat_chance", 2);
        set("chat_msg", ({
		"СͷĿ�󺰣�̫��ͷ�϶�����������ˣ�\n",
}) );

	setup();
        carry_object("/d/obj/weapon/throwing/dujili")->wield();
	carry_object("/d/gao/obj/piyi")->wear();
}
