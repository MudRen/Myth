 // d/wizz/mudring/npc/shinv.c ʹŮ

inherit NPC;

void create()
{
        set_name("�ϰ�", ({"shi nv"}) );
        set("nickname", "�ư��ϰ�");
        set("gender", "Ů��" );
        set("age", 12+random(6));
        set("long",
          "���Ǹ���ޢ������С���һ��һ����͸���ഺ����Ϣ��\n"
          "�ֽ��ڿ죬����ϲ������������΢ʾ�⣬���ȥ�����ͳԵġ�\n");
        set("attitude", "friendly");
    set("shen_type", 1);

        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

        set("combat_exp", 1000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

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
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        say("ʹŮЦ������˵������λ" + RANK_D->query_respect(ob)
             + "����������" + "����͸������ơ�\n");
}


void serve_tea(object who)
{
        object obt, obc, obn;
        object room;

        if( !who || environment(who) != environment() ) return;

        if( !who->query_temp("marks/sit") ) return;
        
        if( !objectp(room = environment()) ) return;

        if ( (int)who->query_temp("tea_cup") <= 0 )
        {
                obn = new("/d/wizz/mudring/obj/wine");
                obn->move(who);
                message_vision("ʹŮ�ó����ֵ������󣬿�ʼ��Ū������\n",
                        who);
        } else 
        {
                who->add_temp("tea_cup", -1);
                obn = new("/d/wizz/mudring/obj/wine");
                obn->move(who);
                message_vision("ʹŮ�ǳ����µ�����С�Ʊ������˱��þƣ��������ϣ�\n",
                        who);
        }

        obn = new("/d/wizz/mudring/obj/wine");
        obn->move(who);
        message_vision("ʹŮ�ó�һ���ѩ�⣬�������ϣ�\n", who);
        
        return;
}

