inherit NPC;

void create()
{
        set_name("����", ({ "xian ren", "xian", "ren" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
              "һ���ڽ����й�����ˡ�\n");
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
                "���˵����ֹ���һ����\n",
        }) );       

        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("coin", 30);
}


