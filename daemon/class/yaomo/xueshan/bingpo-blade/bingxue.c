//Created by Wuyou@Sanjie

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, mypot, tapot;
        object weapon;
        weapon = me->query_temp("weapon");
        
        damage = (int)me->query_skill("bingpo-blade", 1) + (int)me->query_skill("blade", 1);
        damage = damage/2 + random(damage/2);
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(WHT"��Ҫ��˭ʩչ"HIR"��ǧ���������ѩ��"WHT"��\n"NOR);
        if( !me->is_fighting(target) )
                return notify_fail(HIR"��ǧ���������ѩ��"WHT"ֻ����ս��ʹ�á�\n"NOR);
        if (!PFM_D->valid_family(me, "��ѩɽ"))
                return notify_fail(HIR"��ǧ���������ѩ��"WHT"�Ǵ�ѩɽ������\n");                        
        if (me->query_skill_mapped("force")!="ningxie-force")
                return notify_fail(WHT"ֻ���ñ�����Ѫ����������"HIR"��ǧ���������ѩ��"WHT"��\n"NOR);
        if (me->query_skill("bingpo-blade",1)<200)
                return notify_fail(WHT"��ı��Ǻ����������죬���ü���Ŭ����\n"NOR);     
        if (me->query_skill("ningxie-force",1)<200)
                return notify_fail(WHT"��ı�����Ѫ���������죬���ü���Ŭ����\n"NOR);                    
        if((int)me->query("force") < 300 )
                return notify_fail(WHT"����������㡣\n"NOR);
        if( me->query("max_force") < 1000 )
                return notify_fail(WHT"���������Ϊ��ǳ����������"HIR"��ǧ���������ѩ��"WHT"��\n"NOR);     
        if( (int)me->query("kee") < 200 || (int)me->query("sen") < 200  )
                return notify_fail(WHT"������̫�����ˣ��޷�ʩչ"HIR"��ǧ���������ѩ��"WHT"��\n"NOR);
        if( time()-(int)me->query_temp("bxffs_end") < 3 ) 
                return notify_fail(WHT"�������׺���ǧ���ѩ�䳾����\n"NOR); 
            
        msg = MAG "\n\t�����"HIW"��ѩ"HIG"Ϊ"HIB"��"HIW"��"HIG"Ϊ"HIR"�ǣ�"HIY"����"HIW"��ѩ"HIM"��"HIC"��գ�"NOR""MAG"�����\n" NOR;                      
                     
        me->add("sen", -50);
        me->add("kee", -50);
        
        msg += WHT "\n\t���������·�˪������\n" NOR;
        msg += WHT "\t\t\tǧ���ѩ˭��Թ��\n" NOR;
        msg += HIC "\n�������գ�������$N����һ������ʱ��ѩ�׷ɣ�Թ�����죡\n" NOR;
        
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) 
        {
                msg += HIY "$n��֪��������Թ����Χ�ˣ�\n" NOR;
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage,me,"pfm");
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target); 
                me->add("force", -50);
        }
        else
        {
                msg += HIY "$n�˹��࿹����Թ����ֹ��������Χ��\n" NOR;
                message_combatd(msg, me, target, "");
        }               
        
        msg = MAG "\n\t��������ѩ���Ρ�����\n" NOR;
        msg += MAG "\t\t\t����ɻ�һ���գ�\n" NOR;
        
        mypot=(int)me->query_skill("bingpo-blade");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
        
        msg += HIW "\n�������ϼ�����������ԼԼ$n�����칬��������Ϸ�����ɾ��硣
$n�������ĳ�����Ȼ��һ�ɺ����Ӻ�Ϯ����\n" NOR;
        
        if( random( mypot+tapot ) > tapot/4 || !living(target) ) 
        {
                msg += HIY "$n���ѽ����λ�֮����δ���ѣ�������һ��͸������\n" NOR;
                COMBAT_D->do_attack_damage(me, target);
                target->receive_wound("kee", damage, me, "pfm");
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);                
                me->add("force", -50);
        }
        else
        {
                msg += HIY "$n�����������Ի󣬱ܿ�����ɺ�����\n" NOR;
                message_combatd(msg, me, target, "");
        }
                
        msg = HIR "\n\t������̤ѩѰ÷������\n" NOR;
        msg += HIR "\t\t\t����֪˭��"HIW"���ģ�\n" NOR;        
        msg += HIM "\n��ѩ��������÷ʢ�������÷��������Ʈ�㡣���÷����Ʈ�䣬���㺮��Ϯ��$n��\n" NOR;
        
        if (me->query_skill("force") > random(target->query_skill("force")))
        {
                msg += HIY "$n��÷�������ı������ˡ�\n" NOR;
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage,me,"pfm");
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);      
                me->add("force", -50);
        }
        else
        {
                msg += HIY "$n��Ȼ����˼��Ķ������仨�꣡\n"NOR;
                message_combatd(msg, me, target, "");
        }
                                
                        
        me->set_temp("bxffs_end",time());
        return 1;
}



