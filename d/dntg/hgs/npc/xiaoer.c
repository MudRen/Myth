inherit F_VENDOR_SALE;

void create()
{
    reload("aolai_xiaoer");
       set_name("��С��", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","��С��");
       set("gender", "����");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ([
                "jiudai": "/d/moon/obj/jiudai",
                "gourou": "/d/ourhome/obj/gourou",
                "jitui": "/d/ourhome/obj/jitui",
                "huasheng": "/d/ourhome/obj/huasheng",
        ]) );

        setup();
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
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say(name()+ "Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "������ЪЪ�ţ������Ѱɡ�\n");
                        break;
        }
}


int accept_object(object me,object ob)
{
        object m;
        if (ob->query("id")=="old hen") {
		command("hehe " + this_player()->query("id") );
		m=new("/d/obj/food/jitui");
		m->move(this_player());
		message_vision(name()+"͵͵����$Nһ�������ȡ�\n", this_player());
	        call_out("destroy", 1, ob);
        return 1;
        }
        else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

