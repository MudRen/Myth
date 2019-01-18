#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail(HIR"��Ҫ��˭ʹ�ú���\n"NOR);

        if((int)me->query_skill("gouhunshu", 1) < 30 )
                return notify_fail("��Ĺ�������򲻹��������õó����У�\n");
   
        if((int)me->query("mana") < 40+(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("force") < 200 )
                return notify_fail("��������������޷��������\n");

        if((int)me->query("sen") < 40 )
                return notify_fail("���������ǲ��壬����Լ��Ե��ˣ�\n");

        me->add("mana", -50-(int)me->query("mana_factor"));
        me->add("force", -150);
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 150 ) 
        {
                write("��һ�κ����顣\n");
                return 1;
        }

        msg = HIG "$NͻȻ�ڿն��𣬿��иߺ������дʣ��ſ��������$n����Χס��\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) 
        {
                damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 10);
                damage -= ((int)target->query("max_mana") / 10 + random((int)me->query("eff_sen") / 10));
                damage +=((int)me->query("mana_factor")-random((int)target->query("mana_factor")));
                damage +=((int)me->query_spi()-random((int)target->query_spi()));
                //here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) 
                {
                        //finally damage also depends on enabled spells level.
                        damage +=damage+random((damage*(int)me->query_skill("spells"))/240);
                        msg += HIM "���$n�ֲ��嶫���ˣ�\n" NOR;
                        target->receive_damage("sen", damage, me, "cast");
                        target->receive_wound("sen", damage*2, me, "cast");
                        target->receive_damage("kee", damage*2, me, "cast");
                        target->receive_wound("kee", damage*3, me, "cast");
                        target->start_busy(1);
                        me->improve_skill("gouhunshu", 1, 1);
                        me->start_busy(2);
                }
                else 
                {
                        //here, cast failed and the target's mana_factor will be added to the previous 
                        //damage to hurt yourself:(...note, damage<0.
                        msg += HIC "�������$n�Է���һ�ƣ�����$N�ؾ��ȥ��\n" NOR;
                        damage -= (int)target->query("mana_factor");
                        damage -= random((-damage*(int)target->query_skill("spells"))/250);
                        me->receive_damage("sen", -damage, target, "cast");
                        me->receive_wound("sen", -damage, target, "cast");
                        me->receive_damage("kee", -damage, target, "cast");
                        me->receive_wound("kee", -damage, target, "cast");
                        //  me->improve_skill("taiyi", 1, 1);
                }
        } 
        else
        msg += "���Ǳ�$n�㿪�ˡ�\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
                else if( damage < 0 ) COMBAT_D->report_status(me);
                //damage=0 corresponding to "���Ǳ�$n�㿪�ˡ�\n"--no report.   

        if( !target->is_fighting(me) ) 
        {
                if( living(target) ) 
                {
                        if( userp(target) ) target->fight_ob(me);
                        else me->kill_ob(target);
                }
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}

