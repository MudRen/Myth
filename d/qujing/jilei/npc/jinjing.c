//Cracked by Roath

inherit NPC;

void create()
{
  set_name("��ˮ����", ({"jinjing shou", "shou"}));
  set("under_water",1);

  set("long", "һͷ˫���Ź⣬�����񰰵Ľ��ޣ������뺣������ƽ�ء�\n");
  set("race", "Ұ��");
  set("age", 10);
  set("age", 30);
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));
  set("ride/msg", "��");
  set("ride/dodge", 35);
  set_temp("apply/attack", 80);
  set_temp("apply/armor", 80);

  setup();
}

�
