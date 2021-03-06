//  北天门守护使

#include <ansi.h>
inherit NPC;


void create()
{
        set_name(HIW"守护使"NOR, ({ "shouhu shi", "shi", }));
        set("gender", "男性");
        set("title", HIG"北天门");
        set("age", random(50) + 120);
        set("str", 25);
        set("int", 60);
        set("dex", 30);
        set("per", 30);
        set("long", "这是太上老君麾下的天宫四使之一。\n");
        set("combat_exp", 80000000);
        set("daoxing", 100000000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 660);
        set_skill("wuxing-quan", 660);
        set_skill("dodge", 660);
        set_skill("baguazhen", 660);
        set_skill("parry", 660);
        set_skill("sword", 660);
        set_skill("sanqing-jian", 660);
        set_skill("staff", 660);
        set_skill("fumo-zhang", 660);
        set_skill("hammer", 660);
        set_skill("xiaofeng-sword", 660);
        set_skill("kaishan-chui", 660);
        set_skill("blade", 660);
        set_skill("yange-blade", 660);
        set_skill("force", 660);   
        set_skill("zhenyuan-force", 660);
        set_skill("literate", 660);
        set_skill("spells", 660);
        set_skill("taiyi", 660);
        map_skill("spells", "taiyi");
        map_skill("force", "zhenyuan-force");
        map_skill("unarmed", "wuxing-quan");
        map_skill("sword", "sanqing-jian");
        map_skill("dodge", "baguazhen");
        map_skill("staff", "fumo-zhang");
        map_skill("blade", "yange-blade");
        map_skill("hammer", "kaishan-chui");
        
        set("max_kee", 15000);
        set("max_sen", 15000);
        set("force", 50000);
        set("max_force", 25000);
        set("mana", 70000);
        set("max_mana", 35000);   
        set("force_factor", 200);
        set("mana_factor", 200);

        set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
        set("chat_chance_combat", 90);
        set("chat_msg_combat", 
        ({
                (: cast_spell, "zhenhuo" :),
                (: cast_spell, "qiankun" :),
                (: cast_spell, "sanqing" :),
                (: cast_spell, "wuxing" :),
                (: perform_action, "sword", "jianmang" :),
                (: perform_action, "sword", "jianzhang" :),
                (: perform_action, "sword", "wanxiang" :),
                (: perform_action, "sword", "sanlianji" :),

        }) );

        setup();
        carry_object("/d/9ct/zb/sword")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
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

        if( !ob || environment(ob) != environment() ) 
                return;
        if(ob->query_temp("start_job")==1)
        {
              say( "守护使皱了皱眉：这位" + RANK_D->query_respect(ob)
                                + "，你还是安心守护天宫吧。\n");
        }       
        else if(ob->query_temp("mark/job_shadi")==4)                        
        {
                say( "守护使拱手说道：这位" + RANK_D->query_respect(ob)
                                + "，你来得正是时候，魔界已经快攻到此地了。\n");
                ob->apply_condition("jobshadi_limit", 5+random(5));
                ob->set_temp("start_job",1);     
                ob->set_temp("where",environment(ob));
                call_out("to_rob",10,ob);
        }
        if(ob->query_temp("job_over")==1)
        {
              say( "守护使拱手说道：这位" + RANK_D->query_respect(ob)
                                + "，你已经可以回去复命了。\n");
              return;
        }                                


}

void to_rob(object ob)
{
        object *target,robber,room;
        mapping my_fam  = ob->query("family");                  
        int i;
        if (!ob) return;
        target=users();  
        room = environment(ob);
        if(ob->query_temp("start_job")==0)
        return;
        if( environment(ob)->query("short")=="北天门")
        {
                robber=new(__DIR__"robber1");
                robber->do_change(ob);
                robber->move(room);
                message_vision(HIR"突然一股黑雾袭来，妖魔现形了。\n" NOR,ob); 
                robber->kill_ob(ob);
                ob->kill_ob(robber);
        }

}


