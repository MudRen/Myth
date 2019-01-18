
inherit F_VENDOR_SALE;
int ask_heal();
string ask_job();

void create()
{
        reload("city_yanglangzhong");
        set_name("������", ({"yang langzhong", "yang", "boss"}));
        set("title", "ҩ���ƹ�");
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
//      set("env/wimpy", 50);

        set("inquiry", ([
        "����": (: ask_heal :),
        "����": (: ask_heal :),
        "heal": (: ask_heal :),
        "job" : (: ask_job :),
        "����": (: ask_job :),
        ]) );

        set("vendor_goods", ([
                "yao": "/d/obj/drug/jinchuang",
                "dan": "/d/obj/drug/hunyuandan",
                "yanlei": "/d/obj/drug/yanlei",
                "tao" : "/d/obj/drug/mihoutao",
                "wan" : "/d/wizz/junhyun/obj/wan",
        ]) );

        set_skill("literate", 120);
        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        (: command("say ���ʱ���ܸо��Լ����ˣ��ɻ��������ġ�����Ҫ���˰���ĥҩ���У�\n") :),
        (: command("say ������С���Ӹɻͦ�����ģ����ǳ���������ǰ��,�����϶������ˣ�\n") :),
         }) );
    
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("silver", 30);
}

int ask_heal()
{
        object ob;
        ob=this_player();
        if ((int)ob->query("mud_age")>800000 )
        {
        command("say ��Ӧ���Լ�ȥ��ҽ��ѧ������Լ����Լ�Ū�ˣ�\n");
        return 1;
        }
        
       
        if ((int)ob->query("eff_kee") == (int)ob->query("max_kee")
                && (int)ob->query("eff_sen") == (int)ob->query("max_sen"))
        {
                command("?"+ob->query("id"));     
                  command("say �����û���ˣ������������ң�\n");
                command("knock"+ob->query("id"));
                return 1;
        }
        else
        {
                message_vision("���ƹ��ó�һ��������������$N���˵Ĳ�λ������Ѩ����$N�о�������ˡ�\n", ob);
                remove_call_out("recover");
                call_out("recover",2,ob);
                return 1;
        }
        }
        
int recover(object ob)
{
        if (!objectp(ob)) return 0; // mudring Dec/10/2002
        ob->set("eff_kee", (int)ob->query("max_kee"));
        ob->set("eff_sen", (int)ob->query("max_sen"));  
        message_vision("һ����Ĺ����ȥ�ˣ�����������Ѿ�����Ȭ���ˡ�\n",ob);
        command("say �����ն�,��С�ĵĻ����´����û��ô�����ˡ�\n");
        command("pat"+ob->query("id"));
        return 1;
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


string ask_job()
{
        object ob;
        ob=this_player();
        if (ob->query("combat_exp")<100000)
                return "�ҵĹ��������ڻ������˰ɣ�";
        if (ob->query("combat_exp")>180000)
                return "����ı����Ѿ����������⹤���ˣ�";
        if (ob->query("job_moyao") >0)
                return "�ҽ�����������㻹û���أ�";
        ob->set("job_moyao",1);
                return "�ðɣ���Ͱ���ĥҩ(moyao)�ɣ�";
}

