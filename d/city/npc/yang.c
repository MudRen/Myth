inherit F_VENDOR_SALE;

string heal_me(object me);

void create()
{
	reload("yangzhongshun");
        set_name("������", ({"yang langzhong", "yang", "boss"}));
        set("title", "ʥ�ֻش�");
        set("gender", "����");
        set("age", 37);
        set("long",
"�������ǳ��������洫����ҽ����Ȼ���ᣬȴ�����������⡣\n");
        set("kee", 900); 
        set("max_kee", 900);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set("inquiry", ([
                "����": (: heal_me :),
                "����": (: heal_me :),
                "��ҩ": (: heal_me :),
        ]) );

        set("vendor_goods", ([
                "taogan": "/d/obj/drug/fake-tao",
                "yao": "/d/obj/drug/jinchuang",
                "dan": "/d/obj/drug/hunyuandan",
                  "yanlei": "/d/obj/drug/yanlei",
        ]) );

        set_skill("literate", 70);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("silver", 50);
}


string heal_me(object ob)
{
        int ratio;
        object me;
        me = this_player();
        ratio = (int)me->query("eff_kee") * 100 /
(int)me->query("max_kee");
        if( ratio >= 100 )
                return "��λ" + RANK_D->query_respect(me) +
"������������ɫ�ܺð������������˵����ӡ�";
        if( ratio >= 95 )
                return
"Ŷ....�ҿ���....ֻ��ЩƤ��С�ˣ��������ҩ��ȥ����û���ˡ�";

}



void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");


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

