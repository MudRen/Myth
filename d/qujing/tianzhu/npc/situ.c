// by snowcat 12/8/1997

inherit NPC;

void create()
{
  set_name("˾ͽ����", ({"situ jinbao", "situ", "jinbao"}));
  set("gender", "����");
  set("combat_exp", 80000);
  set("age", 48);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
  carry_object("/d/qujing/tianzhu/obj/baijie")->wear();
}


