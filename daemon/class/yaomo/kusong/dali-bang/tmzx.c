//��ħ���� by cigar

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="��ħ����";
        return str;
}

string get_help(string str)                
{
        str="ָ����������������\n"
        +"������������120������ħ�ķ�120��"
        +"�ܹ�ͬʱ�˺��Է��ľ������Ѫ��";
        return str;
}

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����ħ���֡���\n");

        if (!PFM_D->valid_family(me, "���ƶ�"))
                return notify_fail("�㲻�ǻ��ƶ����ˣ���ô��ʹ��Ұ����ƾ�����\n");
                
        if((string)me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("�����ħ�ķ������ò�����ħ���֡�\n");

        if((int)me->query("force") < 65+(int)me->query("force_factor") )
                return notify_fail("����������㣡\n");

        if(me->query("max_force") < 1000 || me->query("force")<500)
                return notify_fail("�������㣬�޷�������ħ���ֵ�������\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("������̫�����ˣ��޷�ʩչ����ħ���֡���\n");

        if((int)me->query_skill("dali-bang", 1) <120)
                return notify_fail("��Ĵ��������ò������죬�޷�ʹ�����С���ħ���֡���\n");

        if((int)me->query_skill("huomoforce", 1) <100)
                return notify_fail("��Ի�ħ�ķ�������ǳ������ʹ������ħ���֡���\n");

        me->add("force", -35-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);

        msg = HIR
"\n$NĬ�˻�ħ�񹦣����κ���б��ɳ���$n��Ҫ׷����ȴ����$N���зų�һ��Ѥ���Ĺ⻷����ʱ����г���һ������ħ��ֻ��ħ���־���ͥ�����\n"
"�����磬���׻�һ��ֱ��$n��ǰ���ֻ̼�$n����������������֪����Ǻ�\n" NOR;

        ap = me->query_skill("dali-bang", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("dodge");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");
        if( random((ap + dp)/400) <  dp/1000 ) 
        {
                msg += "$n"+HIG"��������ֱ������������һ��"+HIW"�����춷�������κ�����"+HIG"�����ƣ������������һ����\n\n"NOR;
                message_vision(msg, me, target);
        } 
        else 
        {
                damage = (int)me->query_skill("stick",1) / 10 +
        (int)me->query("sen") / 300 + random((int)me->query("sen") / 200 ) +
        (int)me->query("kee") / 300 + random((int)me->query("kee") / 200 );
                msg += HIY "��ħһ����ʱ��$n���ؿ�ֱ�������$n���ؿڶ�ʱѪ����ע�����"+HIW"�����ˣ��������"+HIR"��$n�������Ƿ��в������ڵ�Ϧ��\n" NOR;
                damage +=random(50);
                target->receive_damage("sen", me->query("eff_sen")*damage/70, me, "pfm");
                target->receive_damage("kee", me->query("eff_kee")*damage/70, me, "pfm");
                me->improve_skill("dali-bang", 1, 1);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }

        if( !target->is_fighting(me) ) 
        {
                if( living(target) ) 
                {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->start_busy(2);
        return 1;
}


