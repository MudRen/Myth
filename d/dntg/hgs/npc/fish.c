inherit NPC;

void create()
{
  set_name("���", ({"fish","yu"}));
  set("race", "Ұ��");
  set("long","һ�������۵�����������㣬β�Ͳ��죻�����㣬���۲�����\n�ƺ��㣬ͷ�����ǣ������㣬�������롣\n");
  set("age", 20);
  set("combat_exp", 50000);
  set("limbs", ({ "ͷ��", "����", "β��" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
