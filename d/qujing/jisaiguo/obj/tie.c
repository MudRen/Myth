// by snowcat 11/1/1997

inherit ITEM;

void create()
{
  set_name("����", ({"shu tie", "tie"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ����ֵ���ɫ������\n");
  }
//  set("is_monitored",1);
  setup();
}
/*
void destruct_me(object where, object me)
{
  message_vision("$nһ�ɾͲ����ˡ���\n",where,me);
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

*/
