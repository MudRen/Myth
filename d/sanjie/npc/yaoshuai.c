// yaoshuai.c 妖帅

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"妖帅"NOR, ({"yao shuai", "yao"}));
       set("long", "大天妖唯一传人，麾下有九大高手。\n");
       set("title", HIC"天妖宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 50);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "弟子");
       set("max_kee", 1500);
       set("max_gin", 100);
       set("max_sen", 1500);
       set("force", 1800);
       set("max_force", 1800);
       set("force_factor", 180);
       set("max_mana", 1800);
       set("mana", 1800);
       set("mana_factor", 180);
       set("combat_exp", 1700000);
       set("daoxing", 2100000);

        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("spells", 120);  
        set_skill("tianmogong", 120);
        set_skill("literate", 120);
        set_skill("stick", 120);  
        set_skill("tianyaofa", 120);
        set_skill("zhaoyangbu", 120);
        set_skill("force", 120);   
        set_skill("huntianforce", 120);
        
        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("stick", "tianyaofa");
        map_skill("parry", "tianyaofa");
        map_skill("dodge", "zhaoyangbu");

        create_family("三界山", 2, "蓝");

	set("inquiry", ([
	"name"     : "我是妖帅，大天妖传人。\n",
	"here"     : "这里是天妖宫。\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/bintiegun")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="三界山") {
	if ((int)ob->query("daoxing") < 100000 ) {
  	command("say 你的道行还不够，" + RANK_D->query_respect(ob) + "还需多加努力。\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say 这位" + RANK_D->query_respect(ob) + "你曾背我派，我不原再收你为徒了！\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 25) {
	command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("tianyaofa", 1) < 80 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "对我天妖屠神法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

�
