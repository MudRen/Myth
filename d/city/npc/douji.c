// by snowcat on 7/5/1997 
inherit NPC;

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

void create()
{
  set_name("����", ({ "dou ji", "ji" }) );
  set("race", "Ұ��");
  set("gender", "����");
  set("age", 2);
  set("long", "һֻ������Ķ�����\n");
  set("attitude", "friendly");
  set("max_kee",400+random2(2)*100);
  set("max_sen",400+random2(2));
  set("str", 40+random2(2));
  set("spi", 40+random2(2));
  set("cor", 40+random2(2));
  set("con", 40+random2(2));
  set("cor", 40+random2(2));
  set("cps", 40+random2(2));
  set_skill("unarmed", random2(2)+10);
  set_skill("dodge", random2(2)+10);
  set_skill("parry", random2(2)+10);
  set("limbs", ({ "ͷ��", "����", "β��" }) );
  set("verbs", ({ "bite"}) );

  // slow down the douji process.
  set("allow_heal_up",1);

  setup();
}

