inherit F_VENDOR_SALE;
void create()
{
    reload("liuyuntian");
        set_name("������", ({"liu yuntian", "liu"}));
        set("age", 22);
        set("gender", "����");
        set("long",
"���ǲ�ׯ���ٶ��ң�Ҳ��������Ϊ��һ��������������ӡ�\n");
	set("title", "���ǲ�ׯ����");
        set("attitude", "friendly");
        set("combat_exp", 20000);
        set("shen_type", 1);
	set("max_force", 400);
	set("force", 400);
	set("force_factor", 10);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set("vendor_goods", ([
                "boots": "/d/obj/cloth/huazheboots",
		"jin": "/d/obj/cloth/wulingjin",
                "shoes": "/d/obj/cloth/bullboots", 
                "choupao": "/d/obj/cloth/choupao", 
        ]) );
        setup();
	add_money("silver", random(5));
	carry_object("/d/obj/cloth/choupao")->wear();
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
                        say(name()+ "Ц���е�ӭ��������λ" + RANK_D->query_respect(ob) + "��Ҫ��Щʲô������\n");
                        break;
        }
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n��Ȼ������������Ѳ�߹ٱ�����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

