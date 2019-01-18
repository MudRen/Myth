// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("����", ({"e long", "long"}));
  set_weight(6000000);
  set_max_encumbrance(100000000000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("long", "һֻͭ��������\n"),
    set("value", 50000);
  }
  setup();
}

int is_container()
{
  return 1;
}

void init()
{
  object me = this_object();

  if (! me->query_temp("initialized"))
  {
    object kid = new ("/d/qujing/biqiu/npc/kid");
    me->set_temp("initialized",1);
    kid->move(me);
  }
  add_action ("do_open","open");
  add_action ("do_put","put");
  add_action ("do_get","get");
}

int do_open (string arg)
{
  object me = this_object();
  object who = this_player();
  object kid;
  object ob;

  if (!arg)
    return notify_fail("��Ҫ��ʲô��\n");

  ob = present(arg,environment(who));
  if (ob != me)
    return 0;

  kid = present ("xiao er",me);
  if (kid)
  {
    message_vision ("$N��������֨��һ���򿪡�\n",who);
    message_vision ("һλС�����������������ߵߵŵŵ����ˡ�\n",who);
    who->add_temp("obstacle/biqiu_xiaoer",1);
    call_out ("reset_elong",1800);
    destruct (kid);
  }  
  else
  {
    message_vision ("$N�������򿪣���ͷ���ȥ���˿���\n",who);
  }  
  return 1;
}

void reset_elong ()
{
  this_object()->set_temp("initialized",0);
}

int do_get (string arg)
{
  string item;
  string id;
  object me = this_object();
  object who = this_player();
  object where = environment (me);

  if (sscanf(arg, "%s from %s", item, id)!=2)
    return 0;
  if (me != present(id,where))
    return 0;

  tell_object(who,"����û������������\n");
  return 1;
}


int do_put (string arg)
{
  string item;
  string id;
  object me = this_object();
  object who = this_player();
  object where = environment (me);

  if (sscanf(arg, "%s in %s", item, id)!=2)
    return 0;
  if (me != present(id,where))
    return 0;

  tell_object(who,"����û������������\n");
  return 1;
}

