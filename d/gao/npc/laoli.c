// laoli.c

inherit "/std/char/smith.c"; 

void create()
{
        reload("lao_li");
        set_name("����ͷ", ({"lao li", "li"}));
        set("long", "���̵����ˣ�\n");
        set("gender", "����");
        set("title", "����");
        set("per", 15);
        set("combat_exp", 6800);
        set("age", 56);
        set("attitude", "friendly");
        set("shen_type", 1);
        set_skill("unarmed", 15);
        set("chat_chance", 5);
        set("chat_msg", ({
                name()+"һ������Сѧͽ��ƨ���ϣ��µ�������͵����\n",
                name()+"��Сѧͽ�µ���������ٴ��ˣ�����ô��ô����\n",
        }) );
        set("vendor_goods", ([
                "blade": "/d/gao/obj/blade",
                "sword": "/d/gao/obj/sword",
                "dagger": "/obj/example/dagger",
        ]) );
        setup();
        add_money("coin", 50+random(200));
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/hammer/hammer")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"����˵������λ" +
RANK_D->query_respect(ob)
                                + "��Ҫ��������\n");
                        break;
        }
}

