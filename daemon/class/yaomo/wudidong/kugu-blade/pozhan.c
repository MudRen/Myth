//Cracked by Roath
// pozhan.c             �����ٳ�

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int delay, myblade;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ս���У�¶ʲô������\n");
        if (!PFM_D->valid_family(me, "�ݿ�ɽ�޵׶�"))
                return notify_fail("��������ֻ���޵׶����˲ſ����ã�\n");

        myblade=(int)me->query_skill("kugu-blade",1);
        if(myblade>160) myblade=160; // mon 12/7/98
        if(myblade<50) 
                return notify_fail("�����Ϊ�����¶��������̫Σ���ˡ�\n");

        delay=myblade/16;

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        msg = CYN "$N����ʽͻȻһ�䣬���ȫ���·����������������ٳ���\n";
        //change totoal random to half random half ur own value to make the sucessrate more stable
        if( ((random(me->query("combat_exp")) + (me->query("combat_exp")/2) > (int)target->query("combat_exp")*1/2 ))) 
        {
                msg += "$n�빥��ȴ��֪���ĸ��������棬�ĸ��Ǽ١�\n";
                msg += "���$p��$P���˸����ֲ�����\n" NOR;
                target->start_busy(delay);

                //me->start_busy(1+random(2));
        }
        else 
        {
                msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
                me->start_busy(1+random(2));
        }
        message_vision(msg, me, target);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        return 1;
}

