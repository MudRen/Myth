// laoyu.c

inherit F_VENDOR_SALE;

void create()
{
    reload("wang_zhanggui");
       set_name("���ƹ�", ({"wang zhanggui", "wang"}));
       set("long", "С�ƹݵ��ϰ壬�Ե����ֵģ�\n");
       set("gender", "����");
	set("title", "�ƹ��ϰ�");
	set("combat_exp", 3000);
       set("age", 46);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ([
                "gourou": "/d/ourhome/obj/gourou",
                "jitui": "/d/ourhome/obj/jitui",
		"huasheng": "/d/ourhome/obj/huasheng",
        ]) );

	setup();
       add_money("silver", 2);
	add_money("coin", random(80));
        carry_object("/obj/cloth")->wear();

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
                        say( name()+"Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "�����������Ѱɡ�\n");
                        break;
	}
}
