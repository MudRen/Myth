#include <ansi.h>

inherit NPC;

void create()
{
  set_name("���", ({ "chai guan", "guan" }) );
  set("gender", "����");
  set("age", 40);
  set("combat_exp", 20000+random(5000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 400);
  set("max_gin", 400);
  set("force", 400);
  set("max_force", 400);
  set("force_factor", random(30)+15);
  set_skill("unarmed", 40);
  set_skill("parry", 40);
  set_skill("dodge", 40);
  set_skill("blade", 40);

  setup();

  carry_object("/d/obj/cloth/choupao")->wear();
}

