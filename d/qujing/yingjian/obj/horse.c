//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;


void create()
{
  set_name("������", ({"bailong ma", "horse"}));
  set("race", "Ұ��");
  set("age", 10);

  set("combat_exp", 200000);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);

  set("ride/msg", "����");
  set("ride/dodge", 10+random(10));
  set_temp("apply/attack", 40);
  set_temp("apply/armor", 40);

  setup();
}

