// long7.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("���",({"gong fu","gong","fu","long","gongfu","dragon"}));
  set("long","�������Ӳ��������������ã�����˵����ӣ�ƽ����ˮ��\n");
  set("gender", "����");
  set("age", 41);
  set("title", "��������֮");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 1000);
  set("force", 1000);
  set("max_force", 1000);
  set("force_factor", 70);
  set("max_mana", 900);
  set("mana", 900);
  set("mana_factor",40);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  set_skill("unarmed",140);
  set_skill("dodge", 140);
  set_skill("force", 140);
  set_skill("parry", 140);
  set_skill("stick", 120);
  set_skill("spells", 130);
  set_skill("seashentong", 130);
  set_skill("dragonfight", 100);
  set_skill("dragonforce", 130);
  set_skill("kusang-bang", 150);
  set_skill("dragonstep", 150);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("stick","kusang-bang");
  map_skill("parry", "kusang-bang");
  map_skill("dodge", "dragonstep");

        set("nkgain", 400);

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/sea/obj/dragonstick")->wield();
  carry_object("/d/sea/obj/longzhu7");
}

int accept_fight(object me)
{
  command("say ½����˵�����򲻹��㣬ˮ������ҵ������ˣ�");
  return 1;
}








