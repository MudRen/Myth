// by snowcat on 7/5/1997 
inherit NPC;

void create()
{
  set_name("����", ({ "gong ji", "ji" }) );
  set("race", "Ұ��");
  set("gender", "����");
  set("age", 2);
  set("long", "һֻ������Ĵ󹫼���\n");
  set("attitude", "friendly");
  set_skill("unarmed", 2);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set("limbs", ({ "ͷ��", "����", "β��" }) );
  set("verbs", ({ "bite"}) );

  setup();
}

