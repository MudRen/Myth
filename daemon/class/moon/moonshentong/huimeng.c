// ����
// requirement: spells 180,moonshentong 120, mana 400, sen 20

inherit SSERVER;
#include <ansi.h>

int cast(object me, object target)
{
        string msg;
        int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;

        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("spells") < 180
         || (int)me->query_skill("moonshentong",1) < 120)
                return notify_fail("�㻹ûѧ������䡣����\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("������˭���Σ�\n");  

        if((int)me->query("mana") < 400 )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("���޷����о�����\n");
        
        if (!living(target)) return notify_fail("�������Ҫ��\n");

        me->add("mana", -400);
        me->receive_damage("sen", 20);

        msg = HIM
                "$N������$n��˫�ۣ����������$n��ͷ����$n�����������ţ���С��������˯����������\n"
                +"$n��ʱ�������������ȫ��������\n"NOR;

        success=1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("daoxing")/2;
        dp = target->query("daoxing");

        if (target->is_fighting(me)) dp=dp*2;
        if ( random(ap+dp)<dp ) success=0;
    
        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp)<dp ) success = 0;

        if(success == 1 )
        {
                msg +=  HIM"$n��֪�����Ĺ�Ƿ��������Ƥ���أ�����֧�ֲ�ס��������˫�ۡ�\n"NOR;
                message_vision(msg, me, target);

                target->set_temp("force_sleep",1);
                if(target->is_fighting()) 
                        target->command_function("surrender");
                if (!target->command("sleep")) 
                        message_vision(HIM"\n$N���˻��Դ����ƺ������˲��٣��ְ��۾������ˡ�\n"NOR,target);
                target->delete_temp("force_sleep");
                me->start_busy(1+random(2)); 
        }           
        else 
        {
                msg +=HIM"$n�������ף����һ����˫Ŀһ�ţ��������䣡$N⧲�����������һ����\n" NOR;      
                message_vision(msg, me, target);
                if( living(target) ) me->kill_ob(target);
                me->start_busy(5+random(5));

        } 

        return 1;
}

