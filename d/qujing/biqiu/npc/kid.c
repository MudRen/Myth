// by snowcat oct 15 1997

inherit NPC;

void create()
{
  set_name("С��", ({"xiao er","kid"}));
  set("gender", "����");
  set("combat_exp", 1);
  set("age", 2);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 1);

  setup();
}

