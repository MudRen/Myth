//last by koker@sjsh2 20020705
//ֻ���ڷ��ϰ����10�����ϲ��ܸ����Ƽ��š�

inherit NPC;

string give_xina(object me);
int do_yes(string arg);
void create()
{
        set_name("������", ({"feng yonggui", "feng", "boss"}));
        set("title", "�����ƹ�");
        set("gender", "����");
        set("age", 35);
        set("kee", 20000); 
        set("max_kee", 20000);
        set("combat_exp",100000);
        set("daoxing",10000);
        set("sen", 20000);
        set("max_sen", 20000);  
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 10);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);

   set("inquiry", ([
        "����" : (: give_xina :),
        ]) );

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();

        add_money("silver", 10);
}

string give_xina(object me)
{
        me=this_player();
        me->set_temp("need_xina", 1);
        return "�����ģ���־���������ҵ���������;�������������Ը��(yes)��\n";
}

void init()
{
        add_action("do_yes", "yes");
}

int do_yes(string arg)
{
        object me;

        me=this_player();
        
        if(me->query_temp("need_xina")) 
        {
                message_vision("$N������ǵģ���Ը�⣡\n\n", me);
                if( me->query("work",1) > 10 )
                {
message_vision("���ϰ�˵�����ã��Һ͸��ص��̻ᶼ����Ϥ���ҿ��Ը���дһ���Ƽ��ţ�ף�����ճɹ���\n", me);
                        me->set_temp("need_xina", 0);
                        carry_object("/d/obj/misc/xina");
                        command("give shanghui xin to " + me->query("id"));
                        
                }
                return 1;
        }
//        command();
        return 0; 
}



