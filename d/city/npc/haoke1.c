inherit NPC;

void create()
{
        set_name("�ƿ�", ({"jiu ke"}));
        set("age", 32);
        set("gender", "����");
        set("long",
"һ���������ݵ�С���ӣ�Խ�Ȼ�Խ�о���\n");
        set("attitude", "peaceful");

        set("combat_exp", 20000);
        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
        set_skill("unarmed", 40);
        set_skill("dodge", 50);
        set_skill("parry", 50);
	setup();
        carry_object("/d/obj/cloth/piyi")->wear();
}


