//Cracked by Roath

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 50 )
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("��ľ����޷����У�\n");

        if (!PFM_D->valid_family(me, "���޵ظ�"))
                return notify_fail("�����Ž��Լ���Ϊ���壬��Ѫ��֮��ȴ��ôҲ��������\n");

        message_vision("$N�૵����˼������\n", me);

        me->add("mana", -25);
        me->receive_damage("sen", 20);

        if(me->is_fighting() ) {
                if(random((int)me->query("max_mana")) >(int)target->query("max_mana")/2) {
                        message_vision(HIC"$N�������һ�ɺڷ磬������Ҳ���źڷ�ɢȥ������\n"NOR, me);
                        me->move("/d/death/gate");
                        tell_room(environment(me),
HIC"һ�����������Լ�ֳ�"+me->query("name")+"��Ӱ�ӡ�\n\n"NOR, ({me, me}) );

                } else {
                        message_vision(HIC"$Nת�����ܣ�ȴ��$nһ��������ס��\n"NOR, me, target);
                        me->start_busy(2);
                }
        } else {
                message_vision(HIC"$N�������һ�ɺڷ磬������Ҳ���źڷ�ɢȥ������\n"NOR, me);
                me->move("/d/death/gate");
                tell_room(environment(me),
HIC"һ�����������Լ�ֳ�"+me->query("name")+"��Ӱ�ӡ�\n\n"NOR, ({me, me}) );

        }

        return 5+random(5);
}


