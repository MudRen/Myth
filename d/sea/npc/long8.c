// long8.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("���",({"jin ni","jin","ni","long","jinni","dragon"}));
  set("long","�������Ӳ��������������ã�����˵ڰ��ӣ�ƽ�����̻�\n");
  set("gender", "����");
  set("age", 22);
  set("title", "��������֮");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 800);
  set("force_factor", 90);
  set("force", 1200);
  set("max_force", 1200);
  set("max_mana", 900);
  set("mana", 900);
  set("mana_factor",50);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  set_skill("unarmed", 140);
  set_skill("dodge", 150);
  set_skill("force", 140);
  set_skill("parry", 150);
  set_skill("whip", 150);
  set_skill("spells", 120);
  set_skill("seashentong", 100);
  set_skill("dragonfight", 140);
  set_skill("dragonforce", 140);
  set_skill("hellfire-whip", 150);
  set_skill("dragonstep", 150);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("whip","hellfire-whip");
  map_skill("parry", "hellfire-whip");
  map_skill("dodge", "dragonstep");

        set("nkgain", 400);

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/sea/obj/dragonwhip")->wield();
  carry_object("/d/sea/obj/longzhu8");
}






