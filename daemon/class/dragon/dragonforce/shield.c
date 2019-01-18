//jiz
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("��ֻ���������ķ������Լ���\n");

        if( (int)me->query("force") < 100 )     
                return notify_fail("�������������\n");
	if( (int)me->query("kee") < 50 )
		return notify_fail("�����Ѫ���㡣\n");
	if( (int)me->query("sen") < 50 )
		return notify_fail("��ľ����㡣\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");

        me->add("force", -100);
        me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);

        message_vision(
                HIC"$N΢һ�������������ķ����������¶�ʱ�������ɫ�����ۡ�\n" NOR, me);

        me->add_temp("apply/armor", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->delete_temp("powerup");
        tell_object(me, "��������ķ�����һ������ϣ����۽�����ȥ�ˡ�\n");
	return;
}

