// by snowcat 11/22/1997
#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("�廨��", ({"xiuhua zhen", "zhen", "needle"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���ǹ��������廨�롣\n");
    set("wield_msg", "$N�γ�һ���廨�룬�������\n");
    set("unwield_msg", "$N���廨�����\n");
  }
  set("is_monitored",1);
  init_sword(3);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("$nͻȻ���ڵ��ϲ����ˣ�\n",where,me);
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

