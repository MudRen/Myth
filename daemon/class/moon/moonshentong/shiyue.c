// ʴ����
inherit SSERVER;
#include <ansi.h>

int cast(object me, object target)
{
        string msg;
        int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;
        int dayphase;

        dayphase =NATURE_D->query_current_day_phase();

        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("spells") < 120
         || (int)me->query_skill("moonshentong",1) < 80)
                return notify_fail("�㻹ûѧ��ʴ���䡣����\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("�����˭ʩչʴ���䣿\n");  

        if(target->query("mark/moon_poison") == 1)
                return notify_fail(target->query("name")+"�Ѿ���а�ˣ�\n");  

        if((int)me->query("mana") < 300 )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���޷����о�����\n");
        //write(dayphase+"\n");
        if (dayphase < 21 && dayphase > 3)
                 return notify_fail("ʴ����ֻ��ҹ�����ʩչ��\n");

        me->add("mana", -300);
        me->receive_damage("sen", 10);

        msg = HIC
"$N��ͷĬĬ�������ģ����н�������һ�Ź���ѩ�׵������ƺ��������͵Ĺ�â��\n" 
NOR;

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("daoxing")/2;
        dp = target->query("daoxing")/2;
//      if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap2 = (int)me->query_spi();
        dp2 = (int)target->query_spi();

        ap3 = (int)me->query("mana");
        dp3 = (int)target->query("mana");
//      if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;
        if( random((ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3))/1000+1) < (dp+2500*dp2+200*dp3)/1000 ) success = 0;

//here we compare current mana. this is important. you need recover to try again.

        if(success == 1 ){
                msg +=  HIR "$n����$N����̬֮���������ɷ������һ����ȴ�����ǹ���һ����ͻȻ����$n��\n" NOR;
                target->set("mark/moon_ice", 1);
                target->apply_condition("moon_poison", ((int)me->query_skill("moonshentong",1)/5));
                me->start_busy(1+random(2)); 
                if( living(target) ) me->kill_ob(target);

        }           
        else {
                msg +=  HIR "$N��ɫ�԰ף��ƺ�������֧�����������н�����ȥ����\n" NOR;   
                if((int)me->query("mana") > 300 )
                        me->add("mana", -300);
                me->apply_condition("moon_poison", ((int)me->query_skill("moonshentong")/10));
        } 

        message_vision(msg, me, target);
        return 1;
}

