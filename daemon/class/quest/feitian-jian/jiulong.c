// feitian-jian.c  ���콣
// Modified by Cody May.2001
// Write by Cody

#include <ansi.h>

inherit SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int i;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ͷ������?\n");

        if( !me->is_fighting() )
                return notify_fail("����ͷ������ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( (int)me->query_skill("feitian-jian",1) < 140 )
                return notify_fail("��ķ��콣�ȼ�����������ô��ʹ������ͷ��������\n");

        if (me->query("force") < 300)
                return notify_fail("���������̣�����ʹ������ͷ��������\n");
        

        msg = HIG "$Nʹ�������������Ľ�������ͷ����������������Ÿ����򷢳�������\n\n" NOR;
        message_combatd(msg, me, 0, "");

        me->clean_up_enemy();
        ob = me->select_opponent();
        
        for(i=0;i<9;i++)
        {
                message_combatd(HIW"ֻ��һ������ֱ����$n��"NOR, me, ob, "");
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        }
                
        me->add("force", -300);
        me->start_busy(3);



        return 1;  

}

