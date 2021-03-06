// 玩家NPC
//by junhyun@SK

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("飞扬"NOR, ({"mya's"}));
        set("title", HIW"无底洞"HIY"轮回真魔"NOR);
        set("nickname", HIC"灭世魔尊"NOR);
        set("gender", "男性" );
      set("taskguai",1);
        set("age", 20);
        set("per", 40);
        set("str", 30);
        set("family/family_name", "闲空山无底洞");
        set("class", "yaomo");
    set("long","
蛇口站资深玩家，高手排行榜前二十名内的佼佼者，陷空山
无底洞老大。\n");

        set("attitude", "friendly");

  set("combat_exp", 100000000);
  set("daoxing", 100000000);

  set_skill("literate", 300);
  set_skill("unarmed", 300);
  set_skill("yinfeng-zhua", 300);
  set_skill("force", 300);
  set_skill("huntian-qigong", 300);
  set_skill("sword", 300);
  set_skill("qixiu-jian", 300);
  set_skill("blade", 300);
  set_skill("kugu-blade", 300);
  set_skill("parry", 300);
  set_skill("dodge", 300);
  set_skill("lingfu-steps", 300);
  set_skill("spells", 300);
  set_skill("yaofa", 300);

  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  map_skill("blade", "kugu-blade");

  set("max_sen", 7000);
  set("max_kee", 7000);
  set("force", 16000); 
  set("max_force", 8000);
  set("force_factor", 100);
  set("max_mana", 8000);
  set("mana", 16000);
  set("mana_factor", 100);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
               (: perform_action, "sword", "qijian" :), 
        }) );
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  setup();
  carry_object("/d/obj/weapon/sword/qingfeng.c")->wield();
}

