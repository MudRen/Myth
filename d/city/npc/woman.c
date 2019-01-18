inherit NPC;

void wield_knife();

void create()
{
        set_name("����", ({ "woman" }) );
        set("gender", "Ů��" );
        set("age", 30);
        set("long", "һ��Ѱ���Ĵ��︾��.");
        set("combat_exp", 4000);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_skill("unarmed", 10);
        set_skill("blade",10);

        set("chat_chance",3);
        set("chat_msg", ({
                "���˴򿪹�������һ��.\n",
                "������˵��: ��ô��������? \n",
                "������̧ͷ��������. \n",
        }));
        set("chat_chance_combat",100);
        set("chat_msg_combat", ({
                (: wield_knife :)
        }));
        setup();

        carry_object("/d/obj/cloth/linen")->wear();
}

void wield_knife()
{
    object knife;
    
    knife = present("cai dao", environment(this_object()));
    if(!knife) return;

    if(knife->query("weapon_prop") == 0) return;

    knife->move(this_object());
    say("����ץ��һ�Ѳ˵����������Ⱔǧ���ģ�\n");
    command("wield knife");
}

