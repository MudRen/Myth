inherit NPC;
void create()
{
        set_name("�Է�", ({ "qiao fu" }) );
        set("gender", "����" );
        set("age", 33);
        set("per", 30);
        set("long", "һ�������Է�\n");
        set("combat_exp", 6000);
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set_skill("axe", 20);
        set("chat_chance",10);
        set("chat_msg",({
        (:random_move:)
        }));
        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "�Է�е���ɱ���ģ�ɱ���ģ�\n",
                "�Է�е����������ģ����컯���´���ģ�\n",
                (: command, "surrender" :),
        }) );
        setup();
        add_money("coin", 50);
	carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/lingtai/obj/axe")->wield();
}

