inherit F_VENDOR_SALE;
void create()
{
    reload("city_jiaer");
        set_name("�ֶ�", ({"jia er", "jia"}));
        set("age", 32);
        set("gender", "����");
        set("long","�����̵��ϰ壬Ц���еĿ����㡣\n");
	set("shop_title", "�������ϰ�");
	set("shop_id", ({"laoban"}));
        set("attitude", "friendly");

        set("combat_exp", 10000);
        set("shen_type", 1);
	set("force", 200);
	set("force_factor", 5);
        set_skill("unarmed", 20);
        set_skill("dodge", 60);
        set_skill("parry", 20);
        set("vendor_goods", ([
                "roubao": "/d/obj/food/bao1",
                "haibao": "/d/obj/food/bao2",                
                "subao": "/d/obj/food/bao3",                
        ]) );

	setup();
        add_money("silver", 3);
        carry_object("/d/obj/cloth/linen")->wear();
}
int accept_fight(object me)
{
        command("say ��Һ������ƣ��������ƣ�\n");
        return 0;
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
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "�������Լ������Ӱɡ�\n");
                        break;
        }
}

