inherit NPC;

void create()
{
        set_name("����", ({"da shou", "shou"}));
        set("age", 22);
        set("gender", "����");
        set("long",
"��Ȼ�书����ô�������ĺ�������Ҳ�����ǡ�\n");
        set("attitude", "heroism");

        set("combat_exp", 10000+random(2000));
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("blade", 20);

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "���ִ󺰣��Ҹ����ӹ���ȥ��ȥ���ɣ�\n"
        }));
        setup();
        carry_object("/d/obj/weapon/blade/blade")->wield();
        carry_object("/d/obj/cloth/linen")->wear();
}


