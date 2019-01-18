// waiter.c


inherit F_VENDOR_SALE;

void create()
{
        reload("wudidong_blacksmith");
        set_name("������", ({ "blacksmith", "smith", "zhang", "zhang tiebi", "tiebi" }) );
        set("gender", "����" );
        set("age", 42);
        set("title", "����");
        set("long","���������ڴ�����¯���������ӳ��ͨ�졣\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("rank_info/respect", "�Ŵ��");
        set("per",25);
        set("vendor_goods", ([
		"zhadao"  : "/d/obj/weapon/blade/zhadao.c",
		"tiefu"   : "/d/obj/weapon/axe/tiefu.c",
		"sickle"  : "/d/obj/weapon/blade/sickle.c",
		"scythe"  : "/d/obj/weapon/blade/scythe.c",
		"pickaxe" : "/d/obj/weapon/hammer/pickaxe.c",
		"plow"    : "/d/obj/weapon/hammer/plow.c",
	]));
	setup();
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
	say("������˵������λ" + RANK_D->query_respect(ob)
		+"��Ҫ��ʲô������\n");
}
