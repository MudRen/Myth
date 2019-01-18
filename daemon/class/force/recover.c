// recover.c

inherit SSERVER;

int exert(object me, object target)
{
	int diff, neilineed;

	if( target != me ) return notify_fail("��ֻ�����ڹ������Լ�����Ϣ��\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("�������������\n");
    if( (int)me->query_skill("force") < 10 )
		return notify_fail("����ڹ���Ϊ������\n"); 

	diff = me->query("eff_kee") - me->query("kee");
	neilineed = diff * 50 / (int)me->query_skill("force");
    if(neilineed < 1)
	   return notify_fail("�������������棬����������\n");
    
	if(neilineed > me->query("force")) neilineed = me->query("force");
    diff = neilineed * (int)me->query_skill("force") / 50;
    
	me->receive_heal("kee", diff );
	me->add("force", -neilineed);

	message_vision("$N�������˼���������ɫ�������ö��ˡ�\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}
