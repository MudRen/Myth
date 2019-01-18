#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return
notify_fail("��ֻ���þ��ľ�����Լ��ľ�����\n");

        if( (int)me->query("force") < 200 )     
                return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("lengquan-force",1);

        me->add("bellicosity", -skill/2);
	if((int)me->query("bellicosity") <= 0){
		me->set("bellicosity", 1);
	}
        me->add("force", -100);

        message_vision(
                HIR
"$N΢һ���������ľ�����ʱ��ƽ���ȣ�����Χһ�о����мӡ�\n"NOR, me);

        me->add_temp("apply/dodge", skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,
skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", -amount);
        me->delete_temp("powerup");
        tell_object(me,
"��ľ��ľ�����һ������ϣ��������ջص��\n");
}

