//by dewbaby@sk_sjsh
//�Ž������

#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
        int lvl;
        object weapon;
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ���������\n");

        if( (int)me->query_skill("kongwujian", 1) < 120 )
                return notify_fail("��Ŀ��޽�������죬�޷�ʩչ�����������\n");
        if ((int)me->query_skill("linghai-force", 1) < 120)
                return notify_fail("����躣�ķ���򲻹����޷�ʩչ�����������\n");
        if ((int)me->query_skill("lingbo-steps", 1) < 120)
                return notify_fail("����貨΢����򲻹����޷�ʩչ�����������\n");
        if ( (int)me->query("max_force") < 2000)
                return notify_fail("��������������޷�ʩչ�����������\n");
        if ( (int)me->query("force") < 500)
                return notify_fail("��������������޷�ʩչ�����������\n");
        if ((int)me->query("kee") < 500)
                return notify_fail("�����Ѫ�������޷�ʩչ�����������\n");
     
        lvl = me->query_skill("kongwujian", 1);
     message_vision(WHT"$N��������ؿ���$n��\n\n"NOR,me,target);
     message_vision(WHT"$N��������ͻȻ����"+ weapon->name() +HIY"��Ϊ�ŵ���ɫ������$n��ȥ��\n"NOR,me, target);
 
        me->add("force", -(200 +random(100)) );
        me->add("kee", -50);
        me->add_temp("apply/attack",lvl/2);
        me->add_temp("apply/damage",lvl/2);
        me->add_temp("apply/sword", lvl/3);

        message_vision(HIY"$N������磬���н���Ӱ�䲻�ϣ�\n"NOR,me,target);
message_vision(WHT"$n"+WHT"����ӭ������Ľ����Ƶ��������ˣ��ƺ���Ϊ������\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
message_vision(HIY"һ��                  "+BLINK+HIC+"����������\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"����             "+BLINK+WHT+"����������\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"����             "+BLINK+HIB+"����������\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�Ľ�             "+BLINK+HIW+"�޵�������\n"NOR,me,target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�彣             "+BLINK+BLU+"�ٱ�Ӱ��Ѱ\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"����             "+BLINK+HIR+"��¥����Ъ\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�߽�             "+BLINK+HIC+"�����״���\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�˽�             "+BLINK+HIM+"ȥ�������\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision(HIY"�Ž�             "+BLINK+WHT+"���������\n"NOR,me,target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->start_busy(2+random(1));
        me->add_temp("apply/attack", -lvl/2);
        me->add_temp("apply/damage", -lvl/2);
        me->add_temp("apply/sword", -lvl/3);
        return 1;
}


