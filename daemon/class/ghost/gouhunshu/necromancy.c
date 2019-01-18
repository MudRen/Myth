//Cracked by Roath
//Necromancy.c Bual

#include <ansi.h>

inherit F_CLEAN_UP;
int check_skeleton(object me, object target, object guard);
int add_skeleton(object me, object target);
int add_status(object me, object guard, object target, int n);

int cast(object me, object target)
{
	object guard;

	if( !target || !target->query("is_skeleton")) 
		return notify_fail("��Ҫ������һ�����ã�\n");
	
	if( (int)me->query("mana") < 200 ) 
		return notify_fail("��ķ���������\n");

	if( (int)me->query_skill("gouhunshu", 1) < 20 )
		return notify_fail("��Ĺ������ȼ���������\n");

	me->add("mana", -50);

	if( me->query_temp("necromancy")
	&& objectp(guard=present(me->query_temp("necromancy"), environment(me))) ) { 
		check_skeleton(me, target, guard);
		return 1;
	} else {
		add_skeleton(me, target);
		return 1;
	}
}

int add_skeleton(object me, object target)
{
	object guard;
	
	message_vision("$N���ŵ��µ�$n���˼������\n", me, target);

	seteuid(getuid());
	guard = new("/obj/npc/skeleton");
	guard->move(environment(me));
	guard->invocation(me);
	
	message_vision("$N��ҡҡ�λε�վ��������\n", target);

	me->set_temp("necromancy", guard);
	
	destruct( target );

	return 1;
}

int check_skeleton(object me, object target, object guard)
{
	int n;

	n = guard->query("people");

	if( me->query_skill("gouhunshu",1)/20 >= n ) {
		add_status(me, guard, target, n);
		return 1;
	}
	tell_object(me, "��Ĺ������ȼ�������û�����Ƹ�������ñ���\n");
	return 1;
}

int add_status(object me, object guard, object target, int n)
{
	n=n+1;
	guard->set("people", n);

	guard->add("max_kee", 200);
	guard->add("eff_kee", 200);
	guard->add("kee", 200);

	guard->add("max_sen", 200);
	guard->add("eff_sen", 200);
	guard->add("kee", 200);

        message_vision("$N��ҡҡ�λε�վ��������\n", target);

	guard->reset_status();
	destruct( target );
	return 1;
}
