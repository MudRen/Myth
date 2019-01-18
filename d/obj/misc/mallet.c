// created by snowcat

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

#include "message.h"

void create()
{
  set_name("������", ({ "mallet" }) );
  set_weight(350);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ����������\n");
    set("unit", "��");
  }
  set("value",100000);
  set("no_get",1);
  init_hammer(1);
  setup();
}

int init ()  
{   
  add_action ("do_hammer", "za");
  add_action ("do_faint", "yun");
  add_action ("do_maxfaint", "zayun");
  return 1;
}

object is_present (string arg, object room)
{
  object *list = all_inventory (room);
  object ob;
  int i;

  if (! arg)
    return 0;
  for (i=0; i<sizeof(list); i++)
  {
    if (list[i]->query("id")==arg)
    {
      ob = list[i];
      break;
    }
  }
  ob = present(arg,room);
  if (ob && !ob->is_character())
    ob = 0;
  return ob;
}

int do_hammer (string arg)
{
  string *hits = ({
    "\n$N�����ץ��ץ������Ȼ���¡�\n\n",
    "\n$N�������ۣ������ط��ſ������¡�\n\n",
    "\n$Nƴ�������ס������Ȼ������һ��̱�ڵء�\n\n",
    "\n$N�����һ��������§ס������Ȼ������Ż������ڵ��ϡ�\n\n",
  });

  object me = this_player();
  object ob;
  string name = this_object()->query("name");

  if (!arg) {
    return notify_fail ("Ҫ����һλ������\n"); 
  }
  ob = is_present (arg,environment(me));
  if (! ob) {
    return notify_fail ("��λ�����������\n");
  }

  set("value",0);
  if (me->query("sen")>50)
  {
    me->add("sen",-50);
  }
  else
  {
    me->unconcious();
    return 1;
  }

  if (ob->query("env/invisibility") > 0)
    message_vision ("$N�߸߾���һ�Ѿ޴������������$n���һ����������������أ�\n",me,ob);
  else
    message_vision ("$N�߸߾���һ�Ѿ޴������������$n���һ���������������У�\n",me,ob);
  message_vision ("\nֻ�����䣡�䣡�䣡\n\n�������춯�صľ��졭��\n",ob);
  message_vision (hits[random(sizeof(hits))],ob);
  ob->set("env/immortal",0);
  ob->set("env/invisibility",0);
  return 1;
}

int do_faint (string arg)
{
  if (!do_hammer(arg))
    return 0;
  if (!wizardp(this_player()))
    return 1; 
  set("value",0);
  if (this_player()->query("sen")>50)
  {
    this_player()->add("sen",-50);
  }
  else
  {
    this_player()->unconcious();
    return 1;
  }
  call_out ("get_fainted",2,is_present (arg,environment(this_player())));
  return 1;
}

void get_fainted (object ob)
{
  //ob->unconcious();
}

int do_maxfaint (string arg)
{
  if (!do_hammer(arg))
    return 0;
  if (!wizardp(this_player()))
    return 1; 
  set("value",0);
  if (this_player()->query("sen")>50)
  {
    this_player()->add("sen",-50);
  }
  else
  {
    this_player()->unconcious();
    return 1;
  }
  call_out ("get_maxfainted",2,is_present (arg,environment(this_player())));
  return 1;
}

void get_maxfainted (object ob)
{
  string short = ob->query("name")+"("+capitalize(ob->query("id"))+")";
  if (ob->query("nickname"))
    short = "��"+ob->query("nickname")+"��"+short;
  if (ob->query("title"))
    short = ob->query("title")+short;
  message_vision(HIR "\n$N��ð���ǣ�һ�������˵��ڵ�....\n\n" NOR,
          ob);
  // ob->set_temp("no_move",1);
  // //ob->disable_player(" <������>");
  //ob->set_temp("block_msg/all", 1);
  ob->set_temp("apply/short",({short+" <������>"}));
  //ob->set("gin", 0);
  //ob->set("kee", 0);
  //ob->set("sen", 0);
  ob->set_temp("mallet_fainted", 1);
  call_out("get_revived", random(100 - query("con")) + 50, ob,short);
  call_out("display_fainted", random(5), ob);
}

void get_revived (object ob, string short)
{
  if (! ob->query_temp("mallet_fainted"))
    return;

  message_vision(HIR "\n$N�������������վ������\n" NOR,
          ob);
  // ob->delete_temp("no_move");
  // //ob->revive();
  ob->delete_temp("apply/short");
  //ob->set_temp("block_msg/all", 0);
  ob->set_temp("mallet_fainted", 0);
}

void display_fainted (object ob)
{
  string *msgs = ({
    "$N�λ�������������һ����̱��ȥ��\n",
    "$N���ڵ��Ϸ������ۡ�\n",
    "$N����������������һ���ֵ���ȥ��\n",
    "$N�����ۣ�ͷһ�������˹�ȥ��\n",
    "$NŬ���������죬ʲôҲ˵��������\n",
    "$N������һ�¡�\n",
    "$N����һ����\n",
    "$N����������֣��ڿ���ץ��һ�¡�\n",
  });

  if (! ob->query_temp("mallet_fainted"))
    return;

  message_vision(msgs[random(sizeof(msgs))],ob);
  call_out("display_fainted", random(20), ob);
  
}

