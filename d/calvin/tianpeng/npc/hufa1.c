//左护法
//by Calvin and Leox 共同开发
//版权所有,未经许可!不得翻录

inherit NPC;
#include <ansi.h>

void create()
{
          set_name("吕飞", ({"lu fei","fei","hufa","lu"}));
        set("title", "天蓬元帅府左护法");
          set("long","他是天蓬元帅府的一名出色的悍降。\n");
        set("class", "tianpeng");
        create_family("天蓬元帅府", 3, "弟子");
          set("gender", "男性");
          set("age", 50);
          set("per",30);        
          set("combat_exp", 1000000);
          set("daoxing",1000000);
          set("per", 30);
          set("str", 30);
          set("max_kee", 2000);
          set("kee",2000);
          set("force_factor",80);
          set("max_sen", 1000);
          set("sen",1000);
          set("force", 1000);
          set("max_force", 1500);
          set("max_mana", 1500);
          set("mana", 1000);
          set_skill("unarmed", 100);
          set_skill("dodge", 100);
          set_skill("force", 100);
          set_skill("parry", 100);
          set_skill("staff", 220);
          set_skill("spells", 100);
//          map_skill("spells", "buddhism");

         setup();
        carry_object("/d/qujing/liusha/obj/staff")->wield();
}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("family/family_name")=="天蓬元帅府" ){
                if( (int)ob->query("family/generation") < 2  ){
                        command("say 一边去开玩笑吧!我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣本小将了！\n");
                }
                else if( (int)ob->query("family/generation") ==3  ){
                        command("blush ");
                        command("say 你这个" + RANK_D->query_rude(ob) + "，那好吧,但是要知理既来之则安之...\n");
                        command("recruit " + ob->query("id") );
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 500000 ){
                                command(":) ");
                                command("say 好，" + RANK_D->query_respect(ob) + "既然到我门下就得给我争气，可不许偷懒！\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say 你还是先找其他弟子练着吧。\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say 这位" + RANK_D->query_respect(ob) + "，你还是找其他弟子先练练吧。\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianpeng");
}
