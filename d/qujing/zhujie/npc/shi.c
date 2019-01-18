// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("��ͷʨ", ({ "jiutou shi", "shi" }));
  set("title", "����Ԫʥ");   
  set("long", "һλ�����֣����žŸ�ʨ��ͷ��\n");
  set("gender", "����");
  set("age", 70);
  set("attitude", "heroism");
  set("per", 29);
  set("max_kee", 1500);
  set("max_gin", 1500);
  set("max_sen", 1500);
  set("force", 1200);
  set("max_force", 1200);
  set("force_factor", 100);
  set("max_mana", 600);
  set("mana", 600);
  set("mana_factor", 80);
  set("combat_exp", 750000);
  set("daoxing", 1000000);

  set_skill("spells", 50);
  set_skill("dao", 50);
  set_skill("unarmed", 90);
  set_skill("dragonfight", 85);
  set_skill("dodge", 10);
  set_skill("jindouyun", 70);
  set_skill("qianjun-bang", 70);
  set_skill("parry", 85);
  set_skill("force", 70);
  set_skill("wuxiangforce", 70);
  set_skill("staff", 50);
  map_skill("spells", "dao");
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "qianjun-bang");
  set("heads", 9);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if (ob)
  {
    ob->set_temp("obstacle/yuhua_killed",1);
    call_out ("prince_appearing",1,ob);
  }
  message_vision ("\n$N�˵��ڵأ�����Ϊһͷ��ͷʨ����\n",me);
  message_vision ("\n����д����ȿ������ŭ�ȣ�Ԫʥ�����ظ���\n",me);
  message_vision ("��ͷʨ����һ����ƶ�ȥ��\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void prince_appearing (object who)
{
  object prince = new ("/d/qujing/yuhua/npc/prince");

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
  call_out ("recovering",1,me,ob);  
  call_out ("hurting",random(20)+20,me,ob);  
  ::kill_ob(ob);
}

void recovering (object me, object ob)
{
  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  if (me->query("heads") > 0 &&
      (me->query("kee") < (me->query("max_kee")*3/4) ||
       me->query("sen") < (me->query("max_sen")*3/4)))
  {
    message_vision ("\n$Nҡ�γ�һֻʨ��ͷ�����Լ��˴�һ��\n",me);
    me->set("gin",me->query("max_gin"));
    me->set("kee",me->query("max_kee"));
    me->set("sen",me->query("max_sen"));
    me->set("eff_gin",me->query("max_gin"));
    me->set("eff_kee",me->query("max_kee"));
    me->set("eff_sen",me->query("max_sen"));
  }
  call_out ("recovering",1,me,ob);  
}

void hurting (object me, object ob)
{
  string *msgs = ({
    "$N��һֻʨ��ͷ�쳤��һ�ڰ�$n�������\n",
    "$N���һֻʨͷ����$n�������\n",
    "$N��ʨ��ͷһ�ڣ��ſ�Ѫ���ڽ�$nҧ��\n",
  });
  object zhudao;
  int heads = me->query("heads");

  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
  
  zhudao = present("taiyi zhu dao",ob);
  if (! zhudao ||
      zhudao != ob->query_temp("weapon"))
  {
    message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
    ob->move("/d/qujing/zhujie/shi");
    ob->unconcious();
  }
  else if (heads>0)
  {
    object head = new("/d/qujing/zhujie/obj/head");

    message_vision ("����$N�����䣬"+
                    "$n�Һ�һ����һֻʨͷ��أ�\n",ob,me);
    head->move(environment(me));
    me->add("heads",-1);
    me->set("long", "һλ�����֣���ʣ��"+chinese_number(heads-1)+"��ʨ��ͷ��");
  }
  remove_call_out ("hurting");  
  call_out ("hurting",random(20)+20,me,ob);  
}
�
