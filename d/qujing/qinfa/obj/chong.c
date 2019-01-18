#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "�˯��" , ({"keshui chong", "chong"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("long", "һֻ���ɵ��˯�棬��������ֻ�۾���ֵض����㡣\n");
    set("value", 60000);
  }
  set("is_monitored",1);
  setup();
}

void init()
{
  add_action("do_apply", "apply");
  add_action("do_apply", "fang");
}

int do_apply(string arg)
{
  object me = this_player();
  object where = environment(me);
  object ob;

  if (! arg)
    return notify_fail ("��Ҫ���˯����ʲô��\n");

  ob = present (arg,where);
  if (! ob)
    return notify_fail ("��Ҫ���˯����˭���Ϸţ�\n");
  
  if (! living(ob))
    return notify_fail ("��Ҫ���˯����˭���Ϸţ�\n");
  
  if (me == ob)
    return notify_fail ("��Ҫ���˯�����Լ����Ϸţ�\n");
// 44    if ((userp(ob))&& (int)me->query("max_mana")<(int)ob->query("max_mana")*2)
  if (userp(ob))
    {
       return notify_fail ("�˯�汻�Է��ķ���Ȧһ�ƣ��ַ��˻�����\n");
    
    }

  // mon 4/11/98
  if(where->query("no_fight") && where->query("no_magic"))
      return notify_fail ("�ڰ�ȫ�����˯��ɲ�̫�ðɣ�\n");

  if (this_object()->query("is_climbing"))
    return notify_fail ("�˯���������ء�\n");

  message_vision ("$N�����ĵ��ó�һֻ�˯�棬��$n����һ�š�\n",me,ob);
  message_vision ("�˯��Ѹ�ٵ�����$N�ıǿ��\n",ob);
  this_object()->move(ob);  
  this_object()->set("is_climbing",1);
  call_out("applying",1+random(10),ob);  
  return 1;
}

void applying (object ob)
{
  if (! ob)
    return;

//  message_vision ("$nѸ�ٵ�����$N�ıǿ��\n",ob,this_object());
  message_vision ("$N�̲�ס����һ����Ƿ������˯�⡣\n",ob);

  if ((userp(ob) || ob->query("can_sleep")) && random (2)==0) {
    //mon 12/18/97 to allow player sleep.
    ob->set_temp("force_sleep",1);
    if(!wizardp(ob)) ob->command_function("sleep");    
    ob->delete_temp("force_sleep");
  }
  destruct (this_object());
}
