
inherit NPC;

void create()
{
        set_name("����", ({ "yu weng"}));
            set("gender", "����" );
        set("age", 45+random(10));
        set("long","һλ�����̡�");
        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }));

        set("combat_exp", 600+random(400));
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set_skill("unarmed", 10);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 30+random(20));
}

