//Cracked by Roath
// powerfade.c

#include <ansi.h>

inherit F_CLEAN_UP;


int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("��ֻ���÷�����������ѹ���Լ���ɱ����\n");

        if( (int)me->query("force") < 100 )     
                return notify_fail("�������������\n");
        if( me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");
        if( (int)me->query("bellicosity") <= 0 )
                return notify_fail("�����ں���ɱ����\n");

//        skill = me->query_skill("force");
        skill = me->query_skill("tonsillit",1);

        me->add("bellicosity", - 50 - skill/3 );
        me->add("force", -100);
        if(me->query("bellicosity") <0) me->set("bellicosity",0);
        me->receive_damage("sen", 100);

        message_vision(
                HIC
"$N��ϥ���£�˫��΢�գ���������������ѹ�����е�ɱ��������\n" NOR, me);

        if( me->is_fighting()
        &&      (random(skill) < (int)me->query("cps") ) )
                me->unconcious();

        return 1;
}

