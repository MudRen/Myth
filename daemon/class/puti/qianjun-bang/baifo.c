#include <ansi.h>
inherit SSERVER;

string get_name(string str)
{
        str="�ݷ���ʽ";
        return str;
}

string get_help(string str)                
{
        str="ָ��: ��������������\n"
        +"������ǧ����������120���������������1200��ÿ��һ������100�����200������"
        +"Ѹ����Է��������У����������ù�����һ���⡣";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        int extra;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С��ݷ���ʽ����\n");
        if(!me->is_fighting())
                return notify_fail("���ݷ���ʽ��ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 1200 )
                return notify_fail("�������������\n");
        if((int)me->query("sen") < 600 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("qianjun-bang", 1) < 120)
                return notify_fail("���ǧ�������𻹲�����ʹ����һ�л������ѣ�\n");
        if (!PFM_D->valid_family(me, "����ɽ���Ƕ�"))
                return notify_fail("�ݷ���ʽ�Ƿ���ɽ���Ƕ��Ĳ���֮�أ����������ܹ�����\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_combatd(HIC"\n$N���㾫������һתʹ����̨��ѧ"HIW"���ݷ���ʽ��"NOR+HIC"������$n���������У�\n"NOR,me,target,"");
        extra=(int)me->query_skill("qianjun-bang", 1);

        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra); 

        if(!target->is_busy())
                target->start_busy(1);
        
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("QJB_perform");
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);

        me->receive_damage("sen", 100);
        me->add("force", -200);
        if( !target->is_fighting(me) ) {

                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->start_busy(2);
        return 1;
}



