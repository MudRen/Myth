// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("������", ({"zhuhong guizi", "guizi"}));
  set_weight(6000000);
  set_max_encumbrance(100000000000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�������Ƕ���������ӡ�\n"),
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
  this_object()->set("short",this_object()->short());
  call_out ("autoleave",1,this_object(),this_player(),0);
  add_action ("do_command","",1);
  add_action ("do_look","look");
  add_action ("do_put","put");
  add_action ("do_get","get");
}

void autoleave (object me, object who, int i)
{
  if (! who)
    return;
  if (environment(who) != me)
    return;
  if (! living(who))
    return;
  if (i < 180)
  {
    call_out("autoleave",1,me,who,i+1);
    return;
  }
  who->move(environment(me));
  message_vision ("ֻ��$N�������ҵر��ڹ����˳�����\n",who);
  if (interactive(who))
    who->unconcious();
}

int do_command (string arg)
{
  string *strs = ({
    "������",
    "�������������",
    "������",
    "�������ƺ�",
  });
  string *msgs = ({
    "$N�ںڰ��к����ߴ��˼��¡�\n",
    "$N���ײ�ڹ��ϡ�\n",
    "$N�������ĵط���������\n",
    "$N���������š�\n",
    "$N���������������š�\n",
    "$N����һ��������\n",
    "$N�ݺݵ�ײ�ڹ���ϡ�\n",
    "$N��֪������ںڰ����ߴ��š�\n",
    "$N�������ص�ײ������\n",
    "$Nͷײ�ڱڰ��ϣ��������Ƶ�һ���졣\n",
  });
  string str = strs[random(sizeof(strs))];
  string msg = msgs[random(sizeof(msgs))];
  object who = this_player();
  object me = this_object();

  if (environment(who) != me)
    return 0;
/*
  if (wizardp(who))
  {
    return 0;
  }
*/
  message_vision (msg,who);
  msg = replace_string (msg,"$N",who->name());  
  tell_room(environment(me),str+msg);
  return 1;
}

int do_look (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if (!arg)
    return 0;

  ob = present(arg,where);
  if (ob != me)
    return 0;

  tell_object(who,ob->long());
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
