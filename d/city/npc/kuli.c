inherit NPC;

void create()
{
        set_name("����", ({"kuli"}));
        set("age", 22);
        set("gender", "����");
        set("long","һ�������ƾɵĿ����ˡ�\n");
        set("attitude", "heroism");

        set("combat_exp", 5000+random(1000));
        set("shen_type", 1);

        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_skill("blade", 10);

        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}


