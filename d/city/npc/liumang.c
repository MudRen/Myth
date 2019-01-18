inherit NPC;

void create()
{
        set_name("С��å", ({"xiao liumang", "liumang", "punk"}) );
        set("gender", "����" );
        set("age", 18+random(10));
        set("long",
"���ǳ�������һ�����ֺ��е�С��å��һ˫�۾�������ġ�\n");

        set_temp("apply/defense", 15);
        set("combat_exp", 3500);
        set("per", 15);
        set("attitude","heroism");

        set("chat_chance",10);
        set("chat_msg",
        ({
                "С��å���ﲻ�ɲ���������š�\n",
                "С��åЦ�����أ���������ش������㡣\n",
                (: random_move :),
        }));

        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("coin", 40+random(90));
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
                        say( "С��å���������˵����λ" +
RANK_D->query_respect(ob)
                                + "��Ҫ�Ҹ������һЩ��Ȥ��ȥ����\n");
                        break;
                case 1:
                        command ("hehe " + ob->query("id") );
                        break;
                case 2:
                        command ("grin " + ob->query("id") );
                        break;
                case 3:
                        command ("hi " + ob->query("id") );
                        break;
                case 4:
                        command ("xixi " + ob->query("id") );
                        break;
                case 5:
                        command ("look " + ob->query("id") );
                        break;

        }

}

