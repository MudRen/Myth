//by dewbaby@sk_sjsh

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage;
        int sp, texp;
        int exd;
        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("spells") < 20 )
                return notify_fail("��ķ����������ߣ�\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�����¡���\n");

        if((int)me->query("mana") < 100 )
                return notify_fail("��ķ���������\n");

        if((int)me->query("force") < 200 )
                return notify_fail("����������������������Ҫ����֧�֡�\n");

        if((int)me->query("kee") < 50 )
                return notify_fail("�����Ѫ̫�ͣ������������̫�ðɣ�\n");


        if((int)me->query("sen") < 150 )
                return notify_fail("��ľ���û�а취��Ч���У�\n");

         if((int)me->query("max_mana") < 200 ) 
                return notify_fail("�㷨��������\n");

        me->add("mana", -100);
        me->receive_damage("sen", 20);

            msg = HIM
"$N��������˫Ŀˮ�����١��������ĳ��죬����ָ��$n\n
$n"HIW"ֻ����ǰһƬ�׹���ҫ���������ɵ�����������\n
$NͻȻЦ��$n"HIM"�����в�������ɫ�裬����裬˭��������?��\n"
NOR;

        sp = me->query_skill("spells");
        exd = sp/2;
        texp = target->query("combat_exp");

        if( random(sp + texp) > texp ) {
         damage = sp/3 + (int)me->query_skill("force")/5  + random(exd);
                if( damage > 0 ) {
        msg +=  HIR "$n"HIR"��վ��ԭ�أ���Ȼ����$N"HIR"���ʻ��������㱵ش��������ů��Ũ�ƾƴ������˲࣬����Ⱦ̴��...��\n"NOR;

         target->receive_wound("sen", damage/3,me,"cast");
         target->receive_damage("kee",damage/3,me,"cast");
          } else
          msg += HIW"���$n"HIW"��$N"HIW"��������޷�Ӧ���������ӳ���n"NOR;
          message_vision(msg, me, target);
          COMBAT_D->report_status(target);
    }

         me->start_busy(1);
        return 1;
}


