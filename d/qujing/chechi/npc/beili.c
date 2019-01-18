// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  string dir;

  set_name("��������", ({"beili daxian", "daxian"}));
  set("gender", "����");
  set("age", 40);
  set("attitude", "peaceful");
  set("combat_exp", 5100000);
  set("daoxing", 3000000);

  set_skill("dodge", 290);
  set_skill("parry", 290);
  set_skill("force", 290);
  set_skill("spells", 290);
  set_skill("unarmed", 290);
  set_skill("gouhunshu", 290);
  set_skill("tonsillit", 290);
  set_skill("ghost-steps", 290);
  set_skill("jienan-zhi", 290);
  set("con", 70);
  set("cor", 70);
  set("int", 70);
  set("per", 70);
  set("spi", 70);
  set("cps", 70);
  //map_skill("dodge", "ghost-steps");
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");

  set("eff_dx",-300000);
  set("nkgain",400);

  set("max_gin", 3200);
  set("max_kee", 3200);
  set("max_sen", 3200);
  set("force", 3200);
  set("max_force", 3200);
  set("mana", 3200);
  set("max_mana", 3200);
  set("force_factor", 15);
  set("mana_factor", 80);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void unconcious()
{
  object bone = new ("/d/obj/misc/bone");

  bone->move(environment(this_object()));
  message_vision ("\n$N����һ��̱�ڵ��ϣ�����һ����ɢ���޹ǡ�\n",
                  this_object());
  destruct(this_object());
}

void die()
{
  object bone = new ("/d/obj/misc/bone");

  bone->move(environment(this_object()));
  message_vision ("\n$N����һ��̱�ڵ��ϣ�����һ����ɢ���޹ǡ�\n",
                  this_object());
  destruct(this_object());
}

�