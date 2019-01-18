// added by snowcat

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/jingjiling") == "done")
    return;
  if (! who->query_temp("obstacle/jingjiling/guzhi gong"))
    return;
  if (! who->query_temp("obstacle/jingjiling/lingkong zi"))
    return;
  if (! who->query_temp("obstacle/jingjiling/shiba gong"))
    return;
  if (! who->query_temp("obstacle/jingjiling/fuyun sou"))
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/jingjiling","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"�����붷�Ƕ��䣬�������ɣ�");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}

void player_win (object me, object who)
{
  object obj;
  
  who->set_temp("obstacle/jingjiling/"+me->query("id"),1);
  message_vision("$N��$nһ�Ϲ�����������\n",me,who);  
  me->announce_success(who);
}

void player_lose (object me, object who)
{
  message_vision("$N��$nһ���֣�ȥ�ɣ�ȥ�ɣ�\n",me,who);
}

void check_fight (object who)
{
  object me = this_object();
  int my_kee, whos_kee;
  int my_max_kee, whos_max_kee;

  my_kee = me->query("kee");
  whos_kee = who->query("kee");
  my_max_kee = me->query("max_kee");
  whos_max_kee = who->query("max_kee");

  if (me->is_fighting()){
    remove_call_out("check_fight");
    call_out ("check_fight",1,who);
    return;
  }

  if (!present(who, environment(me)))
    return;

  if ((my_kee*100/my_max_kee) <= 50)
    player_win (me, who);
  else if ((whos_kee*100/whos_max_kee) <= 50)
    player_lose (me, who);
}

void reset_me ()
{
  object me = this_object();
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
}

