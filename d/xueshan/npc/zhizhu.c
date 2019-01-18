inherit NPC;


void create()
{

  set_name("���֩��", ({ "wucai zhizhu", "zhizhu" }) );
  set("race", "Ұ��");
  set("age", 100);

  set("attitude", "aggressive");
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("xiaoyaoyou", 90);
  set_skill("cuixin-zhang", 90);
  set_skill("unarmed", 90);
  set("combat_exp", 300000);
  set("daoxing", 300000);

  map_skill("unarmed", "cuixin-zhang");
  map_skill("dodge", "xiaoyaoyou");

  set("limbs", ({ "ͷ��", "����", "ǰ��","����", "β��" }) );
  set("verbs", ({ "bite"}));

  setup();
}

void unconcious ()
{
  object ob;
  object me = this_object();
  object where = environment (me);

  ob = new ("/d/xueshan/obj/cookfood");
  ob->set("name",me->query("name"));
  ob->set("cook/type","zhizhu");
  ob->set("cook/value",5);
  ob->move(where);
  message_vision ("\n$N����һ�ţ����ٶ��ˡ�\n",me);
  destruct (me);
}

void die ()
{
  unconcious();  
}

