// jinshen.c ��ħ����

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        
	if( target != me ) 
                return notify_fail("��ֻ������ħ�������Լ���\n");
        if( (int)me->query_skill("tianmogong", 1) < 40)
                return notify_fail("�����ħ�����𻹲�����ʹ����һ�л������ѣ�\n");
        if( (int)me->query_skill("huntianforce", 1) < 40)
                return notify_fail("��Ļ��챦�����𻹲�����ʹ����һ�л������ѣ�\n");
        if( (int)me->query("force") < 250 )     
                return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ��н������ˡ�\n");

        skill = me->query_skill("tianmogong",1);

        me->add("force", -250);
        me->receive_damage("kee", 10);

        message_vision(HIY"$N˫Ŀһ�������������дʣ��������¶�ʱ��һƬ�����ס��\n�����������ף�վ�����￴�����������ݡ�\n" NOR, me);

        me->add_temp("apply/armor", skill/2);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
       me->add_temp("apply/armor", - amount/2);
       me->delete_temp("powerup");
       tell_object(me, HIY"��ķ���������������������⽥����ȥ�ˡ�\n"NOR);
}

