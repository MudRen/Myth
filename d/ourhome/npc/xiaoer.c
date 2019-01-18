// waiter.c

//inherit NPC;
//inherit F_VENDOR;

inherit F_VENDOR_SALE;

void create()
{
	reload("ourhome_xiaoer");
	set_name("��С��", ({ "xiao er" , "xiao" , "waiter" }) );
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","��С��");
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ�ţ�����ʱ������ڲ����ϵ�Ĩ�������֡� \n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ([
		"gourou": "/d/ourhome/obj/gourou",
		"xigua": "/d/ourhome/obj/watermelon",
		"jitui": "/d/ourhome/obj/jitui",
	]) );
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
	if( !ob || !visible(ob) || environment(ob) != environment() ) return;
		if((string)ob->query("startroom")=="/d/ourhome/kedian"){
                		ob->set("startroom","/d/city/kezhan");
		}	
	switch( random(3) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
		case 2:
			say( "��С��˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȼ���С��Ļ���ɣ��⼸��Ŵӽ����￪���Ӵ��\n");
			break;
	}
}
