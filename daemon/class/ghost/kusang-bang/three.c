//Cracked by Roath
//Changed BY wuyou@sk_xyj 2002-12-1
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i, j, extra;               
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����ˡ�����\n");
                
        if (!PFM_D->valid_family(me, "���޵ظ�"))
                return notify_fail(HIG"�����ˡ���"+NOR"��ڤ�粻��֮�ܣ�\n");

        if(!me->is_fighting())
                return notify_fail("�����ˡ���ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("zhuihun-sword", 1) < 50)
                return notify_fail("���׷�꽣���𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("kusang-bang", 1) < 50)
                return notify_fail("��Ŀ�ɥ�����𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("hellfire-whip", 1) < 50)
                return notify_fail("����һ�޼��𻹲�����ʹ����һ�л������ѣ�\n");

        weapon=me->query_temp("weapon");

        if( me->query("env/brief_message") ){
                i=1;
        } else {
                i=0;
        }
        if( target->query("env/brief_message") ){
                j=1;
        } else {
                j=0;
        }

        extra = (int)me->query_skill("zhuihun-sword",1) / 10 +
                (int)me->query_skill("kusang-bang",1) / 10 +
                (int)me->query_skill("hellfire-whip",1) / 10;
        me->add_temp("apply/attack", extra); 
        me->add_temp("apply/damage", extra); 
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIW"\n$N˫�ֻ�һ��Բ����Ȼ������٣�������������������������"+BLINK""+HIG"�����ˡ���"NOR""+HIW"���С�\n", me);

        me->set("HellZhen", 7);
        message_vision(HIW"
                        "HBRED+HIG"������������"NOR" 
                        "HBRED+HIG"��   "NOR+BLINK+HIR"��"NOR+HBRED+HIG"   ��"NOR" 
                        "HBRED+HIG"������������\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set("HellZhen", 6);
        message_vision(HIW" 
                        "HBRED+HIG"������������"NOR"  
                        "HBRED+HIG"��   "NOR+BLINK+HIR"��"NOR+HBRED+HIG"   ��"NOR"  
                        "HBRED+HIG"������������\n"NOR,me,target);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set("HellZhen", 5);
        message_vision(HIW"
                        "HBRED+HIG"������������"NOR"   
                        "HBRED+HIG"��   "NOR+BLINK+HIR"��"NOR+HBRED+HIG"   ��"NOR"   
                        "HBRED+HIG"������������\n"NOR,me,target);   
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete("HellZhen");
        me->add_temp("apply/attack", -extra); 
        me->add_temp("apply/damage", -extra); 

        if( i ) me->set("env/brief_message", 1);
        if( j ) target->set("env/brief_message", 1);

        me->receive_damage("kee", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

