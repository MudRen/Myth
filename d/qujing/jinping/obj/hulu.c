// hulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("�ͺ�«", ({"you hulu", "hulu", "hu", "lu"}));
  set_weight(700);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ���ú�«�Ƴɵ��ͺ�������������ϻ���\n");
    set("unit", "��");
    set("value", 1000);
    set("max_liquid", 10);
  }
  set("liquid", ([
    "type": "oil",
    "name": "�ֺ�����",
    "remaining": 0,
  ]));
  set("no_get",1);
  set("no_drop",1);
  set("no_sell",1);
}

void destruct_me(object where, object me)
{
  message_vision("$n���ȡ���һ��ˤ�ڵ��ϣ����˸����飡\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  add_action ("do_fill", "fill");
  add_action ("do_pour", "pour");
  add_action ("do_fill", "zhuang");
  add_action ("do_pour", "dao");
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
}

int do_fill (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if (! arg)
    return notify_fail ("��Ҫ��ʲô��\n");    
  ob = present (arg,who);
  if (! ob)
    return notify_fail ("����Ҫ��ʲô��\n");    

  if (! where->query("has_oil"))
  {
    if (where->query("has_oil_pot"))
      return notify_fail ("��������û���ֺ������ˡ�\n");    
    else
      return notify_fail ("����û���ֺ����Ϳɹࡣ\n");    
  }
 
  if (query("liquid/remaining") > 0)
  {
    //message_vision ("$N��$n��ʣ�µ�"+query("liquid/name")+"������\n",who,me);
    return notify_fail ("��«����װ���ֺ������ˡ�\n");
  }
  message_vision ("$N��$n�����ֺ����͡�\n",who,me);
  where->set("has_oil",0);
  where->regenerate_oil();
  set("liquid", ([
    "type": "oil",
    "name": "�ֺ�����",
    "remaining": 10,
  ]));
  return 1;
}

int do_pour (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object guan = present ("deng guan",where);
  object ob;

  if (! arg)
    return notify_fail ("���뵹ʲô��\n");
  ob = present (arg,where);
  if (! ob)
    return notify_fail ("��������������ﵹ��\n");
  if (ob->query("name")!="��Ƹ�")
    return notify_fail ("��������������ﵹ��\n");
  if (! query("liquid/remaining"))
    return notify_fail ("�ͺ�«��û���͡�\n");
  if (query("liquid/name") != "�ֺ�����")
    return notify_fail ("�ͺ�«��װ�Ĳ����ֺ����͡�\n");

  message_vision ("$N��$n���"+query("liquid/name")+"������Ƹס�\n",who,me);
  set("liquid", ([
    "type": "oil",
    "name": "�ֺ�����",
    "remaining": 0,
  ]));

  who->add_temp("obstacle/jinping_oil",1);
  if (guan)
  {
    int i = 40 - who->query("kar");

    if (i < 10)
      i = 10;
    i -= who->query_temp("obstacle/jinping_oil");
    
    if (i > 0)
      message_vision ("$N����$n���ٵ�"+chinese_number(i)+"�α�ɡ�\n",
                      guan,who);
    else     
    {
      message_vision ("$N����$n����үҪ���ˣ�\n",guan,who);
      call_out ("coming",random(3)+3,who);
    }
  }  
  return 1;
}

void coming (object who)
{
  object me = this_object();
  object *obs = all_inventory (who);
  int i = sizeof(obs);

  message_vision ("һ���紵������ү���֣�\n",who);
  while (i--)
  {
    object ob = obs[i];

    if (ob == me)
      continue;
    if (ob->query("no_get"))
      continue;
    if (ob->query("no_drop"))
      continue;

    message_vision ("��ү��$N�����ѳ�$n��\n",who,ob);
    if (! interactive(ob))
      destruct (ob);
    else
      ob->move(environment(who));
  }  
  message_vision ("\n��үЯ��$N������գ�\n",who);
  who->move("/d/qujing/qinglong/shantou");
  message_vision ("\n��үͻȻͣ������˳�㽫$N������һ�ӣ�\n",who);
  who->unconcious();
}

