// by snowcat oct 15 1997

inherit NPC;

void create()
{
  set_name("��С��", ({"wang xiaoer", "wang", "xiaoer", "xiao", "er"}));
  set("gender", "����");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

