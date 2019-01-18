// zijinbo.c	�Ͻ�

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;

void create()
{
	set_name("�Ͻ�", ({"zijinbo", "zijin bo", "bo"}));
	set_weight(7000);
//  	set_max_encumbrance(50000);
//  	set("max_items",10);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�����Ͻ�,������޼�֮��,������ի��\n");
		set("unit", "��");
		set("value", 1000000);
		set("max_liquid", 15);
	}

  	set("unique", 1);
  	set("no_sell", "������޼�֮��,����û�������ɡ�\n");
  	set("no_drop", "�Է��ļһ�,���ǲ������׶���\n");
  	set("no_give", "�����������ͱ���,����������\n");
  	set("is_monitored",1);
  	setup();

}


void destruct_me(object where, object me)
{
  object who;
  who=find_player(me->query("owned"))	;
  message_vision("$n����������,����ҫ�۵Ĺ�â���˷�Ʈȥ����\n",where,me);

  if (!who)destruct(me);
  me->move(who)				;
  tell_object(who,"���������һ��,�������ʲô����");
    
}

void init()
{
  object me = this_object();
  object where = environment();
  add_action("do_huayuan","huayuan");

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


int do_huayuan(string arg)
{
   object me,who,target,where;
   me=this_object();
   who=this_player();
   where=environment(who);
 
   if (!arg)return notify_fail("��Ҫ��˭��Ե\n");
   if (target=present(arg,where))
     {
	if (me->query("have_food"))
		return notify_fail("�Ͻ����Ѿ��ж�����\n");
	if (who->is_busy())return notify_fail("�����æ������\n");
	if (who->is_fight())return notify_fail("�����.\n");
	if (target->query("id")=="qujing ren")
		return notify_fail("�����Ʊ��㻹��\n");
	if (target->query("attitude")!="friendly")
		return notify_fail(target->query("name")+"��������̫�Ѻ�\n");
	if (target->query_temp("give_beg")) 
		return notify_fail(target->query("name")
			+"������ûʲô���Ը����\n");	  
/*	if (!target->query("vendor_goods"))
		return notify_fail(target->query("name")
			+"������ûʲô���Ը����.\n");	  
	//�������̵껯Ե.
*/

	if (random(2)!=0) 
	  {
 	    target->set_temp("give_beg",1);//Ҫ��һ�γɹ�
	    return notify_fail(target->query("name")
		+"������ûʲô���Ը����\n");
	  }

	target->command_function("say �����ﻹ��Щ����,��ͽ����ð�\n");
        message_vision("$N������Щ����\n",target);
	target->set_temp("give_beg",1);
	me->set("have_food",1);
     }
   else
     {
	return notify_fail("��Ҫ��˭��Ե\n");
     }
  
   return 1;
}




 

