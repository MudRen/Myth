//by dewbaby@sk_sjsh
//�Ž�������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j;
        int kwj;

        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
           return notify_fail("�����Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        kwj = me->query_skill("kongwujian");

        if( (int)me->query_skill("kongwujian", 1) < 120 )
                return notify_fail("��Ŀ��޽��ȼ��������ٺú������ɡ�\n");

        if( (int)me->query_skill("sword", 1) < kwj )
                return notify_fail("��Ļ��������ȼ�����!\n");

        if( (int)me->query_skill("lingbo-steps", 1) < 100 )
                return notify_fail("����貨΢���ȼ��������ٺú������ɡ�\n");
            if( time()-(int)me->query_temp("meng_end") < 3 )    
                return notify_fail(WHT"[����]��������,�޷�����ʹ��!\n"NOR);    


        if( (int)me->query_skill("linghai-force",1) < 100 )
                return notify_fail("����躣�ķ��ȼ�����!\n");
                
        if( (int)me->query("max_force") < 1500 )
                return notify_fail("�������̫����!\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("�����������!\n");

        if (!objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "sword"
           || me->query_skill_mapped("sword") != "kongwujian")
            return notify_fail("����������ʹ�������Ρ���\n");
        
        i = (int)me->query_skill("kongwujian",1)/2;
        j = (int)me->query("max_force",1)/110*4+20;   
 
   message_vision(WHT"$N���б������㳯$n"WHT"������ȥ��һ�������������\n\n"HIC"$n"HIC"���Ƶýп�������ȴ�㲻���������εĽ���!\n"NOR,me,target);

        me->add_temp("apply/attack", i);
        me->add_temp("apply/sword", i);
       me->add("force", -90);
        me->add_temp("apply/damage", j);
        target->start_busy(random(2));
        target->receive_damage("kee",j,me,"pfm");
        target->receive_wound("kee", i,me,"pfm");
        target->add("force",-j);
     message_vision(WHT"$N������������������˭ͬ?˷�����ա�ѩӳ�Ļ��죬��ҹ��Ѭ������\n\n"HIC"$n"HIC"����һͷ��ˮ�����������������Σ��֮�У�\n"NOR,me,target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  

       me->start_busy(1);
       return 1;
}





