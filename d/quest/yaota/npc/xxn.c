//  /d/quest/yaota/npc/xxn.c
      
inherit NPC; 
#include <ansi.h> 
 
int ask_yaota ();  
void create() 
{ 
         set_name( HIY "小仙女" NOR, ({"xiao xiannv","xiannv"})); 
        set("title",HIR+"授命除妖"+NOR);  
        set("long", "她是一个外表弱不禁风，内心刚强正直的芊芊女子，受天命下凡寻找能够除妖降魔的仁人志士。\n");  
        set("gender", "女性");  
        set("attitude", "peaceful"); 
        set("class", "xian"); 
        set("age", 16); 
        set("str", 40+random(10)); 
        set("int", 30); 
        set("per", 30+random(4)); 
        set("con", 20); 
        set("max_kee", 50000);    
        set("max_sen", 50000);     
        set("kee", 50000);   
        set("sen", 50000);    
        set("max_force", 30000);   
        set("force", 30000);  
        set("force_factor", 450);  
        set("max_mana", 30000);   
        set("mana", 30000);   
        set("mana_factor", 450);  
        set("combat_exp", 15000000);   
        set("daoxing", 15000000);   
    
        set_skill("unarmed", 600);  
        set_skill("force", 600);  
        set_skill("dodge", 600);  
        set_skill("parry", 600);  
        set_skill("spells", 600);  
        set_skill("sword", 600);  
        set_skill("snowsword",600);  
        set_skill("moonforce",600);  
        set_skill("moonshentong",600);  
        set_skill("moondance",600);  
        set_skill("baihua-zhang",600); 
        map_skill("dodge","moondance");  
        map_skill("unarmed","baihua-zhang");  
        map_skill("force","moonforce");  
        map_skill("spells","moonshentong");  
        map_skill("sword","snowsword");  
        map_skill("parry","snowsword");   
        set("chat_chance_combat", 60);  
        set("chat_msg_combat", ({ 
                (: exert_function, "recover" :),  
                (: perform_action, "sword", "hanyue" :),  
                (: perform_action, "sword", "tian" :),  
          }) );  
         
          set("inquiry", ([ 
            "降妖" : (: ask_yaota :),  
          ]) ); 
          setup(); 
         
          carry_object("/d/obj/cloth/nichang")->wear();   
          carry_object("/d/obj/cloth/huazheboots")->wear();
          carry_object("/d/obj/weapon/sword/qinghong")->wield();   
} 
             
int ask_yaota () 
{ 
         int tt; 
        object me=this_player();
        object ob=this_object();
        if( (tt=(int)me->query("yaota/job_start")) && me->query("yaota/done")=="done") { 
        // job done 
                if(tt<=time() && time()<tt+900) { 
                        message_vision("\n"+ob->query("name")+"说道:任务已经完成，你还是等等再来。\n",me); 
                        return 1; 
                } 
        } 
        if( me->query("yaota/fail") ) { 
                if(tt<=time() && time()<tt+900) { 
                        message_vision("\n"+ob->query("name")+"说道：你任务失败了，等等再来吧。\n",me); 
                        return 1; 
                } 
                me->delete("yaota/fail");   
        } 
        if(me->query("combat_exp")<8000000 || me->query("daoxing")<8000000){  
                command("say 以你现在的修为去降妖太危险了，还是好好练练再来吧。\n");  
                command("pat " +me->query("id"));  
                return 1;
        } 
        if(me->query("yaotapass")>=3 ){  
                command("say 你已经完成了分内的事情，不用再去了。\n");  
                command("thank " +me->query("id")); 
                return 1;
        } 
        else {
                command("say 去那里凶多吉少啊，你有心帮我降妖除魔，这是上天助我呀，如果你完成了任务，我会好好答谢你的，我这就送你到妖怪肆虐的"+HIB"妖塔"NOR+"，你要小心才是，祝你好运！\n");    
                tell_room(environment(me),HIW"\n突然一朵五彩祥云从天边飘来，把"+me->query("name")+"轻轻托起，不消一刻就消失的无影无踪。\n"NOR);
                me->move("/d/quest/yaota/gate");
                me->delete("yaota/job_start"); 
                me->set("yaota/job_start",time()); 
                me->delete("yaota/done");
        }
        return 1; 
} 

int accept_fight(object ob) 
{ 
         object me = this_object();  
         object who = this_player();  
         if(me->is_fighting() )  
                 return notify_fail(HIY"小仙女"NOR+"对你说：没见我正忙着呢么？\n"); 
         if( (int)me->query("kee")*100/(int)me->query("max_kee") < 60 )  
                 return notify_fail(HIY"小仙女"NOR+"对你说：本姑娘身体不适，不和人打架！\n"); 
         command("hmm");  
         command("say 和为贵，不要动不动就打架喔...\n");  
         return 0;  
} 
