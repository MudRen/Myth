#include <ansi.h>
#include <combat.h>
inherit SSERVER;


int perform(object me, object target)
{
        int damage,damagea,extra,exp;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С������ɻ�����\n");
                if (!PFM_D->valid_family(me, "�Ϻ�����ɽ"))
                return notify_fail("[�����ɻ�]���Ϻ�����ɽ����֮�ܣ�\n");
                if(!me->is_fighting())
                return notify_fail("�������ɻ���ֻ����ս����ʹ�ã�\n");
                if((int)me->query("max_force") < 400 )
                return notify_fail("�������������\n");
                if((int)me->query("force") < 400 )
                return notify_fail("����������㣡\n");

                if((int)me->query("sen") < 150 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
                if((int)me->query_skill("buddhism", 1) < 160)
                return notify_fail("��Ĵ�˷𷨲�����죬ʹ����һ�л������ѣ�\n");                
                if((int)me->query_skill("lunhui-zhang", 1) < 160)
                return notify_fail("����ֻ��ȷ�����������ʹ����һ�л������ѣ�\n");
              
                if (me->query_skill_mapped("spells")!="buddhism")
                return notify_fail("�������ɻ���������ϴ�˷𷨲���ʹ�á�\n");

                me->delete("env/brief_message");
                target->delete("env/brief_message");

        exp = (int)me->query("combat_exp"); 
            extra=(int)me->query_skill("lunhui-zhang");
            damagea=random((int)me->query_skill("lunhui-zhang"));
              message_vision(HIR"\n$N����˵��:��Ի�����Ա�ֹ������ɱֹɱ!���ҽ���ʹ�ɱ�䣬����������ͷ�������Щ���֮ͽ��\n"NOR,me,target);
if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
{
              target->receive_damage("kee",damagea,me,"pfm");
              target->receive_wound("kee",damagea/2,me,"pfm");
              target->receive_damage("sen",damagea/3,me,"pfm");
//              target->start_busy(2);
              COMBAT_D->report_status(target);
}
                me->add_temp("apply/attack", extra*3); 
                me->add_temp("apply/damage", extra*3); 
                me->add("combat_exp", exp);  
                message_vision(HIY"\n����ѭ������Ӧ��ˬ��\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIC"\n�����ֻ֣������©��\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n�������������سɷ�\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                me->add_temp("apply/attack", -extra*3); 
                me->add_temp("apply/damage", -extra*3); 
                me->add("combat_exp", -exp);  
               damage=(int)me->query_skill("staff")+random((int)me->query_skill("buddhism"));
if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{
              message_vision(HIC"\n$n��$N�ĳ���֮�£������Ѿ����˼������磮������\n"NOR,me,target);
              message_vision(HIC"\n$n���������������֪���롣\n"NOR,me,target);
              target->receive_damage("kee",damage*2/3,me,"pfm");
              target->receive_wound("kee",damage/2,me,"pfm");
//              target->start_busy(2);
              COMBAT_D->report_status(target);
}
              me->receive_damage("sen", 30);
              me->add("force", -100);
              me->start_busy(2);
return 1;
}

