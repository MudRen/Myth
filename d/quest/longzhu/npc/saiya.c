// �������� by Calvin

inherit NPC;

void create()
{
        set_name("������", ({ "sai ya", "sai", "ya","man","woman"}));
        if(random(10)<7)
            set("gender", "����" );
        else
            set("gender", "Ů��" );
        set("age", 15+random(50));
        set("long",
                "����һ��δ֪���֡�\n");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }));

        set("combat_exp", 10000+random(10000000));
        set("daoxing", 10000+random(10000000));
      set("attitude", "aggressive");
        set_skill("dodge", 1000);
        set_skill("unarmed", 1000);
        setup();
//         carry_object("/obj/cloth")->wear();
}

