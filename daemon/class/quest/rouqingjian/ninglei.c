//��ָ���齣 ���������
//by junhyun@SK

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����������\n");

        if(!me->is_fighting())
                return notify_fail("���������ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 100 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("rouqingjian", 1) < 150)
                return notify_fail("�����ָ���齣���𻹲������޷�ʹ�á����������\n");

               weapon=me->query_temp("weapon");

        if( me->query("env/brief_message") ){
                i=1;
        } else {
                i=0;
        }
        if( target->query("env/brief_message") ){
                j=1;
        } else {
                j=0;
        }

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIW"
�㽣��Խ��Խ�죬�������䣬������ˣ�ͻȻһ����Х��������
�������ΰ���������������л���һ�������Ļ��ߣ�˼������
�ữ���ޱߵĽ���
\n\n\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
 message_vision(HIW"������\n"NOR, me);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
 message_vision(HIW"�����\n"NOR, me);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
 message_vision(HIW"�����\n"NOR, me);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
 message_vision(HIW""NOR, me); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                if( i ) me->set("env/brief_message", 1);
        if( j ) target->set("env/brief_message", 1);

        me->receive_damage("kee", 100);
        me->add("force", -10);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1);
        return 1;
}

