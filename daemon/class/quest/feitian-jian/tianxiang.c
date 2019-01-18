// feitian-jian.c  ���콣
// Modified by Cody May.2001
// Write by Cody

#include <ansi.h>

inherit SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�����������?\n");

        if( !me->is_fighting() )
                return notify_fail("������������ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( (int)me->query_skill("feitian-jian",1) < 180 )
                return notify_fail("��ķ��콣�ȼ�����������ô��ʹ����������������\n");


        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (me->query("force") < 300)
                return notify_fail("���������̣�����ʹ����������������\n");



        msg = HIR "$Nʹ�������������Ľ�����������������������������ƶ��γ���һ��������\n\n��ס��$n��ȫ��, ʹ$n�������á�\n" NOR;

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 )
        {
                msg +=  HIG "���$p��$P���˸����ֲ���! \n" NOR;
                target->start_busy(6);
                me->add("force", -100);
        }
        else
        {
                msg += HIY "����$p������$P����ͼ����û���ϵ���\n" NOR;
                me->start_busy(2);
        }

        message_vision(msg, me, target);

        
        return 1;  

}

