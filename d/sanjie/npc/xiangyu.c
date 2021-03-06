// xiangyu.c 项羽

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"项羽"NOR, ({"xiang yu", "xiang"}));
       set("long", "一代枭雄，败于刘邦，心生怨恨，千年来冤魂不息。\n");
       set("title", HIC"雷刀门"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 100);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "鬼魂");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 240);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("spells", 160);  
        set_skill("tianmogong", 160);
        set_skill("literate", 160);
        set_skill("blade", 200);  
        set_skill("zileidao", 200);
        set_skill("zhaoyangbu", 160);
        set_skill("force", 160);   
        set_skill("huntianforce", 160);
        
        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("blade", "zileidao");
        map_skill("parry", "zileidao");
        map_skill("dodge", "zhaoyangbu");

	create_family("三界山", 1, "蓝");
	
	set("chat_msg_combat", ({
        (: perform_action, "blade", "tulong" :),
        }) );

	set("inquiry", ([
	"name"     : "我是项羽，当年败给刘邦，我誓要仇。\n",
	"here"     : "这里是乌江边，当年我自杀的地方。\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/leidao")->wield();
}

void attempt_apprentice(object ob, object me)
{
        command("say 很好，" + RANK_D->query_respect(ob) +"多加努力，他日帮我报仇。\n");
        command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

void xiangyu_disappear (object me)
{
  message_vision (MAG"$N慢慢地化为紫色云雾消失了。\n"NOR,me);
  destruct (me);
  return;
}

�
/*
void die()
{
         message_vision("$N死了。\n",this_object());
                 distruct(this_object());
}
*/
