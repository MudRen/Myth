inherit NPC;

void create()
{
  set_name("��ȸ", ({"maque"}));
  set("race", "Ұ��");
  set("age", 20);
  set("long", "һֻС��ȸ���������Ҷ��ϡ�\n");
  set("combat_exp", 50000);
  set("limbs", ({ "ͷ��", "����", "���", "���","�ҽ�", "β��" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
