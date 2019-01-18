// created 4/5/1997 by snowcat

void invite_player (object who)
{
  string dir;
  object me = this_object();

  message_vision ("$N����ָһ�㣬ʯ�ſ��ˡ�$n���˽�ȥ��\n", me, who);
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/firemount/";
  who->move(dir+"dongnei.c");
  message_vision ("���⴫��$N��������������ߵ��������\n", me, who);
}

void inform_player (string msg, object who)
{
  object me = this_object();

  message_vision (msg, me, who);
}

int test_player (object me)
{
  object who = this_player();
  string msg = "$N˵������λ"+RANK_D->query_respect(who);

  if (who->query("family/family_name")=="����ɽ�Ž���")
  {
    inform_player (msg+"�������\n",who);
    call_out("invite_player",1,who);
    return 1;
  }  

  if (who->query("obstacle/firemount") == "done")
  {
    inform_player (msg+"ʧ���ˣ�\n",who);
    call_out("invite_player",1,who);
    return 1;
  }  

  if (present("palm bone",who))
  {
    inform_player (msg+"�ͱ��������룡\n",who);
    call_out("invite_player",1,who);
    return 1;
  }  

  if (who->query_temp("won_cloud_fog"))
  {
    inform_player (msg+"������ˣ��룡\n",who);
    call_out("invite_player",1,who);
    return 1;
  }  

  inform_player (msg+"�Ǳ����ɵ��ӣ���δ�������ָ��֣��������������\n",who);
  return 1;
}

int accept_fight(object who)
{
  object me = this_object();

  remove_call_out("check_fight");
  call_out("check_fight", 1, me, who);
  return 1;
}

void player_win (object me, object who)
{
  object tieshan = present("tie shan",me);
  string msg;

  message_vision ("$N��$n˵����ʦ��Ȼ���ֲ�����\n",me,who);
  who->set_temp("won_cloud_fog",1);
}

void player_lose (object me, object who)
{
}

void check_fight (object me, object who)
{
  int my_kee, whos_kee;
  int my_max_kee, whos_max_kee;

  if(!who) return;

  my_kee = me->query("kee");
  whos_kee = who->query("kee");
  my_max_kee = me->query("max_kee");
  whos_max_kee = who->query("max_kee");

  if (me->is_fighting())
  {
    call_out ("check_fight",2,me,who);
    return;
  }

  if (!present(who, environment(me)))
    return;

  if ((my_kee*100/my_max_kee) <= 50)
    player_win (me, who);
  else if ((whos_kee*100/whos_max_kee) <= 50)
    player_lose (me, who);

}

