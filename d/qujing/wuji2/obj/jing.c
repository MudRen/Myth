// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("�ڼ���", ({"wuji jing", "jing"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("no_sell", 1);
    set("no_drop", 1);
    set("unit", "Сƿ");
    set("long", "һСƿ�ڼ�������˵����(drink)��������"+
                "ʩ������(apply)���Ի��ꡣ\n");
  }
  set("is_monitored",1);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("$n���ڵ��ϣ����ˡ�\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }

  add_action ("do_drink","drink");
  add_action ("do_apply","apply");
}

int do_drink (string arg)
{
  object me = this_object();
  object who = this_player();
  object ob = present(arg, who);

  if (! ob)
    return 0;
  if (ob != me)
    return 0;

  message_vision ("$N�����ڼ����������£�˳�ֽ���ƿһ�ӡ�\n",who);
  message_vision ("��ʱ$Nֻ����һ�ɾ��������������̣�Ǭ�����ã�\n",who);

  who->unconcious();
  destruct (me);
  return 1;
}

int do_apply (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if (! arg ||
     ! (ob = present(arg, where)))
  {
    return notify_fail("��Ҫ���ڼ�������ʲô���棿\n");
  }
  if (ob == who)
  {
    message_vision ("$N�����ڼ������Լ�����һ����˳�ֽ���ƿһ�ӡ�\n",who);
    message_vision ("��ʱ$Nֻ����һ�ɾ��������������̣�Ǭ�����ã�\n",who);

    destruct (me);
    who->unconcious();
  }
  else if (ob->query("name") != "��������" ||
           who->query("obstacle/wuji") == "done")
  {
    message_vision ("$N�����ڼ�����$n��һ����˳�ֽ���ƿһ�ӡ�\n",who,ob);
    message_vision ("��ʱ"+ob->name()+"�ζ���һ�¡�\n",who);
    destruct (me);
  }
  else
  {
    object king = new ("/d/qujing/wuji/npc/kingreal");
    message_vision ("$N����$n�Ŀڴ��������ڼ���ֻ�ǹ��£�"+
                    "һ���������ʺ�\n",who,ob);
    message_vision ("�ڼ���������¥��ת���ã����������ʱ��������һ�¡�\n",
                    who);

    king->move(where);
    call_out("king_wake",2,king,who);
    call_out("follow_player",4,king,who,me);
    me->move(king);
    destruct (ob);
  }
  return 1;
}

void king_wake (object king, object who)
{
  message_vision ("\n����һ������������������飬��������\n",who);  
}

void follow_player (object king, object who, object me)
{
  if (! who)
    return;
  if (environment(who) != environment(king))
    return;
  message_vision ("\n������$N�ݵ�������ҹ�����ˣ����������񣡡�\n",who);  
  message_vision ("˵�չ�������һ�ݡ�\n",who);  

  if (who->query("obstacle/wuji") == "done")
    return;

  king->command_function("follow "+who->query("id"));
  king->set("my_saver",who->query("id"));
  who->set_temp("obstacle/wuji","saved");
  destruct (me);    
}
