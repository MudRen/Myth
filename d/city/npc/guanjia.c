inherit NPC;

void create()
{
        set_name("�", ({ "li ding", "li", "guanjia" }));
        set("title", "��ܼ�");
        set("gender", "����");
        set("age", 65);

        set("combat_exp", 12500);
        set_skill("unarmed", 30);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);
        set_skill("dodge", 40);
	set_skill("parry", 30);
        setup();

        carry_object("/d/gao/obj/magua")->wear();
        add_money("silver", 10);

}

