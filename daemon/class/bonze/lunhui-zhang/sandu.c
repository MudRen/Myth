// /daemon/class/bonze/lunhui-zhang/du.c ��������
// writted by jie 2001-2-9
// �������У��ɽ� ���� �ɶ� 
// ɱ������300 ��̨�ķ�100 �ֻ���100�Ϳɷ�����
// ���һ�дȹ��ն�
// ��̨�ķ�120 �ֻ���120�Ϳɷ�����
// ���μǵ�pfm��������˫������Ƚ�ȷ���ɹ��ʺͳ�����
// ��xkxϵ��ֱ���������������к���
// �Ͼ�ɱ��ϵͳ�����μ�MUD��֧��
// modi by xintai 2/26/2001

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void sandu2(object me);
void sandu3(object me);
void sandu4(object me);
int perform(object me, object target)
{
        string msg;
        object weapon;
        int ap1, ap2, ap3, dp1, dp2, ap, dp, damage, wound;

        me->clean_up_enemy();
        target = me->select_opponent();
// ����ɱ���ߣ����󲻷�����ʵ�������趨��ɱ������
        if( (int)me->query("bellicosity") > 300 )
                return notify_fail("���ɱ��̫�أ��޷�ʩչ���ž�����\n");

        if (me->query_skill("staff",1) < 180)
                return notify_fail("����ֻ��ȷ�������ȷ����������죬�����޷����ã�\n");

        if(me->query_skill("lotusforce",1) < 180)
                return notify_fail("����ڹ����Ӳ��㣬�޷�������磬ʩչ�����������ɡ�\n");

        if (me->query_skill("buddhism",1) < 180)
                return notify_fail("��Ĵ�ɷ𷨲��㣬�޷�������磬ʩչ�����������ɡ�\n");

        if (me->query_skill("parry",1) < 180)
                return notify_fail("��Ļ��������㣬�޷�������磬ʩչ�����������ɡ�\n");

        if (me->query_skill("spells",1) < 180)
                return notify_fail("��ķ������㣬�޷�������磬ʩչ�����������ɡ�\n");

        if (me->query_skill("lunhui-zhang",1) < 180)
                return notify_fail("��Ļ��������㣬�޷�������磬ʩչ�����������ɡ�\n");

        if (me->query_skill("force",1) < 180)
                return notify_fail("��Ļ����ڹ����㣬�޷�������磬ʩչ�����������ɡ�\n");
        
        if((string)me->query_skill_mapped("force")!="lotusforce")
                return notify_fail("�������ɱ�������̨�ķ�Ϊ���ӡ�\n");

        if (!PFM_D->valid_family(me, "�Ϻ�����ɽ"))
                return notify_fail("���Ƿ��ŵ��Ӳ����ã�\n");
        
        if(me->query("max_force") < 2500)
                return notify_fail("����������㣬��������Ӷ�һ�����ȡ�\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷������ɣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if( (int)me->query("force") < 1000 )
                return notify_fail("�����ڵ��������㡣\n");

        msg = HIW "$NĬ����ţ����е�"+ weapon->query("name")+ HIW"��һ�㵭���İ���ֱֱ����$n����ǰ��\n
        ���һ���������ɽ١���\n"NOR;
        message_vision(msg, me, target);

        ap1 = (int)me->query("combat_exp");
        dp1 = (int)target->query("combat_exp");
        ap2 = me->query_str();
        dp2 = target->query_str();
        ap3 = (int)me->query_skill("buddhism",1);
        
        ap = ap1 + ap2 + ap3;
        dp = (dp1 + dp2)*3/4;
        if( dp < 1 )
                dp = 1;
        if( random(ap + ap3) + ap1 > dp/2 )
//        if( random(ap) + ap1*3/5 > dp/2 )
        {
                msg = HIR "$n����һ�ţ�һ��������������$N��"+ weapon->query("name")+ HIR"ʵʵ���ڵ�ӡ�����ţ�\n$n���������̾�������ȥ��\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-60);
                damage = (200 + me->query_str() + random(me->query_skill("staff")))/3;
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(wound>0) target->receive_wound("kee", wound, me);
                target->receive_wound("kee", ap3, me,"pfm");
                target->receive_damage("kee", damage,me,"pfm");
                COMBAT_D->report_status(target, 0);
                call_out("sandu2", 0, me);
                me->start_busy(1);
                target->start_busy(1);
        }
        else
        {
                msg = HIG "ֻ��$n��ɫһ�ݣ�����Ӳ�ӣ�һ������ʱ���˳�սȦ���㿪��$N�����Ĺ��ƣ�\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                me->start_busy(1+random(1));
        }
       
        return 1;
}

void sandu2(object me)
{
        string msg;
        object weapon, target;
        int ap1, ap2, ap3, dp1, dp2, ap, dp, damage, wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( !me->is_fighting()|| !living(me) )
                return;

/*
        if( (int)me->query("force") < 200 )
                return;

        if(me->query_skill("staff") < 135)
                return;

        if(me->query_skill("force") < 135)
                return;
*/
        weapon = me->query_temp("weapon");
        if(!weapon) return ;
        msg = HIW "$N����"+ weapon->query("name")+ HIW"һ�񣬰�ɫ������Ȼ����ȫ������֮������
       \n ��ڶ�ʽ�����ѡ���Ȼ�ĳ���\n\n"NOR;
        message_vision(msg, me, target);
        ap1 = (int)me->query("combat_exp");
        dp1 = (int)target->query("combat_exp");
        ap2 = me->query_str();
        dp2 = target->query_str();
        ap3 = (int)me->query_skill("buddhism",1);
        
        ap = ap1 + ap2 + ap3;
        dp = (dp1 + dp2)*3/4;
        if( dp < 1 )
                dp = 1;
        if( random(ap)/2 + ap1 > dp )
        {
                msg = HIR "$n���Ŀ�䣬"+ weapon->query("name")+ HIR"�ѵ�����ǰ���ھ�һ�£�\n$n��ʱ������Ѫ�����ɳ��������࣡\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                damage = (100 + me->query_str() + random(me->query_skill("staff")))/2;
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(wound>0) target->receive_wound("kee", wound,me,"pfm");
                target->receive_damage("kee", damage,me,"pfm");
                target->receive_wound("kee", (ap3+ap3)*4/5,me,"pfm");
                target->receive_wound("sen", (ap3)*4/5,me,"pfm");
                COMBAT_D->report_status(target, 0);
                call_out("sandu3", 0, me);
                target->start_busy(1);
                me->start_busy(1);
        }
        else
        {
                msg = HIG"$n���޿ɶ㣬�͵�һ�����ǳ��Ǳ��Ŀ����㿪����ڶ��С�\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                me->start_busy(2);
        }
        
        return;
}
void sandu3(object me)
{
        string msg;
        object weapon, target;
        int ap1, ap2, ap3, dp1, dp2, ap, dp, damage, wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( !me->is_fighting()|| !living(me) )
                return;

/*
        if( (int)me->query("force") < 320 )
                return;

        if(me->query_skill("staff") < 150)
                return;

        if(me->query_skill("force") < 150)
                return;
*/
        weapon = me->query_temp("weapon");
        if(!weapon) return;
        msg = HIW "$N������"+ weapon->query("name")+ HIW"������˷�ľ�������ӿ������
        ���ɶ�һʽ֮�����Լ���Ҷ���Ҳ������ʨ�Ӻ𡱣�\n\n"NOR;
        message_vision(msg, me, target);
        ap1 = (int)me->query("combat_exp");
        dp1 = (int)target->query("combat_exp");
        ap2 = me->query_str();
        dp2 = target->query_str();
        ap3 = (int)me->query_skill("buddhism",1);
        
        ap = ap1 + ap2 + ap3;
        dp = (dp1 + dp2);
        if( dp < 1 )
                dp = 1;
        if( random(ap)/2 + ap1 / 2*3 > dp*3/4 )
        {
                msg = HIR "$n���⻡�ε���ӿ����һ�֣���ȫ�ң�������˵Ķ������ᣡ\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-300);
                damage = (200 + me->query_str() + random(me->query_skill("staff")));
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(wound>0) target->receive_wound("kee", wound,me,"pfm");
                target->receive_damage("kee", damage,me,"pfm");
                target->receive_wound("kee", ap3*3/2,me,"pfm");
                COMBAT_D->report_status(target, 0);
                call_out("sandu4", 0, me);
                target->start_busy(1);
                me->start_busy(1);
        }
        else
        {
                msg = HIG "$n��Σ���ң���׼���ƣ�����������һ�С�\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                me->start_busy(1+random(2));
        }
        
        return;
}

void sandu4(object me)
{
        string msg;
        object weapon, target;
        int ap1, ap2, ap3, dp1, dp2, ap, dp, damage, wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( !me->is_fighting()|| !living(me) )
                return;

/*
        if( (int)me->query("max_force") < 800 )
                return;

        if( (int)me->query("force") < 350 )
                return;

        if(me->query_skill("staff") < 180)
                return;

        if(me->query_skill("force") < 180)
                return;
*/
        weapon = me->query_temp("weapon");
        msg = HIC "$N������������ͷ�ǰ����������߳߾���ӿ���������ӷ������������Ϲ����ջ���
        ���ȹ��նɡ����ȶ�����\n\n"NOR;
        message_vision(msg, me, target);
        ap1 = (int)me->query("combat_exp");
        dp1 = (int)target->query("combat_exp");
        ap2 = me->query_str();
        dp2 = target->query_str();
        ap3 = (int)me->query_skill("buddhism",1);
        
        ap = ap1 + ap2 + ap3;
        dp = (dp1 + dp2)*4/5;
        if( dp < 1 )
                dp = 1;
//        if( random(ap+ap) > dp )
        if( random(ap + ap)*2 > dp*5/4 )
        {
                msg = HIR "$n��һƬ��Ҷ�������ȹ��նɡ��ľ�����Χ������ѹ�⡢���£�\n���ص�ˤ�ڵ��ϣ��ۿ��ǲ����ˣ�\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-400);
                damage = (400 + me->query_str() + random(me->query_skill("staff")))*2;
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(wound>0) target->receive_wound("kee", wound,me,"pfm");
                target->receive_damage("kee", damage,me,"pfm");
                target->receive_wound("kee", ap3*2,me,"pfm");
                COMBAT_D->report_status(target, 0);
                target->start_busy(1);
                me->start_busy(2+random(1));
        }
        else
        {
                msg = HIG "$nһ�����ǰ㼱�˶���������ӹ��Ź��ϼ����һ������\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                  me->start_busy(2+random(1));
        }

        

        return;
}


