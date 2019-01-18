// tianmojian.c 	��ħ��

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;

void create()
{
	set_name("��ħ��", ({"tianmojian", "tianmo jian", "jian"}));
	set_weight(7000);
//  	set_max_encumbrance(50000);
//  	set("max_items",10);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�������˵���ħ��,ר��������ȡ����\n");
		set("unit", "��");
		set("max_liquid", 15);
	}

	set("value",1);
  	set("unique", 1);
  	set("no_sell", "����������\n");
  	set("is_monitored",1);
  	setup();

}



void init()
{
  object me = this_object();
  object where = environment();

  if (interactive(where))
  {
     if (where->query("obstacle/qujing")=="ren" 
		|| where->query("combat_exp")<500000)
	{
	   call_out("destruct_me",1,where,me);
   	}
  }

  add_action("do_shou","��");
  add_action("do_shou","shou");
  add_action("do_shou","zhua");
}


void destruct_me(object where, object me)
{
    object env=environment(where);
    message("sound","����һ�����,���õļһ�,������ħ����\n",env);
    destruct(me);
    OBSTACLE_D->delete("last_jie_id")	;
}


int do_shou()
{
   	object me,who,qjr,where,laoren,husongren;
	string husong 		;
	
	me=this_object()	;
	who=this_player()	;
        where=environment(who)	;
	if (!(qjr=present("qujing ren",where)))
 	  return notify_fail("ȡ���˲�������\n");
	husong=OBSTACLE_D->query("husong");
	husongren=find_player(husong);  	    	
        if (husongren)
 	  {  
   	     if (where==environment(husongren))
	     return notify_fail("�����ڱ�������\n");
  	  }

	message_vision("$N������ħ��,ֻ���Ǽ����������˿��ȡ����������ס\n",who);
	write("����߷·������������˵Ľк���,�Ǽ����ʧ��\n");

	OBSTACLE_D->set("cated_qjr",1);
	OBSTACLE_D->set("cated_id",who->query("id"));
	OBSTACLE_D->set("cated_type","player");
		//ȡ�����Ѿ���ץ.���������ץ��
	OBSTACLE_D->set("last_env",base_name(where));
	OBSTACLE_D->set("where_qujingren","/d/qujing/qujingren/tianmo/zlf");
	OBSTACLE_D->save();	
        OBSTACLE_D->qujing_fail();
	OBSTACLE_D->open_door();

	laoren= find_living("zhenglong laoren");
	if (laoren)destruct(laoren);
  	if (qjr)destruct(qjr);
	destruct(me);
	return 1;

}



