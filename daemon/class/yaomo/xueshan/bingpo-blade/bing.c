//write by swagger
//2001.5.10
//Changed by Wuyou@Sanjie

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

string get_name(string str)
{
        str="����ն";
        return str;
}

string get_help(string str)                
{
        str="ָ��������������\n"
        +"���������Ǻ���100����������Ѫ��100��������1200";
        return str;
}

int perform(object me, object target)
{
        string msg;
        int damage, def, extra;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("����նֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!PFM_D->valid_family(me, "��ѩɽ"))
                return notify_fail("������ն��ֻ��ѩɽ���Ӳſ���ʹ�ã�\n");
        weapon = me->query_temp("weapon");
        if( (string)weapon->query("skill_type") != "blade" )
                return notify_fail("�������޵�������ʹ�ú���ն��\n");
        if ((int)me->query_skill("bingpo-blade", 1) < 100 )
                return notify_fail("����Ǻ���������죬ʹ��������ն��\n");
        if ((int)me->query_skill("ningxie-force", 1) < 100 )
                return notify_fail("��ı�����Ѫ����Ϊ������\n");
        if ((int)me->query_skill("dengxian-dafa", 1) < 100 )
                return notify_fail("��ĵ��ɴ���Ϊ������\n");                 
        if (me->query_temp("bing_busy")) 
                return notify_fail("��շ�������,���û���Σ��!\n");
        if( (int)me->query("force") <= 1200 )
                return notify_fail("������������ʹ�ú���ն����Σ�գ�\n");
                
        msg = HIC "\n$N���˼����������һ�ӣ���Χ��ʱ��������ޱȣ�
$N������Ѫ�񹦣�һ�Ŵ̹ǵĺ�����$nֱ�ƶ�����\n" NOR;
        
        
        if( random((int)me->query("max_mana")*4) > (int)target->query("max_mana"))
        {
                
                msg += HIW"\n$n��$N���������ź������˸����ţ�\n\n" NOR;
                
                target->start_busy(2+random(3)); 
                
                msg +=  HIC ">>$N����"+ weapon->name() + HIC"����һ��������Ҳ�����ڿն���
�漴һʽ"HIW"������ն��"HIC"�ó�����������$nӭ��������\n\n"NOR;
                                
                if (me->query_skill("parry") > random(target->query_skill("parry")))
                {
                        msg += HIC"$n��û������������У�һ��Ѫ���Ѿ�������һ�㣬���������\n"NOR;
                        damage = (int)me->query_skill("parry", 1);
                        damage = damage + random(damage);
                        def=(int)target->query_temp("apply/armor_vs_force");
                        //damage -=damage*def/3000;
                        damage -=damage*def/6000;
                        damage = damage + me->query("force_factor");
                        target->receive_damage("kee", damage, me, "pfm");
                        target->receive_wound("kee", damage/2, me, "pfm");
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else 
                {
                        msg += HIC"$næһ�˹�������һ���������л��������е�������\n"NOR;
                        message_combatd(msg, me, target, "");
                } 
                
                msg =   HIC">>$N����"+ weapon->name() +""HIW"--����������"HIC"$NҲ�ɾ�ת����
һ���㼱��磬��̤���ţ��������У�ʽʽ��$n���벻���ķ�λ���������\n" NOR;                
                       
                if (random(me->query("combat_exp")) > (target->query("combat_exp"))/4)
                {
                        msg += HIC"$nһ����æ���ң���֪�����ȥ�м��⾲��ˮ�������ĵ�����\n"NOR;
                        damage = damage + random(200);
                        if(damage<1)damage = 1;
                        target->receive_damage("kee",damage*3/2,me,"pfm");
                        target->receive_wound("kee", damage, me,"pfm");
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else
                {
                        msg += HIC"$nȴ�ľ���ˮ�����в��У��߽���$N�������Ĺ��ơ�\n"NOR;
                        message_combatd(msg, me, target, "");
                        
                }

                me->add("force", -100);
                me->add("mana", -100);
        }
        else 
        {
                msg = WHT"\n$n���Ѿ�����$N����ͼ������һ�����ѱܿ������ź�����\n" NOR;
                message_combatd(msg, me ,target, "");
                me->start_busy(2);
                me->add("force", -100);
                me->add("kee", -50);
        }
        
        me->set_temp("bing_busy",1);
        
        call_out("remove_effect",2+random(2),me);
        return 1;
}

void remove_effect(object me, object target) 
{
        string msg;
        if (!me) return;
        me->delete_temp("bing_busy");
        msg = HIR"\n����һ��,����������ɢȥ�ˡ�\n" NOR;
        message_vision(msg, me ,target);
}



