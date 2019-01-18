//guiwei...2001.3

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 100;
        damage_adj = 100;

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("��Ҫ����˭��\n");

        if((int)me->query_skill("wuxing-quan", 1) < 100 )
                return notify_fail("�������ȭ�����������컹������Դ��λ��\n");
        if (me->query_skill_mapped("unarmed")!="wuxing-quan")
                return notify_fail("��λ�����������ȭ����ʹ�á�\n");
        if (!me->is_fighting())
                return notify_fail("���й�λֻ����ս����ʹ�ã�\n");
        
        if((int)me->query("mana") < 20+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������������ʹ���������Դ��λ��\n");

        if((int)me->query("force") < 100 )
                return notify_fail("��������������޷�����Դ��λ��\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���������ǲ��壬������Դ��\n");

        me->add("mana", -20-2*(int)me->query("mana_factor"));
        me->add("force", -100);
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) 
        {
                write("�㻹��ȥ���ڤ˼�ɡ�\n");
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
                HIW "$NͻȻ˫��˫�ٶ���󺰵�����ľ��ˮ������������Դ���ٹ�λ!ֻ��������ͻȻ������ɫ��������$n��ȥ��\n" NOR,
                        //initial message
                HIC "���$n�������Դ�Ƶ��������ˣ�\n" NOR, 
                        //success message
                HIC "����$n����һ���Ͷ��˿�����\n" NOR, 
                        //fail message
                HIC "���������Դ��$n����ԴӲ�����˻�����\n" NOR, 
                        //backfire initial message
                HIC "��������Դ���Է����ƣ�$n��������ɢ��ȥ��\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(2);
}

