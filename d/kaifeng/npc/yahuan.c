// yahuan1.c

inherit NPC;

void create()
{
  set_name("Ѿ��", ({"ya huan"}));
  set("long","һ��������Ѿ����\n");
  set("gender", "Ů��");
  set("age", 14);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("combat_exp",600);
  setup();
  carry_object("/d/obj/cloth/pink_cloth")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}


