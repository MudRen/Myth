# include <skill.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIM"��"+HIR"��"+HIC"ˮ"+HIY"��"+HIG"ʯ"NOR, ({"jingshi", "shi", "shui jing"}));
	set_weight(1);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
	//	set("no_give",1);
		set("no_put",1);
		set("no_get",1);
		set("value",0);
		set("unit","��");
		set("long",
"һ������ˮ����������������ɢ����"+HIM"��"+HIR"��"+HIC"��"+HIG"â��\n"NOR);
	}
	set("is_monitored",1);
	setup();

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
void destruct_me(object where, object me)
{
	object pearl;
        if( pearl=new("/d/npc/obj/jingshi"))
        	pearl->move(where);
	message_vision("$N���е�$nͻ��"HIM"��"HIC"��"HIY"֮"HIG"�⣬һ��ϼ������ʧȥ����ɫ��\n"NOR,where,me);
	destruct(me);
}

