// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{

        string msg;

        int i, lmt, damage ;
        object weapon;

        if( (int)me->query_skill("sword") < 90 ||
            me->query_skill_mapped("sword") != "xuantian-sword")
                return notify_fail(HIW "��ġ����콣�����������ң��޷�ʹ�á�������ѩ����\n"NOR);
        if ((int)me->query("force",1) < 500)
                return notify_fail("��������������޷�ʹ�á�������ѩ����\n");           
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIW "��������ѩ��ֻ�ܶ�ս����ʹ�á�\n"NOR);
        weapon = me->query_temp("weapon");
        msg = HIY  "$N��Хһ�������ж�Ю����֮ʽ�������͵ı������ߣ����е�\n"+ weapon->name()+  "���籩������$n������\n\n" NOR;
        message_vision(msg,me,target);
        if( !target->is_killing(me) ) target->kill_ob(me);
                damage = me->query_skill("xuantian-sword",1) + (int)me->query_skill("dangmo-xinjing", 1);
                damage = damage - random( target->query_skill("dodge")/3 );
        lmt = random(5)+3;
        for(i=1;i<=lmt;i++)
        {
        msg =  HIW "$N���һ�����ӵ�"+chinese_number(i)+"����\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }

//      target->receive_wound("jing", random( damage/20 ));
        target->receive_damage("kee", 20 + random(damage),me,"pfm");
        target->receive_wound("kee", 20 + damage,me,"pfm");
        me->add("force", -80);
        me->start_busy(4);
        return 1;
}

