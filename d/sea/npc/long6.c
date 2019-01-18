// long1.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("����",({"tao tie","tao","tie","long","taotie","dragon"}));
  set("long","�������Ӳ��������������ã������˵����ӣ�ƽ����ʳ��\n");
  set("gender", "����");
  set("age", 28);
  set("title", "��������֮");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1000);
  set("max_sen", 700);
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 60);
  set("max_mana", 900);
  set("mana", 900);
  set("mana_factor",30);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  set_skill("unarmed", 140);
  set_skill("dodge", 150);
  set_skill("force", 150);
  set_skill("parry", 140);
  set_skill("staff", 150);
  set_skill("spells", 120);
  set_skill("seashentong", 100);
  set_skill("dragonfight", 130);
  set_skill("dragonforce", 120);
  set_skill("lunhui-zhang", 150);
  set_skill("dragonstep", 150);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("staff","lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  map_skill("dodge", "dragonstep");

        set("nkgain", 400);

  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
    (: cast_spell, "hufa" :),
    "�����૵������ˣ����ˣ����ҵ㶫�����ˡ�\n",
  }) );

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/sea/obj/dragonstaff")->wield();
  carry_object("/d/sea/obj/longzhu6");
}

int accept_fight(object me)
{
  command("consider "+me->query("id"));
  command("jealous");
  command("grin");
  command("say �����Ҷ��ˣ��Եľ����������ˣ�");
  command("kill "+me->query("id"));
  return 1;
}








