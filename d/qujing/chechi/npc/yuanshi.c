// by snowcat oct 26 1997

inherit NPC;

void create()
{
  set_name("Ԫʼ����", ({"yuanshi tianzun", "yuanshi", "tianzun"}));
  set_weight(75000);
  set("long", "һ������ߵ�Ԫʼ���������ʥ���ڵ�̨�����ն�����\n");
  set("unit", "��");
  set("title", "ʥ��");
  set("value", 10000);
  set("age", 100);
  set("max_gin", 10);
  set("max_kee", 10);
  set("max_sen", 10);
  set("no_get","��ʥ�����֮�أ�������ȥ����·ִ�����Ҳ��\n");
  set("no_drop","�㽫ʥ��������һ�ţ��־����ף�Ӳ��ͷƤ�ְ���������\n");
  set("no_give","ʥ�����֮�����Ǹ������˰ɡ�\n");
  set("no_sell","ʥ�����ƷҲ��\n");
  setup();
}

void init ()
{
  add_action ("do_get","get");
  add_action ("do_lift","lift");
  add_action ("do_throw","throw");
}

int do_get (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object obj;

  if (! arg)
    return 0;
  obj = present(arg,where);
  if (obj == who)
    obj = present(arg+" 2",where);
  if (obj == me)
  {
    tell_object(who,"����Ҫ�����̵�����ȥ����ܰ�ö��ɡ�\n");
    return 1;
  }
  return 0;
}

int do_lift (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object obj;

  if (! arg)
    return notify_fail("��Ҫ��ʲô��\n");
  obj = present(arg,where);
  if (obj == who)
    obj = present(arg+" 2",where);
  if (! obj)
    return notify_fail("��Ҫ��ʲô��\n");
  if (obj != me)
    return notify_fail("��Ҫ��ʲô��\n");
  if (where->query("short") != "�����")
  {
    message_vision("$Nʹ�˳��̵�����Ҳû�ܽ�ʥ���������\n",who,me);
    return 1;
  }
  me->move(who);
  if (environment(me) != who)
  {    
    message_vision("$N�������һʹ����$nֻ�ǻ���һ�Ρ�\n",who,me);
    return 1;
  }
  message_vision ("$N���һ�������ȵؽ�$n���ڼ��ϡ�\n",who,me);
  return 1;
}

int do_throw (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object obj;

  if (! arg)
    return notify_fail("��Ҫ��ʲô��\n");
  obj = present(arg,who);
  if (! obj)
    return notify_fail("��Ҫ��ʲô��\n");
  if (obj != me)
    return notify_fail("��Ҫ��ʲô��\n");
  if (where->query("short") != "����ֻ�")
    return notify_fail("��������û����ʥ��ĵط���\n");
  if (environment(me) != who)
    return notify_fail("��������û����ʥ��ĵط���\n");

  message_vision ("$N��$n�ٹ�ͷ����������һ�ӡ�\n",who,me);
  remove_call_out ("destruct_me");
  call_out ("destruct_me",1,who,me);
  return 1;
}

void destruct_me (object who, object me)
{
  message_vision ("ֻ�����̡���һ����$n����һ�������\n",who,me);
  destruct (me);
}

void die ()
{
  this_object()->remove_all_killer();
  all_inventory(environment())->remove_killer(this_object());

  set("gin", 10);
  set("kee", 10);
  set("sen", 10);
  revive();
  reincarnate();
}

void unconcious ()
{
  die();
}

