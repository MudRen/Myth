//Ansi 99.8

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap;

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("��Ҫ��˭ʩ�����񡹣�\n");

        if((int)me->query_skill("taoism", 1) < 100 )
                return notify_fail("�����ʦ�ɷ���򲻹����Ŀ��ܺ����������񡹣�\n");
        if(!me->query("shushan/jiushen_master"))
                return notify_fail("�㻹���ᡸ�������ַ�����\n");

        if((int)me->query("mana") < (int)me->query("max_mana") )
                return notify_fail("��ķ��������������������񡹿���Ҳû��ʲô�ã�\n");

        if((int)me->query("force") < (int)me->query("max_force") )
                return notify_fail("������������������������񡹿���Ҳû��ʲô�ã�\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���������ǲ��壡\n");

        me->set("mana", 0);
        me->set("force", 0);

        msg = HIR "$N����ȫ������ͻȻ�����������������񡹣��������춯�ص��𶯣�\n" NOR;
        msg = HIR "\n        
                      ��#
                      @  @_                  
                    ��    @    
                     @     @    
                     _*****_   
                   ��    ��  @  
                   @         @   
                    @   ɽ    @  
    _________________@_______@______         
  ��____________________________iiiiii)***  
                              @��^^^^^  *****
                                           ***\n"NOR;

        ap = me->query_skill("spells") ;
        damage = (me->query("force")+ me->query("mana")) / 10;
        damage += (int)me->query("sen")/5 + ap + (int)me->query("mana_factor") - random((int)target->query("mana_factor"));
        damage = damage + random(damage)+ random(damage);
        if (damage > 2000) damage = 2800+ random(200);
        msg += HIC "���$n�����������ˣ�\n" NOR;
        target->receive_wound("sen", damage, me, "cast");
        target->apply_condition("drunk",50);
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_sen_status(target);

        if( !target->is_fighting(me) ) 
        {
                if( living(target) ) 
                {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        me->start_busy(2+random(2));
        return 10+random(10);
}

