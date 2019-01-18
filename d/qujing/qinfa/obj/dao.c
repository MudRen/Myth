//Cracked by Roath
// by snowcat 11/22/1997
#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("�굶", ({"ti dao", "dao", "blade"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ����ͷ�õı��е���\n");
    set("wield_msg", "$N���һ�ѱ����굶���������\n");
    set("unwield_msg", "$N���굶����������һװ��\n");
  }
  init_blade(2);
  setup();
}

void init()
{
  add_action ("do_cut","cut");
  add_action ("do_cut","ti");
}

int do_cut(string arg)
{
  object me = this_player();
  object ob;

  if (! arg)
    return notify_fail ("��Ҫ���굶��ʲô��\n");

  ob = present (arg,environment(me));
  if (! ob)
    return notify_fail ("��Ҫ���굶��˭��ͷ��\n");
  
  if (! ob->is_character())
    return notify_fail ("��Ҫ���굶��˭��ͷ��\n");
  
  if (me == ob)
    return notify_fail ("��Ҫ���Լ���ͷ��\n");

  if (me->is_busy())
    return notify_fail ("������æ���ء�\n");

  if (ob->query_temp("no_hair"))
    return notify_fail ("�˼�ͷ����ûë�ˡ�\n");

  message_vision ("$N�����굶����$n����ͷ����\n",me,ob);
  me->start_busy(5,5);
  call_out ("cutting",5,me,ob);
  return 1;
}

void cutting (object me, object ob)
{
  me->interrupt_me();

  message_vision ("��ৣ�$N��ͷ������һƬ��\n",ob);
  if (living (ob))
  {
    message_vision ("$N������������Բ˫�۴��һ�����㣬ס�֣�\n",ob);

    if (environment(ob)->query("no_fight"))
      return;

    if (! interactive(ob) &&
        ! ob->query("can_sleep"))
      return;

    if(!userp(ob)) {
      message_vision ("���ˣ�������ͷҪ��������ˣ�\n",ob);
      ob->kill_ob(me);
    }
    return;
  }
    
  if (!ob)
    return;

  if (ob->query("disable_type") != "<˯����>" ||
      ! ob->query_temp("disabled"))
    return;

  if (random(7))
    return;
  message_vision ("$N��ͷ��������ˡ�\n",ob);
  ob->set_temp("no_hair",1);
  me->add_temp("obstacle/qinfa_cut_times",1);
  ob->check_hair();
}
 
