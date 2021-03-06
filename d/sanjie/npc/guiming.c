// guiming.c 鬼冥

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"鬼冥"NOR, ({"master guiming", "master"}));
       set("long", "是鬼幽师弟，不过他勤于练功，功夫比他师弟强多了。\n");
       set("title", HIC"藏尸地"NOR);
       set("per", 40);
       set("gender", "男性");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "鬼王");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 300);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 270);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 160);
        set_skill("parry", 200);  
        set_skill("tianmogong", 160);
        set_skill("literate", 200);
        set_skill("unarmed", 200);  
        set_skill("liushenjue", 200);
        set_skill("zhaoyangbu", 160);
        set_skill("force", 200);   
        set_skill("huntianforce", 200);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "liushenjue");
        map_skill("dodge", "zhaoyangbu");
        
        set("chat_msg_combat", ({
		(: cast_spell, "zhui" :),
        }) );

	create_family("三界山", 1, "蓝");
	
	set("inquiry", ([
	"name"     : "老夫乃鬼冥，鬼幽师弟。\n",
	"here"     : "此乃藏尸地，没有其他事情别乱跑。\n",
	]));
	
	set("time", 1);
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="三界山") {
	if ((int)ob->query("daoxing") < 500000 ) {
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
	if( (int)ob->query_skill("huntianforce", 1) < 100 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "对混天宝鉴领会还不够深，现在收你也是勉为其难，不如作罢！\n");
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
