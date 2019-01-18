
inherit NPC;

void create()
{
       set_name("��ͷ", ({"laotou"}));
       set("long", "һ����ü��Ŀ���ϴ�ү��\n");
       set("gender", "����");
        set("combat_exp", 3000);
	set("per", 18);
       set("age", 56);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 15);
        setup();
       add_money("silver", 1);
}
void init()
{
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
	object m,n,mm;
	message_vision("$N����ͷ�ʵ����ϴ�ү����������\n", this_player());

	if((int)this_player()->query("food") >= (int)this_player()->max_food_capacity()*90/100 )
	return notify_fail("��ͷЦ�����ȿ���ʱ�����ɣ�\n");

	if((int)this_player()->query("water") >= (int)this_player()->max_water_capacity()*90/100 )
        return notify_fail("��ͷЦ�����ȿ���ʱ�����ɣ�\n");
            
	if((present("bao", this_player())))
	return notify_fail("��ͷЦ�����㻹û�����أ���ô��Ҫ��\n");

        if((present("teapot", this_player())))
        return notify_fail("��ͷЦ�����㻹û�����أ���ô��Ҫ��\n");


	m=new("/d/obj/food/baozi");
        mm=new("/d/obj/food/baozi");

	n=new("/d/obj/food/chahu");
	
	m->set("value", 0);
	mm->set("value", 0);
	n->set("value", 0);

	m->move(this_player());
	mm->move(this_player());
	n->move(this_player());

	message_vision("��ͷ��$NЦ�������˰ɣ�����ԡ�\n", this_player());
return 1;	
}
