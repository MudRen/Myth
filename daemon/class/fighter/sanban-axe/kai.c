// ����ٵ�
// lestat 2001
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ��"+HIM"������ٵء�"+NOR"��\n");

        if((int)me->query("force") < 150+(int)me->query("force_factor") )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("sanban-axe", 1) <60)
                return notify_fail("������������𻹲�����\n");
        
        if (!PFM_D->valid_family(me, "������"))
                return notify_fail(HIR"������ٵء�"+NOR"�ǽ���������֮�ܣ�\n");



        me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);



        PFM_D->attacking_perform(
                me, 
                        //attacker 
                target, 
                        //target
                (int)me->query_skill("sanban-axe", 1), 
                        //level of skill used
                140, 
                        //success adjustment
                100, 
                        //damage adjustment
                "both", 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "$NͻȻ����һ���������о޸�б���Ͼ���Ȼ���ڰ���л���һ
��Բ�����漴��ֱб��ն��$n����һ˲�䣬$nֻ���ú�����ֹͣ�ˣ�\n" NOR,
                        //initial message
                HIW "���һ�������$n��ͷ����,����һ����Ѫ��\n" NOR, 
                        //success message
                CYN "$n��æ�������Ծ�����ɣ�����ǿ������������һ����\n" NOR, 
                        //fail message
                HIB "���Ǳ�$n������һ�𣬺���һ��,����$N����������\n" NOR, 
                        //backfire initial message
                HIB "�������$n����һ�Ӷ�����\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

//        me->start_busy(2+random(2));
        me->start_busy(1+random(2));

        return 3+random(3);
}


