//��ʱpfm
//Created by wuyou@sk

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg,*limbs;
        int i,size,damage,num;

        if( !target ) target = offensive_target(me);
        if( !target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�����������\n");

//    ���������ж�by seng@2005-1-20
// 18      if( me->query("family/family_name")!="����ɽ") 
// 19         return notify_fail("�㲻������ɽ��, ����ʹ�á���!��!��!����\n");
        if( (int)me->query_skill("huxiaojian",1) < 50)
                return notify_fail("��Ŀǰ������ʹ����������������\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("�������������\n");
        me->add("force", -60);
        msg = WHT"������������������������������������������������\n"NOR;
        message_combatd(msg,me,target,"");
        me->start_busy(1+random(1));

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/8 ) 
        {
                        
                limbs=target->query("limbs");                   
                size=(int)(me->query_skill("huxiaojian")/5);
                damage=random(size)+size;
                damage=damage+me->query_str()+random(me->query_temp("apply/damage"));
                num=random(size/2)+size/2;
                for(i=0;i<=num;i++)
                {
                        msg =HIR"$NͻȻ���һֻ�׻�ҧ��$p"+limbs[random(sizeof(limbs))]+"��\n"NOR;
                        message_combatd(msg,me,target,"");
                   target->receive_damage("kee",damage,me,"pfm");
                   target->receive_wound("kee",damage,me,"pfm");
                }
                COMBAT_D->report_status(target);
                
        }
        
        return 1;
        
}


