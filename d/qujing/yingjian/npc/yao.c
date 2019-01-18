//Cracked by Roath


inherit NPC;

void create()
{
   set_name("ˮ��", ({ "shui yao", "yao"}));
   set("gender", "����" );
   set("age", 35);
   set("long","�̾���ˮ�µ������֡�\n");
   set("max_kee",1200);
   set("max_force",1200);
   set("force",1200);
   set("force_factor", 40);
   set("max_mana",1200);
   set("mana",1200);
   set("combat_exp", 850000);
   set("attitude","aggressive");
   set_skill("unarmed", 130);
   set_skill("wuxing-quan", 130);
   set_skill("dodge", 120);
   set_skill("baguazhen", 130);
   set_skill("parry", 130);
   set_skill("hammer", 120);
   set_skill("kaishan-chui", 120);
   set_skill("force", 130);
   set_skill("zhenyuan-force", 130);
   set_skill("spells",130);
   set_skill("taiyi", 130);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("hammer", "kaishan-chui");
   map_skill("dodge", "baguazhen");
   set("chat_chance_combat", 70);
   set("chat_msg_combat", ({
     (: cast_spell, "qiankun" :),
    }) );
   setup();
   carry_object("/obj/cloth")->wear();
   carry_object("/d/qujing/village/obj/hammer")->wield();
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
