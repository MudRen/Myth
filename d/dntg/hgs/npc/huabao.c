inherit NPC;

void create()
{
  set_name("���", ({"hua bao","bird"}));
  set("race", "Ұ��");
  set("long","һֻ��𱣬����������֮�\n");
  set("age", 20);
  set("combat_exp", 50000);
  set("limbs", ({ "ͷ��", "����", "���", "���","�ҽ�", "β��" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
