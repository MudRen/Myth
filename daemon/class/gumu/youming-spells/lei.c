//��ԯ��Ĺ ������ͨ ��������
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

success_adj = 130;
damage_adj = 130;

        if( me->query("gender") =="Ů��" )
                return notify_fail("Ů���ӿ��ٻ���������Ŷ��\n");

        if( !target ) target = offensive_target(me);

        if( random(me->query("max_mana")) < 850 ) {
                write("���û����ô�෨�����ٻ���������\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ������˭��\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 50 )
                return notify_fail("���޷����о�����׼��\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
                me->receive_damage("sen", 10);

                return 1;
        }

        SPELL_D->attacking_cast(
                me, 
                        //attacker 
                target, 
                        //target
                success_adj,    
                        //success adjustment
                damage_adj,     
                        //damage adjustment
                "both",                 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIW "
$N���һ�������������ҡ�������ж�ʱ�����ܲ�����������\n
ͻȻһ����һ����ɫ����������ڹ������������ɵ�����$n\n" NOR,
                        //initial message
                WHT "���һ�������$n����͸�������$n��ʱ�����Ľ��ڣ�\n" NOR, 
                        //success message
                HIC "ֻ��$nʩչ�Ṧ������Ծ��ÿһ�����綼����߲�����\n" NOR, 
                        //fail message
        HIC "֮��$n˫�۷Ź⣬���һ������ȥ�����羹Ȼ����$N��\n" NOR,
                        //backfire initial message
                HIC "���һ�������$n����͸�������$n��ʱ�����Ľ���\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}


