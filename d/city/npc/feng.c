//last by koker@sjsh2 20020705
//只有在丰老板这打工10次以上才能给你推荐信。

inherit NPC;

string give_xina(object me);
int do_yes(string arg);
void create()
{
        set_name("丰永贵", ({"feng yonggui", "feng", "boss"}));
        set("title", "粮店掌柜");
        set("gender", "男性");
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
        "经商" : (: give_xina :),
        ]) );

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();

        add_money("silver", 10);
}

string give_xina(object me)
{
        me=this_player();
        me->set_temp("need_xina", 1);
        return "好样的，有志气。不过我得提醒你商途坎坷啊，你真的愿意(yes)？\n";
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
                message_vision("$N答道：是的，我愿意！\n\n", me);
                if( me->query("work",1) > 10 )
                {
message_vision("丰老板说道：好！我和各地的商会都很熟悉，我可以给你写一封推荐信，祝你早日成功。\n", me);
                        me->set_temp("need_xina", 0);
                        carry_object("/d/obj/misc/xina");
                        command("give shanghui xin to " + me->query("id"));
                        
                }
                return 1;
        }
//        command();
        return 0; 
}



