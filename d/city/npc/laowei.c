inherit F_VENDOR_SALE;
void create()
{
    reload("city_weiluqi");
        set_name("κ¼��", ({"wei luqi", "wei"}));
        set("age", 42);
        set("gender", "����");
        set("long",
"�ӻ��̵��ϰ壬Ц���еĿ����㡣\n");
	set("title", "�ӻ����ϰ�");
        set("attitude", "peaceful");

        set("combat_exp", 10000);
        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set_skill("parry", 30);
        set("vendor_goods", ([
                "cutan": "/d/obj/food/cutan",
                     "box":   "/d/city/obj/depositbox",
		"bag": "/d/obj/misc/bag",
		"seal": "/obj/paper_seal",
        ]) );
        setup();

        carry_object("/d/obj/cloth/choupao")->wear();
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
                        say( name()+"˵������λ" +
RANK_D->query_respect(ob)
                                + "��Ҫ��Щʲô������\n");
                        break;
        }
}

