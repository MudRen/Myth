//���з�ʬ
//by junhyun@SK
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        int extra;
        object weapon1;

        if(!target) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����з�ʬ����\n");

        if(!me->is_fighting())
                return notify_fail("�����з�ʬ��ֻ����ս����ʹ�ã�\n");

        if (!PFM_D->valid_family(me, "��ԯ��Ĺ"))
                return notify_fail("�ǹ�Ĺ���Ӳ����á����з�ʬ����\n");

        if((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 250)
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("mohuang-blade",1) < 200)
                return notify_fail("���ħ�ʵ�����������죬ʹ����һ�л�������!\n");


        weapon1=me->query_temp("weapon"); 

        extra = me->query_skill("mohuang-blade",1);

        message_vision(HIR"\n
$NĬ�˾�����������������������֣�����"+weapon1->query("name")+HIR"�������Ƶ�ͨ�죬
ͻȻ������⣬�绮����ʵ������ֱ��$nȫ��Ҫ��!\n"NOR, me, target);

        if(!target->is_busy()) target->start_busy(2);

        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        COMBAT_D->do_attack(me, target, weapon1);
        COMBAT_D->do_attack(me, target, weapon1);
        COMBAT_D->do_attack(me, target, weapon1);
        COMBAT_D->do_attack(me, target, weapon1);

        message_vision(HIR"\n
$nȫ���ʱ��$N�����������˿ڣ�����$n�����мܵ�ʱ��$N����
һ����������һ�����εı�����$n��ȥ��$N˫�ַ��裬������ʩ��
��ʱ�����������б������"NOR, me, target);


        COMBAT_D->do_attack(me, target, weapon1);
        COMBAT_D->do_attack(me, target, weapon1);
        COMBAT_D->do_attack(me, target, weapon1);
        COMBAT_D->do_attack(me, target, weapon1);

        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra);

        me->receive_damage("sen", 100);
        me->add("force", -100);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }


        me->start_busy(2);

        return 1;
}

