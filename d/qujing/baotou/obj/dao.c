// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("̫����", ({"taiyi zhu dao", "zhu dao", "dao"}) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 2000);
    set("material", "bamboo");
    set("no_sell", 1);
    set("no_drop", 1);
    set("is_monitored", 1);
    set("replace_file", "/d/obj/weapon/blade/blade");
    set("long", "����һ��ϸ�񵶣����л��������\n");
    set("wield_msg", "$N���һ��ϸϸ��$n�������У��޹���˸��\n");
    set("unequip_msg", "�޹�һ����$N�����е�$n����\n");
  }
  init_blade(65);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("һ������������$n��ͻ��������ϼ�������ˣ�\n",where,me);
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

