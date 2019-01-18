// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/yao.c

inherit NPC;

string *names = ({
  "ѩ�ǹ�",
  "������",
  "Ұ����",
  "���⾫",
  "�ڵ��",
  "��¹��",
  "���߾�",
});

void create()
{
  int i = random(9)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"yao jing", "yao", "jing"}));
  set("gender", "����");
  set("age", 30*i);
  set("combat_exp", 30000*i);
  set("per", 10);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("fork", 10*i);
  set_skill("mace", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("rake", 10*i);
  set_skill("stick", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",10*i);
  setup();
  set("chat_chance", 5);
  set("chat_msg", ({ (: random_move :) }));
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  str = "/d/qujing/qilin/obj/weapon10";
  str[strlen(str)-1] = '0'+random(3);
  carry_object(str)->wield();
}
