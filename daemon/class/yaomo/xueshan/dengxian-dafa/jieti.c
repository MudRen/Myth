// modified by vikee
// jieti.c ��ħ����󷨡�


#include <ansi.h>

inherit SSERVER;



int cast(object me, object target)
{
        string msg;
        int success, ap, dp;

return 0;
        if( (string)me->query("class") != "yaomo" )
                return notify_fail("ֻ����ħ����ʩչ��ħ����󷨡�\n");

        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || target->is_corpse()
        || target==me)
                return notify_fail("��Ҫ��˭ʩչ��ħ����󷨣�\n");

        if((int)me->query("mana") < 1100 || (int)me->query("max_mana") < 1100 )
                return notify_fail("��ķ���������������Чʩչ��ħ����󷨣�\n");

        if((int)me->query("force") < 1500 || (int)me->query("max_force") < 1500 )
                return notify_fail("�������������������Чʩչ��ħ����󷨣�\n");

        if((int)me->query("sen") < 100 || (int)me->query("sen") < (int)me->query("max_sen")/2 )
                return notify_fail("���޷����о���ʩչ��ħ����󷨣�\n");

        if( (int)me->query("daoxing") < (int)target->query("daoxing")/10  )
                return notify_fail("�Է�����ǿ̫���ˣ����Ǳ������ɣ�\n");
        //here, we do not allow that a too weak player trys this on 
        //a much stronger player. this is to prevent statistically possible 
        //but unreasonable results from happenning. 

        if( random(me->query("max_mana")) < 50 ) {
                write("��ʧ���ˣ�\n");
                return 1;
        }

        msg = HIC
"$N�������˼������ģ�˫����ס�Դ������췢��һ����˻��\n\n��Ȼ��$N���Լ���ͷ����һҧ��һ��Ѫ����$n���˹�ȥ��\n" NOR;

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("daoxing");
        ap = 4*ap; //this is for ƴ�� so easier.
        dp = target->query("daoxing");
        if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( ap < random(dp) ) success = 0;
//here we compared max_mana.
//if the attacher has half of the max_mana of the target, 
//he has 50% chance to kill his target, which is reasonable.

        if(success == 1 ){//now both die.
                msg +=  HIR "���$n��Ѫ����ס����ʱ����һ���ҽУ�\n��$NҲ����һ̱�����ڵ��ϡ�\n" NOR;
                message_vision(msg, me, target);

                me->kill_ob(target);
                target->kill_ob(me);
                //to produce killing messages.

                me->add_maximum_mana(-100);
                me->add_maximum_force(-50);
                me->save();
                //successed, attacker lost 100 max_fali and 50 max_neili.
                
                target->receive_damage("sen",target->query("max_sen")+1,me,"cast");
                target->receive_wound("sen", (int)target->query("max_sen")+1, me, "cast");
                target->receive_damage("kee",target->query("max_kee")+1,me,"cast");
                target->receive_wound("kee", (int)target->query("max_kee")+1, me, "cast");
                COMBAT_D->report_status(target);
                target->heart_beat();
                //target die here.

                me->receive_damage("sen", (int)me->query("max_sen")+1, target, "cast");
                me->receive_wound("sen", (int)me->query("max_sen")+1, target), "cast";
                me->receive_damage("kee", (int)me->query("max_kee")+1, target, "cast");
                me->receive_wound("kee", (int)me->query("max_kee")+1, target, "cast");
                COMBAT_D->report_status(me);
                me->heart_beat();
                //attacker die here.

        }
            
        else {
                msg +=  HIR "���Ѫ��$n����������������ס��$N��\n$N��̾һ��������һ̱�����ڵ��ϡ�\n" NOR;
                message_vision(msg, me, target);

                me->kill_ob(target);
                target->kill_ob(me);
                //to produce killing messages.

                me->add_maximum_mana(-50);
                me->add_maximum_force(-25);
                me->save();
                //failed, attacker lost 50 max_fali and 25 max_neili.
                
                me->receive_damage("sen", (int)me->query("max_sen")+1, target, "cast");
                me->receive_wound("sen", (int)me->query("max_sen")+1, target, "cast");
                me->receive_damage("kee", (int)me->query("max_kee")+1, target, "cast");
                me->receive_wound("kee", (int)me->query("max_kee")+1, target, "cast");
                COMBAT_D->report_status(me);
                me->heart_beat();
                //attacker die here.
        } 

        return 3+random(5);
}


