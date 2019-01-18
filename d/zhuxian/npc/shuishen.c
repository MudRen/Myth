
inherit NPC;
void create()
{
  set_name("ˮ��", ({"shui shen", "shuishen", "shen"}));
  set("gender", "����");
  set("attitude", "friendly");
  set("combat_exp", 20000000);
  set("daoxing", 30000000);

  set("age", 100);
  set("per", 100);
  set("str", 30);
  set("int", 30);
  set("cor", 30);
  set("cps", 30);
  set("con", 30);
  set("max_kee", 10000);
  set("max_sen", 10000);
  set("force", 5000);
  set("max_force", 5000);
  set("max_mana", 10000);
  set("mana",10000);  
  set("mana_factor",500);  
  set("force_factor",200);  
  set_skill("spells", 250);
  set_skill("force", 250);
  set_skill("unarmed", 250);
  set_skill("dragonfight", 250);
  set_skill("parry", 250);
  set_skill("dragonforce", 250);
  set_skill("seashentong", 250);
  set_skill("dodge", 250);
  set_skill("dragonstep", 250);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("spells", "seashentong");
  map_skill("force", "dragonforce");

         set("chat_chance_combat", 50);
         set("chat_msg_combat", ({
        (: cast_spell, "water" :),
       }));
        set_temp("apply/armor", 300);

  setup();
}

void die()
{
    object rope;
    string rp="/d/zhuxian/obj/juexian.c";

	rope = new(rp);
    if( environment() ) {
    message("vision", "ˮ�����˾������ˮ�����ˣ���æ�е���һ��������\n", environment());
    }
    rope->move(environment(this_object()));
    destruct(this_object());
}
�
