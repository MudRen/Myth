// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/animal.c

inherit NPC;

string *names = ({
  "С����",
  "СҰ��",
  "СҰè",
  "С���",
});

string *ids = ({
  "xiao songsu",
  "xiao yetu",
  "xiao yemao",
  "xiao ciwei",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("race", "Ұ��");
  set("age", 6);
  set("str", 30);
  set("cor", 26); 
  set("combat_exp",50);
  set_skill("dodge",20);
  set_skill("unarmed",10);
  set("limbs", ({ "ͷ��", "����", "ǰצ", "���", "β��" }) );
  set("verbs", ({ "bite", "claw" }) );
  setup();
}
