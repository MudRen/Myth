inherit NPC;


void create()
{

  set_name("�������", ({ "baizu wugong", "wugong" }) );
  set("race", "Ұ��");
  set("age", 100);

  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set("combat_exp", 100);
  set("limbs", ({ "ͷ��", "����", "��","��","��","��","��","��","��", "β��" }) );
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
//  ob->set("id",me->query("id"));
  ob->set("cook/type","wugong");
  ob->set("cook/value",5);
  ob->move(where);
  message_vision ("\n$N����һ�ţ����ٶ��ˡ�\n",me);
  destruct (me);
}

void die ()
{
  unconcious();  
}

