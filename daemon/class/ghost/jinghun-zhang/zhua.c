#include <ansi.h>
#include <skill.h>
inherit SSERVER;
int perform(object me, object target)
{
        int i,j,k,damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʹ���޳�צ��\n");
        if (!PFM_D->valid_family(me, "���޵ظ�"))
                return notify_fail(HIG"���޳�צ��"+NOR"��ڤ�粻��֮�ܣ�\n");
        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");
        if((int)me->query("max_force") < 200 )
                return notify_fail("����ڹ�̫�\n");
        if((int)me->query("force") < 100 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("jinghun-zhang", 1) < 50)
                return notify_fail("��ľ����Ƶȼ�����������ʹ����һ�У�\n");
        i=(int)me->query("combat_exp");
        j=(int)target->query("combat_exp");
        k=(int)me->query_skill("jinghun-zhang");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIB"\n$N����Ĭ����������޳��������޳�����ƫƫ������ײ����ϲŭ�޳����������ɣ���צ��"NOR,me,target);
        message_vision(HIB"\nһצץ��$n\n"NOR,me,target);
        if (random(i+j)>j) 
        {
                damage=k+random(k);
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage/5, me, "pfm");
                target->start_busy(5);
                if (k>160) k=160;
                target->apply_condition("hell_zhua", (int)target->query_condition("hell_zhua")+2+k/20);
                COMBAT_D->report_status(target);
                message_vision(HIG"\n$n����һ�Σ�����������һ������ɫ��צ�ۣ�\n"NOR,me,target);
        }
        else message_vision(HIY"\n$n����һ�����㿪����һץ��\n"NOR,me,target);
        me->receive_damage("sen", 30);
        me->add("force", -100);
        me->receive_damage("kee", 30);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->start_busy(2);
        return 1;
}

