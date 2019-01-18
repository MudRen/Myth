inherit NPC;

string *names = ({
  "������",
  "������",
  "������",
  "������",
  "������",
  "׷����",
  "������",
  "������",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"horse", "ma"}));
  set("race", "Ұ��");
  set("age", 20);
  set("long", "һƥ�����Ƽ��������\n");
  set("combat_exp", 50000);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("unarmed", 100);
  set("ride/msg", "��");
  set("ride/dodge", 20+random(6));
  set_temp("apply/dodge", 40);
  set_temp("apply/attack", 40);
  set_temp("apply/armor", 40);

  setup();
}

