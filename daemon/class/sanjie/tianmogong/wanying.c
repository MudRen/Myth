inherit SSERVER;

int cast(object me, object target)
{
	int wanying_time;
	object soldier;

	if( !me->is_fighting() )
		return notify_fail("ֻ��ս���в���ʹ�á���Ӱ���١���\n");

	wanying_time=60+(200-(int)me->query_skill("spells"));
	if(wanying_time<60) wanying_time=60;
	if((time()-me->query("last_wanying"))<wanying_time)
		return notify_fail("��ո��ù���Ӱ���٣����ô˷�������Ҳ�������ţ�\n");
	if( (int)me->query("mana") <4*(int)me->query_skill("spells"))
		return notify_fail("��ķ��������ˣ�\n");
	if( (int)me->query("sen") < 50 )
		return notify_fail("��ľ����޷����У�\n");

	message_vision("$N�૵����˼������\n", me);

	if( random(me->query("max_mana")) < 200 ) {
		me->add("mana",-(int)me->query_skill("spells"));
		me->receive_damage("sen",10);
		message("vision", "����ʲôҲû�з�����\n", environment(me));
		return 1;
	}

	me->add("mana", -4*(int)me->query_skill("spells"));
	me->receive_damage("sen", 40);

	seteuid(getuid());
	soldier = new("/daemon/class/sanjie/obj/npc/wsjiashen");

	soldier->move(environment(me));
	soldier->invocation(me);
	soldier->set_temp("invoker",me);
	me->set("last_wanying",time());
	me->start_busy(2+random(2));

	return 8+random(5);
}
