// mantian.c ժ���� �������ǡ�

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
//        string mantian;
      string msg;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if((int)me->query_skill("dangmo-xinjing",1) < 100)
                return notify_fail("�㵴ħ�ľ��ļ��𲻹�����ʹ��������!\n");

        if((int)me->query_skill("zhaixing-shou",1) < 100)
                return notify_fail("���ժ������Ϊ����,Ŀǰ������ʹ�������Ǿ���!\n");       

        if((int)me->query("force") < 200)
                return notify_fail("���������ڲ���, ����ʹ��������! \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

        message_vision(HIY"$Nʹ��ժ���־����������ǡ���˫��ʮָ��������ס��$n��ȫ��ҪѨ��\n"NOR,me,target);

        if( random(me->query("combat_exp")) > target->query("combat_exp") / 4 ) {
        message_vision(HIY"$N��֪����м��Ǻã���������ߴ�Ѩ�����ƣ���ʱ�������ã�\n"NOR,target);
                target->start_busy(me->query_skill("zhaixing-shou",1) / 20 - 1);
                me->add("force", -150);
        } else {
                message_vision(HIG "$N�������һԾ���ܿ�����һ�С�$n�������ϣ��Լ�����¶����������\n" NOR,target,me);
                me->start_busy(1+random(3));
        }
//        message_vision(mantian, me, target);

        return 1;
}

