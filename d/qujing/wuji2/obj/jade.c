// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("��������", ({"yu gui", "yu", "jade"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 100000);
    set("no_sell", "����û�˸�����������硣\n");
    set("no_drop", "˭�����ӽ������磿\n");
    set("unit", "��");
    set("long", "һ���������磬���ڼ���֮������\n");
  }
  set("is_monitored",1);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("$n���һ��������һ����ȥ�ˡ���\n",where,me);
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
}

