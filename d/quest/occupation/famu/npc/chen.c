// Created by kuku@sjsh 2003.2
// 职业任务npc （伐木工）

#include <ansi.h>
inherit NPC;
int give_work();

string *wood1=({"/d/quest/occupation/famu/material/rawredwood","/d/quest/occupation/famu/material/rawfirwood"});
string *wood2=({"/d/quest/occupation/famu/material/rawredwood","/d/quest/occupation/famu/material/rawfirwood","/d/quest/occupation/famu/material/rawpinewood"});
string *wood3=({"/d/quest/occupation/famu/material/rawredwood","/d/quest/occupation/famu/material/rawfirwood","/d/quest/occupation/famu/material/rawpinewood","/d/quest/occupation/famu/material/rawrubberwood"});
string *wood4=({"/d/quest/occupation/famu/material/rawredwood","/d/quest/occupation/famu/material/rawfirwood","/d/quest/occupation/famu/material/rawpinewood","/d/quest/occupation/famu/material/rawrubberwood","/d/quest/occupation/famu/material/rawnanwood"});
string *wood5=({"/d/quest/occupation/famu/material/rawredwood","/d/quest/occupation/famu/material/rawfirwood","/d/quest/occupation/famu/material/rawpinewood","/d/quest/occupation/famu/material/rawrubberwood","/d/quest/occupation/famu/material/rawnanwood","/d/quest/occupation/famu/material/rawcamphorwood"});
string *wood6=({"/d/quest/occupation/famu/material/rawredwood","/d/quest/occupation/famu/material/rawfirwood","/d/quest/occupation/famu/material/rawpinewood","/d/quest/occupation/famu/material/rawrubberwood","/d/quest/occupation/famu/material/rawnanwood","/d/quest/occupation/famu/material/rawcamphorwood","/d/quest/occupation/famu/material/rawpomelowood"});

void create()
{
        set_name("陈亦飞",({"chen yifei","jiangong","chen"}));
        set("gender","男性");
        set("nickname","监工");
        set("age",40+random(40));
        set("combat_exp",30000+random(400000));
        set("str",45);
        set("per",16);
        set("inquiry",([    
                "work":(:give_work:),
                "job":(:give_work:),
                "工作":(:give_work:),
        ]));
        set_skill("unarmed",115);
        set_skill("parry",115);
        set_skill("dodge",115);
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{  
        object ob;
        ::init();
        if (interactive(ob=this_player()) && !is_fighting()){   
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
        add_action("do_say","say");
}

void greeting(object ob)
{   
        if(!ob || environment(ob)!= environment()) return;
        if (ob->query_temp("work/kan")==1) return;
        if (ob->query_temp("work/kan")==2){    
                command("say 啊,"+ob->query("name")+"已经干完了，请用(say 干完了).\n");
                return;
        }     
        command("say 这位"+RANK_D->query_respect(ob)+"是要找工作么，请用(ask chen about work)。\n");
        return;
}

int give_work()
{
        object me;
        me=this_player();
        if (!me || environment(me)!= environment()) return 0;

        if (me->query("combat_exp")<500000){    
                command("say 经验不够，练练再来吧。\n");
                return 1;
        }

        if (me->query_temp("work/kan")==1){    
                command("say 你刚才的活还没干完吧!\n");
                return 1;
        }
        
        if (me->query_temp("work/kan")==2){    
                command("say 干完活应该先汇报(say 干完了)!\n");
                return 1;
        }
        
        if (!me->query("occupation")|| me->query("occupation") != "伐木工"){ 
                command("say 只有伐木工才能完成我分配的工作!\n");
                return 1;
        }
        
        command("say 好!你这就到松林去伐木吧!\n");
        me->set_temp("work/kan",1);
        return 1;
}

int do_say(string str)
{   
        object ob,ob1;
        ob=this_player();
        if (!str || str!="干完了") return 0;
        
        if (ob->query_temp("work/kan")!=2){
                command("hmm");
                command("say 想骗我啊？哼!\n");
                return 1;
        }
        
        command("say 如果运气好，你的伐木经验会增加喔，继续努力吧！\n");
        ob->delete_temp("work/kan");
        if (random(10)>7){
                ob->add("work/famu",1);
        }
        
        if ((int)ob->query("work/famu") > 60000 ){
                message_vision(HIR"辛勤的劳动终于有所收获，为了奖励$N，$n给了$N一根上好的原木。\n"NOR,ob,this_object()); 
                ob1=new(wood6[random(7)]);
                ob1->move(ob);
                ob1->set_temp("famu/owned",7); 
                return 1;
        }
        else if ((int)ob->query("work/famu") > 50000 ){
                message_vision(HIR"辛勤的劳动终于有所收获，为了奖励$N，$n给了$N一根上好的原木。\n"NOR,ob,this_object()); 
                ob1=new(wood5[random(6)]);
                ob1->move(ob);
                ob1->set_temp("famu/owned",6);     
                return 1;
        }
        else if ((int)ob->query("work/famu") > 40000 ){
                message_vision(HIR"辛勤的劳动终于有所收获，为了奖励$N，$n给了$N一根好原木。\n"NOR,ob,this_object()); 
                ob1=new(wood4[random(5)]);
                ob1->move(ob);
                ob1->set_temp("famu/owned",5); 
                return 1;
        }       
        else if ((int)ob->query("work/famu") > 30000 ){
                message_vision(HIR"辛勤的劳动终于有所收获，为了奖励$N，$n给了$N一根好原木。\n"NOR,ob,this_object()); 
                ob1=new(wood3[random(4)]);
                ob1->move(ob);
                ob1->set_temp("famu/owned",4); 
                return 1;
        }
        else if ((int)ob->query("work/famu") > 20000 ){
                message_vision(HIR"辛勤的劳动终于有所收获，为了奖励$N，$n给了$N一根一般的原木。\n"NOR,ob,this_object()); 
                ob1=new(wood2[random(3)]);
                ob1->move(ob);
                ob1->set_temp("famu/owned",3); 
                return 1;
        }
        else if ((int)ob->query("work/famu") > 10000 ){
                message_vision(HIR"辛勤的劳动终于有所收获，为了奖励$N，$n给了$N一根一般的原木。\n"NOR,ob,this_object());     
                ob1=new(wood1[random(2)]);
                ob1->move(ob); 
                ob1->set_temp("famu/owned",2); 
                return 1;
        }
        else{ 
                message_vision(HIR"辛勤的劳动终于有所收获，为了奖励$N，$n给了$N一根原木。\n"NOR,ob,this_object());
                ob1 = new( "/d/quest/occupation/famu/material/rawredwood");
                ob1->move(ob);       
                ob1->set_temp("famu/owned",1); 
        }
        return 1;
} 
