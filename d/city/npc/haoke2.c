inherit NPC;

void create()
{
        set_name("������", ({"pang zi"}));
        set("age", 42);
        set("gender", "����");
        set("long",
"һ�������ӣ����˼����������ˡ�\n");
        set("attitude", "peaceful");

        set("combat_exp", 19000);
        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 30);
	setup();
        carry_object("/d/obj/cloth/magua")->wear();
}


