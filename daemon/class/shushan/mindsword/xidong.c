//Cracked by Roath
//Ansi 99.12

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int i;
        int f_time;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ���Ķ���������\n");

        if(!me->is_fighting())
                return notify_fail("���Ķ�������ֻ����ս����ʹ�ã�\n");
                
        if (!PFM_D->valid_family(me, "��ɽ����"))
                return notify_fail("������ɽ�Ĳ����á��Ķ���������\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("mindsword", 1) < 80)
                return notify_fail("����Ľ���Ϊ��������ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        me->add_temp("apply/attack", (int)(me->query_skill("mindsword",1)/6));
        me->add_temp("apply/damage", (int)(me->query_skill("mindsword",1)/6));
        message_vision(HIW"\n$N���о���ʩչ�Ľ��ġ��Ķ�����������$n�������Ĺ�����\n"NOR,me,target);
        message_vision(HIR"\n�Ķ��Ķ������ķ��\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIR"\n�Ķ��Ķ�������ŭ�ţ�\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIR"\n�Ķ��Ķ����Ľ���һ��\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/attack", -(int)(me->query_skill("mindsword",1)/6));
        me->add_temp("apply/damage", -(int)(me->query_skill("mindsword",1)/6));
        if( me->query_temp("shushantop")) 
        {
                if( living(target)) 
                        target->receive_damage("kee",5*((int)me->query_skill("sword",1)),me,"pfm");
                        message_vision(HIR"\n$NͻȻʹ���Ľ��������У����ȶ�����\n$n�ܵ������ص��˺���\n"NOR,me,target);
        }
        me->receive_damage("sen", 100);
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

