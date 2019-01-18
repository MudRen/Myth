//modified by vikee
//2000.12.11

inherit F_CLEAN_UP;

int cast(object me, object target)
{
        if( !me->is_fighting() )
                return notify_fail("��ֻ����ս���в���ʹ�ø�������\n");
        
        if( !target || !target->is_corpse() ) return notify_fail("��Ҫ������һ��ʬ�壿\n");
        
        if( (int)me->query("mana") < 200 ) return notify_fail("��ķ���������\n");

        message_vision(
                "$N�������ϵ�$n�૵����˼������$n�鴤�˼��¾�վ��������\n", me, target);

        target->animate(me);

        me->add("mana", -50);
        me->receive_damage("sen", 50);

        return 3+random(5);

}
