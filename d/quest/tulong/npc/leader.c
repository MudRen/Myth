inherit NPC; 
#include <ansi.h> 
void create()
{
        set_name("接引使", ({"jieyin shi", "shi", "leader"}));
        set("age", 14);
        set("attitude", "peaceful");
        set("gender", "女性");
        set("title", "精灵使");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 20);
        set("max_kee", 90000);
        set("kee", 90000);
        set("max_sen", 90000);
        set("sen", 90000);
        set("combat_exp", 101100000);

        set("force", 18000);
        set("max_force", 9000);
        set("force_factor", 10);
        set_skill("unarmed", 700);
        set_skill("force", 800);
        set_skill("dodge", 800);
        set_skill("parry", 900);
        set_skill("blade", 900);
        setup();

} 

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        } 
        add_action("do_answer", "answer");} 

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return; 
        if( this_object()->query_temp("check_answer") ) {
                command("say 请你快回答吧。");
                return;
         }        
         
        switch(random(4)) 
        {
        case 0 :
                say("接引使微笑道：这位" + RANK_D->query_respect(ob) +
                        "，请先回答我一个问题：如果你的母亲和妻子同时遇险，你会先救哪一个呢？\n");  
                this_object()->set_temp("check_answer", 1);
                call_out("say_answer", 50);
                break;  
        case 1 :
                say("接引使微笑道：这位" + RANK_D->query_respect(ob) +
                        "，请先回答我一个问题：如果你的儿子和女儿同时遇险，你会先救哪一个呢？\n");
                this_object()->set_temp("check_answer", 1);
                call_out("say_answer", 50);
                break;
        case 2 :
                say("接引使微笑道：这位" + RANK_D->query_respect(ob) +
                        "，请先回答我一个问题：如果你的妻子和朋友同时遇险，你会先救哪一个呢？\n");
                this_object()->set_temp("check_answer", 1);
                call_out("say_answer", 50);
                break;
        case 3 :
                say("接引使微笑道：这位" + RANK_D->query_respect(ob) +
                        "，请先回答我一个问题：如果你的朋友和亲属同时遇险，你会先救哪一个呢？\n");
                this_object()->set_temp("check_answer", 1);
                call_out("say_answer", 50);
                break;
        }
}

void say_answer(object who)
{
        if(!who) return;
        command("smile");
        command("say 对了，沉默才是答案！这本来是没有答案的问题，一切要视当时的情形而定。你过关了，去吧。\n");   
        this_object()->delete_temp("check_answer");     
        this_player()->move("/d/quest/tulong/spirit5");
        return ;
}
   
int do_answer(string arg)
{
        if( !(this_object()->query_temp("check_answer") ) )
                return notify_fail("什么？\n");

        if( !arg ) return notify_fail("你说什么？\n");

        message_vision("$N答道：我会先救“" + arg + "”。\n", this_player());

        if( arg == "亲属" || arg == "女儿" || arg == "儿子" || arg == "母亲" || arg == "妻子" || arg == "朋友") 
        {
        switch (random(3)) 
        {
         case 0:      
                message_vision("$N侧身让出一条路。\n", this_object());   
                this_object()->delete_temp("check_answer");
                this_player()->move("/d/quest/tulong/spirit3");
                remove_call_out("say_answer"); 
          break;
         case 1: 
                message_vision("$N侧身让出一条路。\n", this_object());   
                this_object()->delete_temp("check_answer"); 
                this_player()->move("/d/tulong/quest/spirit4");  
                remove_call_out("say_answer");
         break;
         case 2: 
                message_vision("$N侧身让出一条路。\n", this_object());   
                this_object()->delete_temp("check_answer"); 
                this_player()->move("/d/tulong/quest/spirit0");
                remove_call_out("say_answer");
         break;
             } 
        return 1;
      }
        command("say 请认真回答！\n");
        return 1;
}


