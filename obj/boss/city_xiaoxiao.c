inherit F_VENDOR_SALE;

void create()
{
    reload("xiaoxiao");
        set_name("����", ({"xiao xiao", "xiao"}));
        set("title", "������");
        set("gender", "Ů��");
        set("age", 25);
        set("long", "��Ӣ������Զ��СŮ����������Ů�ϰ塣
���������ݶ��������˳ƣ������ӣ���\n");

        set("combat_exp", 70000);
	set_skill("fonxansword", 30);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
	set_skill("moondance", 50);
	map_skill("dodge", "moondance");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

        set("vendor_goods", ([
               "dagger": "/d/obj/weapon/dagger/dagger.c",
                "axe": "/d/obj/weapon/axe/tiefu.c",
                "hammer": "/d/obj/weapon/hammer/hammer",
                "fork": "/d/obj/weapon/fork/fork",
            	"tiegun": "/d/obj/weapon/stick/bintiegun",
                "tielian":"/d/obj/weapon/whip/tielian",
                "shield": "/d/obj/armor/niupi",
                "sword": "/d/obj/weapon/sword/changjian",
                "blade": "/d/obj/weapon/blade/blade",
                "spear": "/d/obj/weapon/spear/tieqiang",
                "staff": "/d/obj/weapon/staff/chanzhang",
        ]) );

        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
		call_out("greeting",1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( name()+"���������æ˵�����͹ٿɷ���Ұ�һ�����������ڰ������ľ˾���ȥ���³�֮���Ҳ��������ġ�\n");
                        break;
        }
}
int accept_fight(object me)
{
        command("say �ߣ����������Ҳ����Ұ��\n");
        return 1;
}

