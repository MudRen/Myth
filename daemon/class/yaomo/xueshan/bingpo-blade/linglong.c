 
#include <ansi.h>
inherit SSERVER;

string get_name(string str)
{
        str="ѩ����";
        return str;
}

string get_help(string str)                
{
        str="ָ������������������\n"
        +"���������Ǻ���250����������Ѫ��200�����������1000"
        +"����һ������������";
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
                return notify_fail("��Ҫ��˭ʩչ��ѩ���硹��\n");
        if (!PFM_D->valid_family(me, "��ѩɽ"))
                return notify_fail("�㲻�Ǵ�ѩɽ���ӣ���ô��ʹ�ô�ѩɽ������\n");
        if(environment(me)!=environment(target))
                return notify_fail("������û���˹���Ŀ��!\n");
        if((string)me->query_skill_mapped("force")!="ningxie-force")
                return notify_fail("ѩ����Ҫ�Ա�����Ѫ��Ϊ���ӡ�\n");
        if((int)me->query("force") < 65+(int)me->query("force_factor") )
                return notify_fail("����������㣡\n");
        if(me->query("max_force") < 1000 || me->query("force")<500)
                return notify_fail("�������㣬�����޷�����ѩ�����������\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("������̫�����ˣ��޷�ʩչ��ѩ���硹��\n");
        if((int)me->query_skill("bingpo-blade", 1) <250)
                return notify_fail("��ı��Ǻ������ò������죬�޷�ʹ�����С�ѩ���硹��\n");
        if((int)me->query_skill("ningxie-force", 1) <200)
                return notify_fail("��Ա�����Ѫ��������ǳ������ʹ����ѩ���硹��\n");
        me->add("force", -65-(int)me->query("force_factor"));
        msg = HIW
 "\n$N��Ӱ�����ĸ���������ǰ��ֻ��$N����������Ө��͸��"RED"ѩ����"NOR"\n"HIW"Χ��������Χ�����⽣Ӱ��������ʱ�����������͵�ѩ��֮�У���һ������\n�����"HIG"����ѩ"NOR"\n"HIM"����ɽˮ�䣬���������!\n"NOR;

        ap = me->query_skill("bingpo-blade", 1);
        ap = ( ap * ap * ap / (3 * 350) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (7 * 400) );
        dp = dp*250 + target->query("combat_exp");
        //if( random((ap + dp)/800+1) <  dp/2200 ) 
        if( random((ap + dp)/600+1) <  dp/2500 ) 
        {
                msg += HIY "��$n��û�б���Ѥ����ѩ��������,��Ȼ������ѩ������Ļþ��У�\n\n"NOR;
                message_combatd(msg, me, target, "");
        } 
        else 
        {
                damage = (int)me->query_skill("bingpo-blade",1) / 8 +
        (int)me->query("sen") / 200 + random((int)me->query("sen") / 150 ) +
        (int)me->query("kee") / 200 + random((int)me->query("kee") / 150 );
                msg += HIR "\n$n��ʱ����������һ��ľ���֮�У���������б�ѩ��������ˣ�\n\n" NOR;
                damage +=random(10);
                target->receive_damage("sen", me->query("eff_sen")*damage/100, me, "pfm");
                target->receive_damage("kee", me->query("eff_kee")*damage/80, me, "pfm");
                target->receive_wound("kee", me->query("eff_kee")*damage/200, me, "pfm");
                me->improve_skill("bingpo-blade", 1, 1);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else me->kill_ob(target);
                }
        }
        me->start_busy(2);
        return 1;
}

