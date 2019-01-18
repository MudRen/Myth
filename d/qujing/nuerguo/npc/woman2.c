// created 4/4/1997 by snowcat

inherit NPC;

int is_busy;

void create()
{
  set_name("�ϸ���", ({"old woman", "woman"}));
  set("age",51);
  set("gender", "Ů��");
  set("combat_exp", 5000);
  set_skill("unarmed", 15);
  set_skill("dodge", 15);
  set_skill("parry", 15);
  set("chat_chance",10);
  set("chat_msg",({(: random_move :)}));

  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  is_busy = 0;
  add_money ("coin", 10+random(200));  
}

void init()
{
  object me;
  me = this_object();

  ::init();
  if (present("xiliang princess", environment(me)))
  {
    remove_call_out ("persuade_princess");
    call_out ("persuade_princess", 3, me);
  }
}

void persuade_princess (object me)
{
  object who;

  who = me->query_temp("help_who");

  if (! who)
    return;
  if (environment(me) != environment(who))
    return;

  if (! present ("xiliang princess",environment(me)))
    return;

  message_vision ("С��������$N������һ�£�����ô�֡���\n", me);
  message_vision ("$N��С�����Ķ�������˵�˼��仰�����$nһ�ۡ�\n", me,who);
  command("follow none");
  call_out("check_result",3,me,who);
}

void check_result (object me, object who)
{
  string dir;
  object icedew;

  if (! who)
    return;
  if (environment(me) != environment(who))
    return;

  if (! present ("xiliang princess",environment(me)))
    return;

  if (random(5) == 0)
  {
    message_vision ("ֻ��ӫ��һ����С�����ӱ������ó�һ������$N��\n", me);
    message_vision ("$N�Ͻ���ͷ���˸��򸣡�\n", me);
/*
    dir = __DIR__;
    dir[strlen(dir)-4] = 0;
*/
    dir = "/d/qujing/nuerguo/";
    icedew = new (dir+"obj/icedew");
    icedew->move(who);
    message_vision ("$N�����ϵĶ���Ѹ�ٵ�����$n��������ȥ��\n", me, who);
  }
  else
  {
    message_vision ("С�����ߺ��˼������޶����ԡ�\n", me);
    message_vision ("$N�Ͻ���ͷл������ĵ�������ȥ��\n", me);
  }
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/nuerguo/";
  me->move(dir+"townb2.c");
  message_vision ("$N���˹�����\n", me);
}

int accept_object (object who, object ob)
{
  string id;
  object me;

  me = this_object();

  id = ob->query("money_id");
  if (! id)
  {
    message_vision ("$N���ص�һЦ��ҡ��һ��ͷ��\n", me);
    return 1;
  }

  if (who->query("combat_exp")<2000)
  {
    message_vision ("$N���ص�һЦ��ҡ��һ��ͷ��\n", me);
    return 1;
  }

  if (who->query("obstacle/number") == "done")
  {
    message_vision ("$N���ص�һЦ��ҡ��һ��ͷ��\n", me);
    return 1;
  }

/*
  if (who->query("obstacle/nuerguo") == "marriage")
  {
    message_vision ("$N���ص�һЦ��ҡ��һ��ͷ��\n", me);
    return 1;
  }

  if (who->query("obstacle/nuerguo") == "company")
  {
    message_vision ("$N���ص�һЦ��ҡ��һ��ͷ��\n", me);
    return 1;
  }
*/

  if (who->query("obstacle/nuerguo") == "stomachache")
  {
    message_vision ("$N���ص�һЦ��ҡ��һ��ͷ��\n", me);
    return 1;
  }
  
  if ( ob->value() < (2000+random(1000))) 
  {
    message_vision ("$N��΢��ԥ��һ�£����Գ�һ���޶����Ե����ӡ�\n",me);
    return 1;
  }  

  if (is_busy)
  {
    message_vision ("$N�����е㷢ֱ������ʲô��û������\n",me);
    return 1;
  }  

  if (random(2) == 0)
  {
    message_vision ("$N��$n����һ��ͷ������һ�룬��ͻȻҡҡͷ��\n", me, who);
    return 1;
  }  
  is_busy = 1;
  call_out("reset_busy",60);
  message_vision ("$N��������ϸ�ؿ��˿���\n", me);
  me->set_temp ("help_who",who);
  command("follow " + who->query("id"));
  return 1;
}

void reset_busy ()
{
  is_busy = 0;
}


