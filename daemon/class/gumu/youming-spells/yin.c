//��ԯ��Ĺ ������ͨ ����
//by junhyun@SK
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 50 )
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("��ľ����޷����У�\n");

        if (!PFM_D->valid_family(me, "��ԯ��Ĺ"))
                return notify_fail("����Ц�ɣ��㲻�ǹ�Ĺ������ô���ٻ�����\n");

        message_vision("$N�૵����˼������ġ�\n", me);

        me->add("mana", -25);
        me->receive_damage("sen", 20);

        if(me->is_fighting() ) {
                if(random((int)me->query("max_mana")) >(int)target->query("max_mana")/2) {
                        message_vision(HIB"����һ�ӣ�ƽ������һ�ź���˲���Χ��$N��ʧ����Ӱ����......\n"NOR, me);
                        me->move("/d/gumu/beiji");
                        tell_room(environment(me),
HIB"ͻȻ����һ�����"+me->query("name")+"�Ӻ��������˳�����\n\n"NOR, ({me, me}) );

                } else {
                        message_vision(HIW"$Nת�����ܣ�ȴ��$nһ��������ס��\n"NOR, me, target);
                        me->start_busy(2);
                }
        } else {
                message_vision(HIB"����һ�ӣ�ƽ������һ�ź���˲���Χ��$N��ʧ����Ӱ����......\n"NOR, me);
                me->move("/d/gumu/beiji");
                tell_room(environment(me),
HIB"ͻȻ����һ�����"+me->query("name")+"�Ӻ��������˳���\n\n"NOR, ({me, me}) );

        }

        return 5+random(5);
}

