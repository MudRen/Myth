//jiz
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("��ֻ���ֳ��Լ�������\n");

        if( (int)me->query("force") < 300 )     
                return notify_fail("�������������\n");
	if( (int)me->query("kee") < 150 )
		return notify_fail("�����Ѫ���㡣\n");
	if( (int)me->query("sen") < 150 )
		return notify_fail("��ľ����㡣\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");
	if( me->query_temp("weapon") )
		return notify_fail("��ֻ�з������������ֳ�����\n");


        skill = me->query_skill("dragonforce",1);

	if ( skill>=250 ) skill=250;

        me->add("force", -300);
        me->receive_damage("kee", 130);
	me->receive_damage("sen", 130);

        message_vision(
HIC"$N�������������һ����Ѫ��֮������Ϊһ��������צ�Ĳ������˵�ɱ�����ˡ�\n"NOR, me);

	me->set_temp("No_Wield", 1);

        me->add_temp("apply/armor", skill/5);
	me->add_temp("apply/damage", skill/5);
	me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/strength", skill/5);

        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :),skill);

        if( me->is_fighting() ) me->start_busy(5);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/strength", -amount);
	me->delete_temp("No_Wield");
        me->delete_temp("powerup");
        tell_object(me, "��������ķ�����һ������ϣ�����Ҳ������ԭ�ˡ�\n");
	return;
}

