inherit NPC;

void create()
{
        set_name("���", ({ "cha ke", "cha", "ke" }) );
        set("gender", "����" );
        set("age", 25);
        set("long",
              "һ���ڲ��̺Ȳ���ˡ�\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
        set_skill("dodge",20);
        set_skill("unarmed",20);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��͵���ͷ���˿ڲ衣\n",
        }) );       
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("silver", 1);
}


