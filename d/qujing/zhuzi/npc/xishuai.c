// by snowcat on 11/5/1997 
inherit NPC;

void create()
{
  set_name("��", ({ "xishuai" }) );
  set("race", "Ұ��");
  set("age", 5);
  set("per", 30);
  set("long", "һֻ������ص��ų��Ĵ��󰡣\n");
  set("attitude", "friendly");
  set_skill("unarmed", 10);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("limbs", ({ "��ͷ", "����", "���", "�ҳ�", "�����", "�Ҵ���", "��¡��" }) );
  set("verbs", ({ "bite" }) );

  setup();
}

