// horse.c

inherit NPC;

void create()
{
  set_name("�����", ({"zaohong ma", "ma", "horse"}));
  set("race", "Ұ��");
  set("age", 10);
  set("combat_exp", 10000);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));
  set("ride/msg", "��");
  set("ride/dodge", 20);

  setup();
}


