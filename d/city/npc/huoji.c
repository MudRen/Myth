inherit NPC;

void create()
{
        set_name("���", ({"huoji"}));
        set("age", 25);
        set("gender", "����");
        set("long",
"һ���ܸɵĻ�ơ�\n");
        set("attitude", "peaceful");

        set("combat_exp", 8000);
        set("shen_type", 1);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}


