inherit NPC;

void create()
{
        set_name("����", ({"hua ren", "hua"}));
        set("age", 27);
        set("gender", "����");
        set("long",
"����һ�������ĵ��̣�����֮����\n");
	set("title", "������");
        set("attitude", "peaceful");

        set("combat_exp", 40000);
        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
        set_skill("unarmed", 40);
	set_skill("changquan", 40);
        set_skill("dodge", 60);
        set_skill("parry", 60);
	map_skill("unarmed", "changquan");
	setup();
	add_money("silver", 10);
        carry_object("/d/obj/cloth/piyi")->wear();
}


