// by snowcat
inherit NPC;

void create()
{
       set_name("���", ({"ma guan","guan"}));
       set("gender", "����");
        set("combat_exp", 2000);
       set("age", 36);
       set("per", 34);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 30);
       set_skill("dodge", 30);
       set_skill("parry", 30);

       setup();
       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 2);
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
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( "���һ�Ϲ�˵������λ" + RANK_D->query_respect(ob)
                                + "�����\n");
                        break;
        }
}


