//cast function: escape.c �����ڸ����Ӷݡ�
//useful only when fighting, other cases only waste fali.
//modified for wudidong, 10-4-97 pickle

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg,start;
	int ap, dp, success;
	target = offensive_target(me);
	//always use the one who is fighting me as target.

	if( me->is_busy())
		return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
		return notify_fail("�㾫��̫����Լ��о������䡣\n");

	if( (int)me->query_skill("yaofa", 1) < 20)
		return notify_fail("��δ��ѧ�����ݡ�\n");

	if(environment(me)->query("under_water"))
		return notify_fail("����ˮ�У�û��ʩ�����ݣ�\n");

	ap=me->query_skill("spells")+me->query("max_mana")/10;
	if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

	if(!me->is_fighting() )
	{
		message_vision(YEL"$N���������һ����������䣬�������в����ˡ�\n"NOR,me);
		me->add("sen", -me->query("max_sen")/8);
		me->add("mana", -80);
		success=1;
	}
	else
	{
		msg=YEL"��ս�У�$NͻȻ����սȦ���������һ�����������˼����䡣\n"NOR;
		if(random(ap+dp)>dp/2)
		{
			msg+=YEL"ֻ��$N����һ�����ߣ�������Ӱ�Ѿ������ˡ�\n"NOR;
			me->add("sen", -me->query("max_sen")/6);
			me->add("mana", -50);
			success=1;
		}
		else msg+=YEL"��$n����Ӱ�ѽ������ϣ���$N����������\n"NOR;
		me->add("mana", -50);
		message_vision(msg, me, target);
	}
	if(success)
	{
		start=me->query("env/destination");
		start=me->query("�Ǻ�/"+start);
		if(!start || !find_object(start))
			start=me->query("startroom");
		if(!start) start="/d/qujing/wudidong/kitchen";
		me->move(start);
		message("vision", YEL+me->name()+"ͻȻ�ӵ������˳�����\n"NOR,
				  environment(me), me);
		tell_object(me, YEL"�����ӰͻȻ������һ�����С�\n"NOR);
		return 3+random(3);
	}
	return 5+random(5);
	//if failed, can't use for a while.
}

