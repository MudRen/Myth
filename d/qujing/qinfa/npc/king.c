// by snowcat 11/6/1997

inherit NPC;

int test_player (object who);

void create()
{
  set_name("����", ({"guo wang", "wang", "king"}));
  set("long", "�շ����������������ۣ���̬ׯ�ϡ�\n");
  set("title", "�շ���");
  set("gender", "����");
  set("age", 50);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",120);
  set("eff_dx",15000);
  set("nkgain",90);
  set("inquiry", ([
    "buddhism" : (: test_player :),
    "monk" : (: test_player :),
    "��"   : (: test_player :),
    "���" : (: test_player :),
    "����" : (: test_player :),
    "�ݷ�" : (: test_player :),
    "���" : (: test_player :),
    "�����" : (: test_player :),
  ]));
  set("can_sleep",1);
  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void check_hair ()
{
  object me = this_object();

  if (me->query("disable_type") == "<˯����>" &&
      me->query_temp("disabled"))
  {
    call_out("check_hair",1);
    return;
  }

  if (me->query_temp("has_said"))
    return;

  message_vision ("$NͻȻ����ʶ��������ͷ�����ţ��Դ�ȫ����ˣ�\n",me);
  message_vision ("$Nһ��ѣ�Σ����ˤ���ڵأ�\n",me);
  me->set_temp("has_said",1);
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "jingang")
  {
    message_vision ("$N˵����ʲô���⣬�޽�ɽ���У���ȱ���û���\n",me);
    return 0;
  }
  if (! query_temp("has_said"))
  {
    message_vision ("$N˵�������ã���Ҫɱ��һ����У�\n",me);
    me->kill_ob(who);
    return 1;
  }
  if (who->query_temp("obstacle/qinfa_cut_times")<4)
  {
    message_vision ("$N˵����������������Ҫɱ��һ����У�\n",me);
    me->kill_ob(who);
    return 1;
  }
  command ("thank "+who->query("id"));
  me->set_temp("has_book",ob->query("name"));
  remove_call_out ("reading");
  call_out ("reading",3);
  return 1;
}

void reading ()
{
  object me = this_object();
  string book = me->query_temp("has_book");

  if (! living (me))
  {
    message_vision ("$N���˷����ۡ�\n",me);  
    return;
  }
  if (! book)
  {
    message_vision ("$N��˼Ƭ�̡�\n",me);  
    return;
  }

  message_vision ("$N����"+book+"���۾�����ض���������\n",
                  me);  
  me->set_temp("can_believe",1);
  if (random(4))
  {
    remove_call_out ("reading");
    call_out ("reading",3);
  }
}

int test_player (object who)
{
  object me = this_object();
  who = this_player();
  if (! me->query_temp("can_believe")) 
  {
    message_vision ("$N˵������Ҫɱ��һ����У�\n",me);
    return 1;
  }    
  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$N˵�����㣬���в��㣬��ɶ��죡\n",me);
    return 1;
  }    
  if (who->query_temp("obstacle/qinfa_cut_times")<4)
  {
    message_vision ("$N˵����������ɮ����Ҳ��\n",me);
    return 1;
  }    
  if (who->query("obstacle/qinfa") == "done")
  {
    message_vision ("$N˵��������������\n",me);
    return 1;
  }    
  message_vision ("$N��Ĭ��������һ��ͷ��\n\n",me);
  remove_call_out ("saying1");
  call_out ("saying1",3,who);  
  return 1;
}

void saying1 (object who)
{
  object me = this_object();
  message_vision ("$N˵����������ɮ�����ޣ�����ԸҪɱһ�������Բ����\n\n",me);
  remove_call_out ("saying2");
  call_out ("saying2",3,who);  
}

void saying2 (object who)
{
  object me = this_object();
  message_vision ("$N˵�������ڽ�ҹ���������޵�Ϊɮ��\n\n",me);
  remove_call_out ("saying3");
  call_out ("saying3",5,who);  
}

void saying3 (object who)
{
  object me = this_object();
  message_vision ("$N˵������񷢶������ˣ���Ը����š�\n\n",me);
  remove_call_out ("saying4");
  call_out ("saying4",5,who);  
}

void saying4 (object who)
{
  object me = this_object();
  message_vision ("$N��˵������������Ҳ��\n\n",me);
  remove_call_out ("announce_success");
  call_out ("announce_success",5,who);  
}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/qinfa") == "done")
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/qinfa","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"�𷨹�Ȱ�޹������ţ��޸Ĺ���Ϊ�շ�����");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}
�
