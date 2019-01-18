// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("�������", ({ "pishu dawang", "dawang" }));
  set("title", "��Ӣ��");   
  set("long", "һλ���֣������ϳ���һ���ǡ�");
  set("gender", "����");
  set("age", 50);
  set("attitude", "heroism");
  set("per", 29);
  set("max_kee", 1400);
  set("max_gin", 1400);
  set("max_sen", 1400);
  set("force", 1400);
  set("max_force", 1400);
  set("force_factor", 90);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 80);
  set("combat_exp", 640000);
  set("daoxing", 800000);

  set_skill("spells", 50);
  set_skill("dao", 50);
  set_skill("unarmed", 90);
  set_skill("dragonfight", 85);
  set_skill("dodge", 10);
  set_skill("jindouyun", 70);
  set_skill("kugu-blade", 70);
  set_skill("parry", 85);
  set_skill("force", 70);
  set_skill("wuxiangforce", 70);
  set_skill("blade", 80);
  map_skill("spells", "dao");
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  set("env/wimpy", 50);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/qinglong/obj/blade")->wield();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if (ob)
  {
    ob->set_temp("obstacle/jinping_pi2_killed",1);
    call_out ("fuling_appearing",1,ob);
  }
  message_vision ("\n$N�˵��ڵأ���ԭΪһͷϬţ��\n",me);
  message_vision ("\n�����ľ����һ����Ϭţ��һ����׽��ȥ��\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void fuling_appearing (object who)
{
  object prince = new ("/d/qujing/jinping/npc/fuling");

  prince->announce_success (who);
  destruct (prince); 
}

void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

�