inherit ITEM;

void create()
{
        set_name("����",({"bing qi"}) );
        set("long","һ��������������ǹ������ꪡ������ᡢ������\n
ʲô���У����涼���м������֣����������ƣ���\n");
        set_weight(20000);
        set("unit","��");
}

void destruct_me(object where, object me)
{
  message_vision("����������������һ�ء�\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",5,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

