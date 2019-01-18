inherit NPC;

void create()
{
        set_name("����ͷ", ({"lao tou","lao", "tou"}));
        set("gender", "����" );
        set("age", 55+random(10));
        set("long",
"�������ָ����ݣ���ü���ۡ�
��Ҳ�������´������㡣\n");

        set("combat_exp", 8000+random(1000));
        set("per", 10);
        set("attitude","heroism");
	set("max_kee", 700);
        set("chat_chance",10);
	set_skill("stealing", 80);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 40);
        set("chat_msg",
        ({
                "��ͷЦ�����أ���������ش������㡣\n",
                (: random_move :),
        }));
        set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
                (: command, "surrender" :),
        }) );


        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("silver", 1);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;

        switch( random(6) ) {
                case 0:
                        say( "��ͷ���ﲻ֪˵��ʲô��\n");
                        break;
                case 1:
                        command ("steal silver from " + ob->query("id") );
                        break;
                case 2:
                        command ("steal coin from " + ob->query("id") );
                        break;
                case 3:
                        command ("steal jitui from " + ob->query("id") );
                        break;
                case 4:
                        command ("grin");
                        break;
                case 5:
                        command ("look " + ob->query("id") );
                        break;

        }

}

int accept_fight(object me)
{
        command("say ��ܣ�����ͷ�������Ķ��֣�\n");
        return 0;
}

