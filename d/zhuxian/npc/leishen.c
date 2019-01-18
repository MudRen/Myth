
inherit NPC;
void create()
{
  set_name("����", ({"lei shen", "leishen", "shen"}));
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
  set("force", 6000);
  set("max_force", 5000);
  set("max_mana", 8000);
  set("mana",8000);  
  set("mana_factor",500);  
  set("force_factor",200);  
  set_skill("spells", 250);
  set_skill("force", 250);
  set_skill("unarmed", 250);
  set_skill("puti-zhi", 250);
  set_skill("parry", 250);
  set_skill("wuxiangforce", 250);
  set_skill("dao", 250);
  set_skill("dodge", 2000);
  set_skill("jindouyun", 250);
  map_skill("dodge", "jindouyun");
  map_skill("unarmed", "puti-zhi");
  map_skill("spells", "dao");
  map_skill("force", "wuxiangforce");

         set("chat_chance_combat", 50);
         set("chat_msg_combat", ({
        (: cast_spell, "thunder" :),
       }));
        set_temp("apply/armor", 300);

  setup();
}

void die()
{
    object rope;
    string rp="/d/zhuxian/obj/zhuxian.c";

	rope = new(rp);
    if( environment() ) {
    message("vision", "һ����������������ʧ����Ӱ���٣���������һ����⡣\n", environment());
    }
    rope->move(environment(this_object()));
    destruct(this_object());
}
�
