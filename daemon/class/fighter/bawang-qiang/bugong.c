//Cracked by Roath
//bugong.c ����ǹ��֮����
//writted by libai

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int i , mkee;
        
        int b_time = (int)me->query_skill("bawang-qiang") / 40 + (int)me->query_skill("yanxing-steps") / 40;
        if (b_time < 4) b_time = 4;
        if (b_time > 8) b_time = 10; 

        if( !target ) target = offensive_target(me);

        
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
                return notify_fail("��û��ǹ����ôʹ��������\n");
        
        if (me->query("force") < 200) return notify_fail("�������̫�١�\n");
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "������ԥ�������ŵ������ɡ�\n");
    
        if(environment(me)!=environment(target))
                return notify_fail("��Ҫ�������˲������\n");
        
        if (!PFM_D->valid_family(me, "������"))
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���ò�����\n");

        if( (int)me->query_skill("lengquan-force", 1) < 60 )
                return notify_fail("�����Ȫ�ķ�����Щ���\n");
        
        if( (int)me->query_skill("yanxing-steps", 1) < 80 )
                return notify_fail("������в����޷���ϲ�����\n");
        
        if( (int)me->query_skill("bawang-qiang", 1) < 80 )
                return notify_fail("��İ���ǹ��������죬���ܲ��ò�����\n");

        msg = CYN "$N����"RED"��ǹ"CYN"�Ͷ�����̤�沽����ʱӿ������ɱ����ң��$n���ƹ��ǹ������ط���!
"HIR"����"CYN"һ����$n��ʱ�е�������������������춱�����������ơ�\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*1/6 ) {
                msg += "$n��æ��ǰ�͹�,����ȴ�޴����֣��������������ѵľ��ء�\n" NOR;
                target->start_busy(b_time);
        } else {
                me->start_busy(2);
                msg += "����$nҲ�����ż�,����������м���������\n" NOR;
        }

        message_vision(msg, me, target);
        me->add("force",-200);
        return 1;
}


