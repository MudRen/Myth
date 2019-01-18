// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("����̨", ({"yun chantai", "chantai"}));
  set_weight(6000000);
  set_max_encumbrance(100000000000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("long", "һ������ʮ�����Ӽ����ݳɵ���̨���������ơ�\n"),
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
  call_out("disturbed",5+random(20),this_object(),this_player());
  call_out ("autoleave",1,this_object(),this_player(),0);
  add_action ("do_look","look");
  add_action ("do_put","put");
  add_action ("do_get","get");
}

void disturbed (object me, object who)
{
  string *msgs = ({
    "$N���Ͳ�ס������һ�£��Ͻ�������\n",
    "$Nǿ���ţ������½���˲�ͷ��\n",
    "$N����һ�ᣬ����ˤ�¡�\n",
    "$N�Զ���һ����\n",
    "$Nһ��������æ������\n",
    "$N����бб�е�����ס�ˡ�\n",
    "$N�������һ��������ֱ�Ρ�\n",
  });
  string msg = msgs[random(sizeof(msgs))];
  object where = environment(me);

  if (! who)
    return;
  if (environment(who) != me)
    return;

  if (! living (who))
    return;
  message_vision (msg,who);
  msg = replace_string (msg,"$N",who->name());
  tell_room(where,"��̨��"+msg,who);    
  call_out("disturbed",5+random(20),me,who);
}

void autoleave (object me, object who, int i)
{
  if (! who)
    return;
  if (environment(who) != me)
    return;
  if (! living (who))
    return;
  if (i < 60)
  {
    call_out("autoleave",1,me,who,i+1);
    return;
  }
  who->move(environment(me));
  message_vision ("ֻ��$N���Դ�һ��ˤ��������������ڵ��ϡ�\n",who);
  if (interactive(who))
    who->unconcious(); 
}

int do_look (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;
  mixed *inv;
  int i;

  if (!arg)
    return 0;

  ob = present(arg,where);
  if (ob != me)
    return 0;

  tell_object(who,ob->long());
  inv = all_inventory(ob);
  i = sizeof(inv);
  if (i)
  {
    tell_object(who,"�����У�\n");
    while (i--)
    {
      tell_object(who,"  "+inv[i]->short()+"\n");
    }
  }
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
