// modify by shao 2001.12.27
// �������У�̫�������ǣ��������������󻯰��ԣ�����ٺ�̫����
// ��Ҫ����exp��skills������

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

string get_name(string str)
{
        str="̫��";
        return str;
}

string get_help(string str)                
{
        str="ָ��:���������������\n"
        +"����:�����ɷ�100����С���๦100�������ǽ���100��"
        +"̫�������ǣ��������������󻯰��ԣ�����ٺ�̫����";
        return str;
}

int perform(object me, object target)
{
        string msg;
        object weapon;
        int exp1, exp2,sword,parry,damage, wound;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�㲻��ս������ʲô�ã�\n");

        exp1 = (int)me->query("combat_exp",1);
        exp2 = (int)target->query("combat_exp");
        sword = (int)me->query_skill("liangyi-sword",1);
        sword = sword * sword * sword / 10;
        parry = (int)target->query_skill("parry",1);
        parry = parry * parry * parry / 10;

        if(me->query_skill("sword",1) < 100 )   
                return notify_fail("��Ļ�������̫���ˣ�\n");
        
        if(me->query_skill("liangyi-sword",1) < 100 )   
                return notify_fail("������ǽ���̫���ˣ�\n");

        if(me->query_skill("wuxiangforce",1) < 100)
                return notify_fail("���С���๦�ȼ������ɣ�\n");

        if((string)me->query_skill_mapped("force")!="wuxiangforce")
                return notify_fail("��������ڹ���ƥ�䣡\n");

        if(me->query("max_force") < 800)
                return notify_fail("���������������̫����������\n");

        if(me->query("force") < 800)
                return notify_fail("������������ˣ�\n");

        weapon = me->query_temp("weapon");

        if ((int)me->query_skill("liangyi-sword",1) > 100)
        {
                msg = HIW "$N��Ȼ���б��������е�"+ weapon->query("name")+ HIW"������һ��̫�������зֳ�����������           
         $NĬĬ�������̫�������ǣ�\n"NOR;

                message_vision(msg, me, target);
        
                if( random( exp1 + sword )> ( exp2 + parry) / 4)
                {
                        msg = HIR "$nֻ������������֮��ֱ�ƹ�������֪����ζ�������ʱ��$N��"+ weapon->query("name")+ HIR"���˸����ţ�\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-50);
                        damage = (50 + me->query_str() + random(me->query_skill("liangyi-sword",1)/2 + me->query("force_factor")) / 2 );
                        wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                        target->receive_damage("kee", damage, me, "pfm");
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "ֻ��$n�������أ����ɽ��仯�⣡\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-50);
                        me->start_busy(1);
                }
        }


        if ((int)me->query_skill("liangyi-sword",1) > 150)
        {
                msg = HIW "���������������е�"+ weapon->query("name")+ HIW"�������󣬴��ĸ���������           
         $NĬĬ�����������������\n"NOR;

                message_vision(msg, me, target);

                if( random( exp1 + sword )> ( exp2 + parry) / 4)
                {
                        msg = HIR "$nһ�����񣬱�$N����޻���֮����\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-50);
                        damage = (100 + me->query_str() + random(me->query_skill("liangyi-sword",1)/2 + me->query("force_factor")) );
                        wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                        target->receive_damage("kee", damage, me, "pfm");
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n����������$N�Ĺ���һһ���⣡\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-50);
                        me->start_busy(2);
                }
        }



        if ((int)me->query_skill("liangyi-sword",1) > 200)
        {
                msg = HIW "�����漴�����仯��Ϊ���ԣ�           
         $NĬĬ����������󻯰��ԣ�\n"NOR;
       
                message_vision(msg, me, target);
        
                if( random( exp1 + sword )> ( exp2 + parry) / 3)
                {
                        msg = HIR "ֻ����Ӱ��Ǭ�������𡢿����ޡ��롢�㡢�Ұ˷�������$n������æ���ң��˸���λ���ܼ�ˣ�\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-50);
                        damage = (150 + me->query_str() + random(me->query_skill("liangyi-sword",1) + me->query("force_factor")) / 2 );
                        wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                        target->receive_damage("kee", damage, me, "pfm");
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n���������������׽��仯�⣡\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-50);
                        me->start_busy(2);
                }
        }


        if ((int)me->query_skill("liangyi-sword",1) > 200)
        {
                msg = HIW "�����ֽ����϶�Ϊһ���γ�һ��̫����           
         $NĬĬ����������Ժ�̫����\n"NOR;
       
                message_vision(msg, me, target);
        
                if( random( exp1 + sword )> ( exp2 + parry) / 2)
                {
                        msg = HIR "һ���޴��̫����$n���˹�����$n�մ������������̱����˸����ţ�\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-50);
                        damage=(me->query_kar() / 10+          random(me->query_skill("sword",1)) / 20 );
                        if ( damage > 6)
                        damage = 6;
                        target->start_busy(damage);
 
                }
                else
                {
                        msg = HIG "$nһ������̫�����Ľ��仯�⣡\n\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-50);
                        me->start_busy(2);
                }
        }


        me->start_busy(2);

        return 1;
}


