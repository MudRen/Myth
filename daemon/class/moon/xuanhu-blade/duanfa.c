#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void duanfa_ok(object);

int perform(object me, object target)
{
        int damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С��̷�����\n");
        if (!PFM_D->valid_family(me, "�¹�"))
                return notify_fail("[�̷�]���¹�����֮�ܣ�\n");
        if(!me->is_fighting())
                return notify_fail("���̷���ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 400 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 400 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("xuanhu-blade", 1) < 100)
                return notify_fail("����������޵�������������ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("moonshentong", 1) < 100) 
                return notify_fail("����¹��ķ�����������ʹ����һ�л������ѣ�\n"); 
        if(me->query_temp("no_duanfa"))
                return notify_fail("�����㺹��������ӣ��Ȼ�����ðɣ�\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIW"\n$N���е���һ�������ŵ������������~~~\n"NOR,me,target);
        message_vision(HIG"\n�ҵĳ������Ҷ����ǣ�ң�˼�������������\n"NOR,me,target);
        message_vision(HIC"\n���Ѽ������ҵķ���������ǣ�ҡ���\n"NOR,me,target);
        message_vision(HIC"\nһ�����ϣ�����黰����ĻŻ�����\n"NOR,me,target);
        damage=(int)me->query_skill("blade")+random((int)me->query_skill("blade"));
        if (random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
        {
                message_vision(HIW"\n$n�������Ų����ĵ�һ�ᣬ���������������Ƕ�������\n"NOR,me,target);
                target->receive_damage("sen",damage,me,"pfm");
                target->receive_damage("kee",damage/3,me,"pfm");
                target->receive_wound("sen",damage/2,me,"pfm");
                COMBAT_D->report_sen_status(target);
        }
        else 
        {
                message_vision(HIG"\n$n���һ����������ȫ���ܵ��˶���֪����\n"NOR,me,target);
        }
        me->receive_damage("sen", 50);
        me->add("force", -100);
        me->set_temp("no_duanfa",1);
        call_out("duanfa_ok",1+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        return 1;
}

void duanfa_ok(object me)
{
        if (!me) return;
        me->delete_temp("no_duanfa");
}


