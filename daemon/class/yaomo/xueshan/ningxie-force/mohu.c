// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//bula, 1/22

#include <ansi.h>

//inherit F_CLEAN_UP
inherit SSERVER;

int exert(object me, object target)
{
        string msg;
        int skill, damage;
        target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("����֮��ֻ����ս����ʹ�ã�\n");

        if( (int)me->query("force") < 400 )
                return notify_fail("�������������\n");

        skill = me->query_skill("force");
   
        msg = HIR "$NͻȻ��ɫһ�䣬�ֳ�һ�����Σ��ּ��ֳ���������$n�ľ�����ȥ��\n";
        me->start_busy(1+random(1));
        me->receive_damage("kee", 50);
        me->add("force", -100);

        if((int)me->query_int()  > (int)target->query_int()/2 +random(30) ) 
        {
                damage = skill - ((int)target->query("max_force")/10);
                if( damage > 0 ) 
                {
                        msg += "(ֻ��һƬ��Ѫ���$n�ľ�����ҧ��һ��Ѫ����)\n\n" NOR;
                        target->receive_wound("kee", damage, me, "exert");
                        me->add("bellicosity", damage/2);
                }
                else msg += "�����Ƥ��û���ƣ�\n" NOR;
        }
        else msg += "�����$n�㿪�ˣ�\n" NOR;

        message_vision(msg, me, target);
        return 1;
}

