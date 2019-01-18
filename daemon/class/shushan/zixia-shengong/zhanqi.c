// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;


        skill = me->query_skill("zixia-shengong",1); 

	if( skill > 250 ) {
		skill=250;
	}

        if( (int)me->query("force") < skill*2 )     
		return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
 HIR "$N������Ŀ�����ȼ�����Լ���С���棬������Լ��Ĺ�����������\n" NOR, me);

        me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/strength", skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
	me->add_temp("apply/strength", - amount);
        me->delete_temp("powerup");
tell_object(me, "���С�����Ѿ�ȼ�վ��ˣ����ǸϿ��չ��ɡ�\n");
}

