#include <ansi.h>

inherit __DIR__"beast.c";

void create()
{
  set_name("��ëʨ", ({"qingmao shi", "shi"}));
  set("race", "Ұ��");
  set("age", 20);
  set("long", "һͷ��ëʨ�ӣ����ǰ���֮����\n");
  set("daoxing", 150000);
  set("combat_exp", 150000);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));
  set("attitude", "aggressive");
  set("max_kee", 800);
  set("kee", 800);
  set("max_sen", 900);
  set("sen", 900);

  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("unarmed", 150);

  set("ride/need_train", 1);
  set("ride/msg", "��");
  set("ride/dodge", 30);

  set_temp("apply/dodge", 40);
  set_temp("apply/attack", 40);
  set_temp("apply/armor", 40);

  setup();
}

