// sgzl

inherit ITEM;

void create()
{
        set_name("����", ({"flag","qi"}));
        set("unit", "��" );
        set_weight(500);
        set("long", @LONG
       ***********************************************
       **      �ô����߿�Ϊ���鸣��ˮ����֮����     **
       ***********************************************
LONG);
}

void destruct_me(object where, object me)
{
  message_vision("һ����紵����$n����һ�Żҽ���\n",where,me);
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
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}
