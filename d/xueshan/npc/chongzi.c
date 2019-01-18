inherit NPC;

string *names = ({
  "����",
  "���",
  "Ы��",
  "֩��",
  "���",
});

string *ids = ({
  "she",
  "wugong",
  "xie",
  "zhizhu",
  "hama",
});

void create()
{
  int ii;
  ii=random(sizeof(names));

  set_name(names[ii], ({ids[ii]}));
  set("race", "Ұ��");
  set("age", 10);

  set_skill("dodge", 10);
  set("combat_exp", 100);
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
//  ob->set("id",me->query("id"));
  ob->set("cook/type",me->query("id"));
  ob->move(where);
  message_vision ("\n$N����һ�ţ����ٶ��ˡ�\n",me,ob);
  destruct (me);
}

void die ()
{
  unconcious();  
}

