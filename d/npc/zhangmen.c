current_master"))
      who = present(me->query("current_master"),environment(me));
    if (who && who->query("id")!=me->query("current_master"))
      who = 0;

    if (who)
    { 
      call_out("master_announce",1,me,who,ob);
    }
    else
    {
      message_vision ("$N�����$n˵��������ݼ�ʦ����\n",me,ob);
      command ("follow "+ob->query("id"));
      if (! me->query("where"))
        me->set("where",base_name(environment(me)));
      remove_call_out("find_master");
      call_out("find_master", 1, me, ob);
    }
    return 1;
  }

  if (( (int)ob->query("kee")*100/his_max_kee)<=50)
  {
    message_vision ("$N��$n����\n",me,ob);
  }

  return 1;  
}

void find_master (object me, object ob)
{
  object who = present(me->query("current_master"),environment(me));

  if (who && who->query("id")!=me->query("current_master"))
    who = 0;

  if (! who)
  {
    remove_call_out("find_master");
    call_out("find_master", 1, me, ob);
  }
  else
  {
    message_vision ("$N����ʦ���Ͻ��°ݣ���̧��ͷ��$nʹ�˸���ɫ��\n\n",me,ob);
    message_vision ("$N΢΢�ص��˵�ͷ��\n\n",who);
    message_vision ("$N���¡�\n\n",me);
    me->set_leader(0);
    call_out("master_announce",1,me,who,ob);
    me->move(me->query("where"));
  }
}

void master_announce (object me, object who, object ob)
{
  string default_name = me->query("default_name");

  CHANNEL_D->do_channel(who,"chat","��ϲ"+default_name+ob->query("name")+"�������Σ�");
  me->set("new_player",1);
  convert_identity (me, ob);
}

string query_save_file()
{
  string str = query("save_file");
  int i;

  if (str)
    return str;

  str = DATA_DIR+"zhangmen/zhangmen_"+query("current_master");
  for (i = 0; i < sizeof(str); i++)
    if (str[i]==' ')
      str[i] = '_';

  return str;
}

void set_save_file(string str)
{
  set("save_file",str);
}

int do_bandage(string arg)
{
  object who = this_player();
  object me = present("zhang men",environment(who));

  if (! arg || me != present(arg, environment(me)))
    return 0;

  message_vision ("$N�������ĵ�Ҫ��$n�����˿ڡ�\n",who,me);
  call_out("no_bandage",2,who,me);
  return 1;
}

void no_bandage(object who, object me)
{
  message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

void kill_ob(object ob)
{
  object me = this_object();
  object master;

  if (me->query("current_master"))
    master = present(me->query("current_master"),environment(me));
  if (master)
    master->kill_ob(ob);
  else
  {
    /*
    master = find_living(me->query("current_master"));

    if (! master)
      master = new (me->query("current_master_base_name"));
    if (master)
    {
      message_vision (master->query("name")+"��Ѷ������Ҫɱ��$n��\n\n",me,ob);
      message_vision ("����"+master->query("name")+"��$nһָ$n��\n\n",me,ob);
      ob->unconcious();
      message_vision (master->query("name")+"���˳�ȥ��\n",me,ob);
    }
    */
  }
  me->set_temp("zhangmen/kill",1);
  ::kill_ob(ob);
}

void set_minimun_conditions(object me)
{
  me->set("gin",1);
  me->set("kee",1);
  me->set("sen",1);
}

void die()
{
  object me = this_object();

  //fully_recover (me);
  message_vision("\n$Nͣ�²����ˣ�̾�˿�����\n",me);
  set_minimun_conditions(me);
  me->remove_all_killer();
  all_inventory(environment())->remove_killer(me);
}

void unconcious()
{
  object me = this_object();

  //fully_recover (me);
  message_vision("\n$Nͣ�²����ˣ�̾�˿�����\n",me);
  set_minimun_conditions(me);
  me->remove_all_killer();
  all_inventory(environment())->remove_killer(me);
}

int create_identity (mixed master, mixed where)
{
  object master_ob, where_ob;

  if (this_object()->query("created"))
    return;
  this_object()->set("created",1);

  if (objectp(master))
    master_ob = master;
  else
  {
    master_ob = new (master);
    master_ob->restore();
  }

  if (objectp(where))
    where_ob = where;
  else
  {
    call_other(where,"???");
    where_ob = find_object(where);
  }
  init_identity (this_object(), master_ob, where_ob);
  this_object()->set("age",30);
}

