// chan.c ������ by stey

#include <ansi.h>

inherit SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("id") != "zhaoyang jian")
           return notify_fail("��û�ó�����������ʹ�þ��У�\n");

        if( me->query("con") < 20 || me->query("str") < 28 )
            return notify_fail("�����������������, ����ʹ�á�����������\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("huxiaojian",1);

        if( !(me->is_fighting() ))
            return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
            return notify_fail("�Է�û��ʹ�ñ��������ò��ˡ�����������\n");

        if( skill < 150)
            return notify_fail("��Ļ�Х�ʽ��ȼ�����, ����ʹ�á�����������\n");

//    ���������ж�by seng@2005-1-20
    if( me->query("family/family_name")!="����ɽ") 
       return notify_fail("�㲻������ɽ��, ����ʹ�á�����������\n");


        if( me->query("force") < 300 )
            return notify_fail("��������������޷����á�����������\n");

        msg = HIC "$N����"YEL"������"HIC"����һ����⣬б��һ����������������
"YEL"������"HIC"�������ò���$n��"+weapon2->name()+"�ϡ�\n";
    message_combatd(msg, me, target, "");

        damage = 100 + random(skill);
        ap = me->query_skill("sword")/3 + skill;
        dp = target->query_skill("dodge")/2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > random(dp) )
        {
            if(userp(me))
                 me->add("force",-50);
            msg = "$n��ʱ������ǰ���һ��������һ������";
            msg += weapon2->name();
            msg += "���ַɳ���\n" NOR;
            me->start_busy(random(2));
            target->receive_damege("kee", damage,me,"pfm");
            target->start_busy(2);
            weapon2->move(environment(me));
        }
        else
        {
            if(userp(me))
                 me->add("force",-50);
            msg = "$n����������������" + weapon2->name()+
"бб˳��һ��һ����˻�����\n"NOR;
            me->start_busy(3);
        }
    message_combatd(msg, me, target, "");

        return 1;
}
