inherit F_VENDOR_SALE;

void create()
{
    reload("lukeqiu");
        set_name("³����", ({"lu keqiu", "lu", "keqiu"}));
        set("title", "ľ�����ϰ�");
        set("gender", "����");
        set("age", 42);
        set("long", "³�ϰ����Ϸ��ˣ�������ͦ�����ġ�\n");
	set("str", 30);
	set("con", 30);
	set("spi", 30);
        set("combat_exp", 20000);
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

        set("vendor_goods", ([
                "blade": "/d/city/obj/mudao",
                "sword": "/d/city/obj/mujian",
                "stick": "/d/city/obj/mugun",
                "staff": "/d/city/obj/muzhang",
 		"spear": "/d/city/obj/muqiang",
		"bow":   "/d/obj/weapon/archery/mugong",
		"arrow": "/d/obj/weapon/archery/zhujian",
        ]) );

        setup();
	add_money("silver", 20);
        carry_object("/d/gao/obj/magua")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
		call_out("greeting",1,ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"æ˵������������\n");
                        break;
        }
}
int accept_fight(object me)
{
        command("say ����Ҳ�ã�Ҳ�ã�\n");
        return 1;
}

