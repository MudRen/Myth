// ������ by Calvin

inherit F_VENDOR_SALE;
void create()
{
    reload("lanling_shudian_boss");
       set_name("����", ({"bo cai","boss"}));
       set("long",
"һλһ���˲ŵ��ѵ�����,�治֪��Ϊ�γ��̣���
\n");

       set("gender", "����");
        set("title", "��Ԩ���ĲŻ�");
        set("combat_exp", 10000);
       set("age", 28);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 100);
        set_skill("dodge", 100);
       set("vendor_goods", ([
               "nverbook": "/d/obj/book/girlbook",
               "pafa": "/d/calvin/book/rake",
               "quanjing": "/d/obj/book/quanjing",
               "gedou": "/d/obj/book/parry_book",
               "taibai": "/d/obj/book/poem",
               "jianfa": "/d/obj/book/jianpu",
               "sanzi": "/d/obj/book/san",
               "butou": "/d/obj/book/stickbook",
               "book": "/d/obj/book/nowords",
               "daode": "/d/obj/book/daode",
               "quanfa": "/d/obj/book/basic_unarmed",
               "daofa": "/d/obj/book/basic_blade",
               "xyj": "/d/obj/books-nonskill/xyjbook",
               "taibai": "/d/obj/book/poem",
               "qiangfa": "/d/obj/book/spearbook",
               "jingangjing": "/d/obj/book/jingang",
               "zhangfa": "/d/obj/book/staffbook",
               "chunyang": "/d/obj/book/chunyang",
       ]) );
        setup();
       add_money("silver", 5);
        carry_object("/d/obj/armor/��������")->wear();
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
                        say(name()+ "��ɭɭ���ߵ��������λ" +RANK_D->query_respect(ob)                                + "����ҪЩ�ö�����?\n");
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

message_vision("\n��Ȼ��Զ���ܹ�����Ѳ�߹ٱ�����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);  

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
