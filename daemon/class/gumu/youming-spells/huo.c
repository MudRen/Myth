//��ԯ��Ĺ ������ͨ ��������
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

success_adj = 130;
damage_adj = 130;

        if( me->query("gender") =="����" )
                return notify_fail("�ɰ����������������˵�\n");

        if( !target ) target = offensive_target(me);

        if( random(me->query("max_mana")) < 850 ) {
                write("���û����ô�෨�����ٻ�����\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ�ٻ�����ҧ˭��\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 50 )
                return notify_fail("���޷����о����ٻ���\n");

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
                MAG "
$N���ĵ�һЦ�����������дʣ�ͻȻ��$N����������������Ů\n
$n���ڲ����У�ֻ����Ů������������ʱ����������ɫ�������˹���\n\n" NOR,
                        //initial message
                WHT "$n��ʧ�룬��ֻ���Ӧ�ԣ�������ҧ�ı������ˣ�\n" NOR, 
                        //success message
                HIC "$n���Ų�æ������һ�ӣ������Һ�һ������ʱ�ҷ�����\n" NOR, 
                        //fail message
        HIC "֮��$n˫�۷Ź⣬���һ������ȥ��������Ȼ����$N��\n" NOR,
                        //backfire initial message
                HIC "���$n�������Լ�������ҧ�ı������ˣ�\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}


