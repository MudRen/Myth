//Cracked by Roath
//evil...........2000.4.16

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;

        extra = me->query_skill("fumo-zhang",1)/10+me->query_skill("staff",1)/10;

        if ( extra < 20) return notify_fail("��ķ�ħ�ȷ�������ȷ����������죬�����޷����ã�\n");

        if(me->query_skill("zhenyuan-force",1) < 100)
                return notify_fail("����ڹ����Ӳ��㣬�޷�������磬ʩչ��������������\n");

        if((string)me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("����������������Ԫ��Ϊ���ӡ�\n");

        if(me->query("max_force") < 500|| me->query("force")< extra*5)
                return notify_fail("����������㣬��������Ӷ�һ�����ȡ�\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۽���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        msg = HIY  "$N����������������֮���һ����磬����"+ weapon->name()+  "Ҳ�����籩������$n������" NOR;

        message_combatd(msg,me,target,"");

        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        lmt = 9;
        for(i=6;i<=lmt;i++)
        {
                me->set_temp("FMZ_perform",i);
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        }
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        me->add("force",-extra*5);
        me->delete_temp("FMZ_perform");
        me->start_busy(3+random(2));
        return 1;
}



