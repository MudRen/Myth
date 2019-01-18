#include <skill.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("��ս��", ({"peace seal", "seal", "paper"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","һ�Ż����˷�����ҷ�ֽ�������и����ġ���ս���֡�
������ս���м�(burn)֮��\n");
        set("unit", "��");
        set("value", 0);
	set("no_put",1);
	set("no_sell",1);
	}
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
	add_action("do_burn", "burn");
}

void destruct_me(object where, object me)
{
        object seal;
        if( seal=new("/obj/paper_seal"))
                seal->move(where);
	message_vision("$N���е�$nͻ����⣬���佥����ȥ�����ˡ�\n",where,me);
        destruct(me);
}

int do_burn(string arg)
{
	object seal=this_object();
	object me=this_player();

	if(!arg || (arg!="peace seal"
                        && arg!="seal"
                        && arg!="paper") )
		return notify_fail("��Ҫ��ʲô��\n");

	if(me->is_busy())
		return notify_fail("����æ���أ��޷�����ս����\n");
	if(!me->is_fighting())
		return notify_fail("��ֻ����ս���в�������ս����\n");
	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ������ܿ�����ս����\n");
	if( (int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬���Ѽ�Ԧ��ս����\n");


	tell_room(environment(me),
me->name()+"��һ�����š�����һ�ӣ�������һ����ս��������\n\n");
	tell_room(environment(me),
"��ս����������һ�·ɵ���գ������������������ѭ������Ӧ��ˬ����λ���ǵ����˴������˰ɣ�����������\n");



	if( random( (int)me->query_kar()+ (int)me->query_cps()) > 20 )	{

		tell_room(environment(me),"\n��������������������ͣ��������\n");
		me->remove_all_killer();

	} else {
		tell_room(environment(me), "\n˭֪û�����ӣ�������ɱ��\n");

	}
	me->add("mana",-50);
        
        me->start_busy(2+random(2));



	destruct(seal);
	return 1;
}
