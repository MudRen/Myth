inherit NPC;

void create()
{
  set_name("ˮ��", ({"shui she","she","snake"}));
  set("race", "Ұ��");
  set("long","һ��ˮ�ߣ����ڰ��ߵ�ˮ����������ȥ��\n");
  set("age", 20);
  set("combat_exp", 50000);
  set("limbs", ({ "ͷ��","�ߴ�", "����", "β��" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
