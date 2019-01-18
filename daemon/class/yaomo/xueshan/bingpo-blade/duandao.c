
#include <ansi.h>
#include <weapon.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage, attp, defp;
        object weapon;

        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ʯ��١���\n");
                
        if (!PFM_D->valid_family(me, "��ѩɽ"))
                return notify_fail("��ı��Ǻ����Ǵ�����͵ѧ���ģ�\n");
                
        if(!me->is_fighting())
                return notify_fail("����ʯ��١�ֻ����ս����ʹ�ã�\n");

        if ((int)me->query_skill("bingpo-blade", 1) < 150)
                return notify_fail("��ı��Ǻ������𻹲�����ʹ����һ�л������ѣ�\n");

        if ((int)me->query_skill("ningxie-force", 1) < 150)
                return notify_fail("��ı�����Ѫ�����̫ǳ���޷�������б�����\n");

        if ((int)me->query("force",1) < 160)
                return notify_fail("��������������޷�������б�����\n");

        message_combatd( HIR "$N�����ڵ���Ĭ��������ֻ�������һ������Ȼ��������ҫ��$N����"+ weapon->name() + HIR"����Ϊ����\n"
         + "�أ���������ư���$n���������\n"NOR, me, target, "");

        attp = me->query_skill("ningxie-force",1) + me->query_skill("bingpo-blade",1);
        defp = target->query_skill("dodge");

//      if( random( attp ) > random( defp ) )
        if(  attp  > random( defp ) )
        {
                damage = me->query_skill("bingpo-blade",1) + me->query_skill("blade",1)+ (int)me->query_skill("ningxie-force", 1)*2;
                damage = damage - random( target->query_skill("dodge")/3 );

                target->receive_wound("sen", random( damage ), me, "pfm");
                target->receive_damage("kee", 20 + random(damage)+damage, me, "pfm");
                target->receive_wound("kee", 20 + damage, me, "pfm");
                me->start_busy(3);
                target->start_busy(3 + random(4));
        }
        else 
        {
                message_combatd( HIY "����$p�ζ����Σ�Ѹ�ٵ�������������м��\n" NOR, me, target, "" );
                me->start_busy(2);
        }

        if( !target->is_killing(me) ) me->kill_ob(target);

        me->add("force", -150);
        destruct( weapon );

        return 1;

}


