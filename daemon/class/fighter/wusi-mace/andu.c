// �²ְ���
// ��Ҫ�Լ�ѧʲô����ȫ�öԷ����书�����Է�
// Ľ�ݾ�ѧ���Ǻǡ�����
// writted by jie 2001-2-12
// modi by lestat 2001-5-2

#include <ansi.h>

inherit SSERVER;
int perform(object me,object target)
{
        int damage, lvl, r_lvl;
        string msg;
        string limb,*limbs,attack_skill,attack;
        object weapon,weapon2;
        mapping action;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"��Ҫ��˭ʩչ�����ɳ²֡���\n"NOR);

        if(!me->is_fighting()) 
                return notify_fail(CYN"�����ɳ²֡�ֻ����ս����ʹ�ã�\n"NOR); 
                
        if (!PFM_D->valid_family(me, "������"))
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á��²ְ��ɡ�?\n");
        
        if( (int)me->query_skill("literate",1)<80)
                return notify_fail("��Ķ���ʶ�ֲ��ô�����о���ԣ��ò��ˡ��²ְ��ɡ���\n");
                
        if( (int)me->query_skill("wusi-mace",1)<50)
                return notify_fail("�����˽ﵷ�������죬����ʹ�á��²ְ��ɡ���\n");
        
        if( (int)me->query_skill("lengquan-force",1)<50)
                return notify_fail("�����Ȫ�񹦲�����񣬲���ʹ�á��²ְ��ɡ���\n");
        
        if( time()-(int)me->query_temp("andu_end") < 4 )
                return notify_fail("�����ö�Ͳ����ˣ�\n");                       
                        
        if( (int)me->query("force")<300)
                return notify_fail("����������̫��������ʹ�á��²ְ��ɡ���\n");
                        
        msg=HIY"$N��һ���񣬼��������������ɳ²֡�����ƶ�Ȼʩչ����\n\n"NOR;

        //me->start_busy(1);
        target->start_busy(random(3));
//��һ��                
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) 
        {       
                damage = (int)me->query_skill("wusi-mace",1);
                lvl = damage/20;
                if( damage > 500) damage = 500;
                r_lvl = 3+random(lvl);
                if( r_lvl > 5 ) r_lvl = 5;
                if( r_lvl < 1) r_lvl = 1;
                damage = damage/4 + r_lvl*me->query("force_factor",1);        
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/3,me,"pfm");
                me->add("force",-damage/10);
                
                weapon=target->query_temp("weapon");
                weapon2= me->query_temp("weapon");
                if(objectp(weapon))
                        attack_skill=weapon->query("skill_type");
                else
                        attack_skill="unarmed";
                attack=target->query_skill_mapped(attack_skill);
                if(!attack)     attack=attack_skill;
                msg +=HIW"$NʩʩȻ�ݳ�$n��ѧ�ġ���"HIM+to_chinese(attack)+HIW"���������о����̣�������ԣ���Ȼ���Ȳ��ң�\n"NOR;

                limbs=target->query("limbs");
                limb = limbs[random(sizeof(limbs))];
                action=target->query("actions");
                if( !mapp(action) ) 
                {
                        target->reset_action();
                        action=target->query("action");
                
                }
                msg += action["action"]+"��\n";
                msg+=HIB"$n�벻�����Է��ݹ����Լ��ľ����ѧ����ʱ����ʧ�룡�����$l���"+action["damage_type"]+"����\n"NOR;
                msg=replace_string(msg,"$l",limb);
                if(objectp(weapon)) 
                msg=replace_string(msg,"$w",weapon2->query("name"));
                message_vision(msg, me, target);
                COMBAT_D->report_status(target, 0);
//�ڶ���
                msg=HIW"\n$N��ʽδ��,�������ֵݳ�һ�С���"HIM+to_chinese(attack)+HIW"�����˳��ᢣ���ʤ��ǧ��֮�⡣\n"NOR;
                limbs=target->query("limbs");
                limb = limbs[random(sizeof(limbs))];
                action=target->query("actions");
                if( !mapp(action) ) 
                {
                        target->reset_action();
                        action=target->query("action");
                
                }
                msg += action["action"]+"��\n";
                msg+=HIB"$nû���Լ�������ѧ��Ȼ������˲��ʹ������ʱ�Ļ����䣡\n"NOR;
                msg=replace_string(msg,"$l",limb);
                if(objectp(weapon)) 
                msg=replace_string(msg,"$w",weapon2->query("name"));
                message_vision(msg, me, target);
                target->receive_damage("sen",damage,me,"pfm");
                target->receive_wound("sen",damage/3,me,"pfm");
                COMBAT_D->report_sen_status(target, 0);
                me->add("force",-damage/10);
        
        } else {
//                me->start_busy(1);
                msg += HIC"$n���쳤Ц:����Ū��!�����ʶʲô�����ڡ�\n" NOR;
                message_vision(msg, me, target);
                me->add("force",-200);
        }
        
        me->set_temp("andu_end",time());
        return 1;
}




