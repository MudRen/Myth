// by snowcat on 11/5/1997 
inherit NPC;

void create()
{
  set_name("ɽ��", ({ "shan ji", "ji" }) );
  set("race", "Ұ��");
  set("age", 20);
  set("per", 20);
  set("long", "һֻ�ɾ���ĸ��ɽ����\n");
  set("attitude", "friendly");
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("limbs", ({ "ͷ��", "����", "β��" }) );
  set("verbs", ({ "bite"}) );

  setup();
}

