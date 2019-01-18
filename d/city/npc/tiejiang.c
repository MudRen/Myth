// waiter.c

inherit F_VENDOR_SALE;

void create()
{
    reload("zhoutiejiang");
        set_name("������", ({ "zhou tiejiang", "zhou", "tiejiang", "smith"
}) );
        set("gender", "����" );
	set("title","����");
        set("age", 42);
        set("long",
                "��������ʮ���꣬���û�����������\n");
        set("combat_exp", 10000);
        set("attitude", "peaceful");

        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("literate", 40);

        set("max_kee", 600);
        set("max_sen", 600);


        set("vendor_goods", ([
                "dagger": "/d/obj/weapon/dagger/dagger.c",
                "axe": "/d/obj/weapon/axe/tiefu.c",
                "hammer": "/d/obj/weapon/hammer/hammer",
		"fork": "/d/obj/weapon/fork/fork",
	    "tiegun": "/d/obj/weapon/stick/bintiegun",
		"tielian":"/d/obj/weapon/whip/tielian",
        ]) );
        setup();

        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/weapon/hammer/hammer")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( name()+"˵������λ" +
RANK_D->query_respect(ob)
                                + "��������㿴���ɡ�\n");
                        break;
                case 1:
                        say(name()+ "�ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" +
RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say(name()+ "˵������λ" +
RANK_D->query_respect(ob)
                                + "��������һ�����ֵı����ɡ�\n");
                        break;
        }
}

