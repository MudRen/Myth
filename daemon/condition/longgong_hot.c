//Longgong_hot.c
int update_condition(object me, int duration)
{
        int limit, shaqi;

        limit = (int)me->query("cor")*50 + (int)me->query("max_force");
	shaqi = (int)me->query("bellicosity");

        me->apply_condition("longgong_hot", duration - 1);

        if( shaqi > limit
        &&      living(me) ) {
                me->unconcious();
        } else if( !living(me) ) {
message("vision", me->name() + "���������Ũ�̣�ȴ��Ȼ���Բ��ѡ�\n",environment(me), me);
		return 0;
        } else if( shaqi > limit/2 ) {
                tell_object(me, "����ø��������һ�㣬����Ҫը��һ����\n");
                message("vision", me->name() + "һ���죬�ƺ��³����Ż��ǣ��ٱ��ұš�\n",environment(me), me);
                me->receive_damage("sen", 30);
		me->add("bellicosity", 30);
        } else if( shaqi > limit/4 ) {
                tell_object(me, "�������ͬ��¯һ���յ����ܡ�\n");
                message("vision", me->name() + "����ð������������̡�\n",environment(me), me);
                me->receive_damage("sen", 20);
		me->add("bellicosity", 20);
        } else {
		tell_object(me, "����ø�������һ�Ż�����һ����\n");
                message("vision", me->name() + "ͷ��ð��˿˿���̡�\n",environment(me), me);
                me->receive_damage("sen", 10);
                me->add("bellicosity", 10);
	}

	me->add("potential", 10);

        if( !duration ) return 0;
        return 1;
}

