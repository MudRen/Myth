// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  string str;
  int i = random(5)+1;
  set_name("С��", ({"xiao yao","yao"}));
  set("gender", "����");
  set("age", 20*i);
  set("long","һ����ͷ���Ե�С����\n");
  set("combat_exp", 10000*i);
  set("per", 15);
  set_skill("parry", 20*i);
  set_skill("unarmed", 20*i);
  set_skill("dodge", 20*i);
  set_skill("blade", 20*i);
  set_skill("fork", 20*i);
  set_skill("mace", 20*i);
  set_skill("spear", 20*i);
  set_skill("sword", 20*i);
  set_skill("whip", 20*i);
  set_skill("axe", 20*i);
  set_skill("hammer", 20*i);
  set_skill("rake", 20*i);
  set_skill("stick", 20*i);
  set_skill("staff", 20*i);
  set_skill("dagger", 20*i);
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/yinwu/obj/cloth")->wear();
  str = "/d/qujing/yinwu/obj/weapon0";
  str[strlen(str)-1] = '0'+random(6);
  carry_object(str)->wield();
}
�