//��ʹ���� jue.c
//by junhyun@SK

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int success, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || target->is_corpse()
        || target==me)
                return notify_fail("��Ҫ��˭����ʹ������\n");

        if((int)me->query("force") < 4000 || (int)me->query("max_force") < 4000 )
                return notify_fail("���������������������ʹ������\n");

        if((int)me->query("force") < 1500 || (int)me->query("max_force") < 1500 )
                return notify_fail("�����������������ʹ����ʹ������\n");

        if((int)me->query_skill("rouqingjian", 1) < 400)
                return notify_fail("�����ָ���齣����������ʹ����һ�л������ѣ�\n");

        if((int)me->query("sen") < 100 || (int)me->query("sen") < (int)me->query("max_sen")/2 )
                return notify_fail("���޷����о�����\n");

        if( (int)me->query("combat_exp") < (int)target->query("combat_exp")/10  )
                return notify_fail("�Է�����ǿ̫���ˣ����Ǳ������ɣ�\n");

        if( random(me->query("max_force")) < 2000 ) {
                write("��ʧ���ˣ�\n");
                return 1;
        }

        msg = HIW"$N����Խ��Խ��������ȥ���Լ����˵Ĺ�ȥ���֣����ɾ�����ʹ����
"+HIM"�����������������Ը���������ǰԵô����
"+HIW"$N����Ͱ��˻�ǰ���²���糲�ʱ�Ļ�����ɵó��ˡ�������

"+HIR"$N���뵽�����������ȥʱ����������飬�����к��ޱ���˫�۵��龰����
"+HIR"ͻȻ��$N����ȫ���ѪҺ�ڷ��ڡ���
"+HIW"$N���������������û���㣬�һ��Ż���ʲô���壿��
�������ʱ��$N�·𿴵����������ڶ��Լ�΢Ц����
"HIW"$N���쳤Х�����ζ�ת������$n���˹��������г�����ת���ۡ���һ�������Լ������ţ�\n" NOR;

        success = 1;
        ap = me->query_skill("rouqingjian");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        ap = 4*ap; //this is for ƴ�� so easier.
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;

        ap = (int)me->query("max_force");
        dp = (int)target->query("max_force");
        if( ap < random(dp) ) success = 0;

        if(success == 1 ){//now both die.
                msg +=  HIR "$n��$N�ľٶ��Ŵ��ˣ�һ��ûע�ⱻ$N͸������Ľ�������ؿڣ���ʱ����һ���ҽУ�\n��$NҲ����һ̱�����ڵ��ϡ�\n" NOR;
                message_vision(msg, me, target);

                target->kill_ob(me);
                me->kill_ob(target);
                //to produce killing messages.

                me->add_maximum_mana(-100);
                me->add_maximum_force(-50);
                me->save();
                //successed, attacker lost 100 max_fali and 50 max_neili.
                
     target->receive_damage("sen",target->query("max_sen")+1,me);
                target->receive_wound("sen", (int)target->query("max_sen")+1, me);
     target->receive_damage("kee",target->query("max_kee")+1,me);
                target->receive_wound("kee", (int)target->query("max_kee")+1, me);
                COMBAT_D->report_status(target);
  target->heart_beat();
                //target die here.

        me->receive_damage("sen", (int)me->query("max_sen")+1, target);
                me->receive_wound("sen", (int)me->query("max_sen")+1, target);
        me->receive_damage("kee", (int)me->query("max_kee")+1, target);
                me->receive_wound("kee", (int)me->query("max_kee")+1, target);
                COMBAT_D->report_status(me);
  me->heart_beat();
                //attacker die here.

        }
            
        else {
                msg +=  HIR "$n�����龰���˲���ʲô����ˣ��͵�һ���㿪����������һ����\n$N��̾һ��������һ̱�����ڵ��ϡ���Ǵ���һ˿΢Ц����\n" NOR;
                message_vision(msg, me, target);

                target->kill_ob(me);
                me->kill_ob(target);
                //to produce killing messages.

                me->add_maximum_mana(-50);
                me->add_maximum_force(-25);
                me->save();
                //failed, attacker lost 50 max_fali and 25 max_neili.
                
        me->receive_damage("sen", (int)me->query("max_sen")+1, target);
                me->receive_wound("sen", (int)me->query("max_sen")+1, target);
        me->receive_damage("kee", (int)me->query("max_kee")+1, target);
                me->receive_wound("kee", (int)me->query("max_kee")+1, target);
                COMBAT_D->report_status(me);
    me->heart_beat();
                //attacker die here.
        } 

        return 3+random(5);
}


