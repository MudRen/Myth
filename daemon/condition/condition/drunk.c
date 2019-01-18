// drunk.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

//	limit = (me->query("con") + (int)me->query("max_force") / 50) * 2;

	// 10/13/98 mon adjusted drunk limit.
	// increased basic tolerance and reduced force effect.
	limit = me->query("con")*6+(int)me->query("max_force")/50;

	if( duration > limit
	&&	living(me) ) {
		me->unconcious();
		return 0;
	} else if( !living(me) ) {
		message("vision", me->name() + "���˸�����������Ȼ�������ࡣ\n",
			environment(me), me);
	} else if( duration > limit/5 ) {
		tell_object(me, "��������л�������������ƮƮ�أ���������ˡ�\n");
		message("vision", me->name() + "ҡͷ���Ե�վ��վ���ȣ���Ȼ�Ǻ����ˡ�\n",
			environment(me), me);
		me->receive_damage("sen", 10);
	} else if( duration > limit/10 ) {
		tell_object(me, "�����һ������ϳ壬��Ƥ��Щ�����ˡ�\n");
		message("vision", me->name() + "�����Ѿ����Ծ����ˡ�\n",
			environment(me), me);
		me->receive_damage("sen", 3);
		//me->receive_healing("gin", 4);
		//me->receive_healing("kee", 4);
	}

	me->apply_condition("drunk", duration - 1);
	if( !duration ) return 0;
	return 1;
}
