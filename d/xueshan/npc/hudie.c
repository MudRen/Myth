inherit NPC;


void create()
{

  set_name("����", ({"hu die","die","butterfly"}));
  set("race", "Ұ��");
  set("age", 10);
  set("long", "һֻС������\n");

  set_skill("dodge", 10);
  set("combat_exp", 100);
  set("limbs", ({ "ͷ��", "����", "ǰ��","����", "β��" }) );
  set("verbs", ({ "bite"}));

  setup();

  set("chat_msg", ({
    (: random_move :),
    }) );
  set("chat_chance", 50);
}
