//Cracked by Roath
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;
        extra = me->query_skill("qixiu-jian",1);
        if ( extra < 80) return notify_fail("���[���޽�]���������죡\n");
        extra = me->query_skill("huntian-qigong",1);
        if ( extra < 80) return notify_fail("���[��������]���������죬�޷��������޽���������\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۶����߽���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!PFM_D->valid_family(me, "�ݿ�ɽ�޵׶�"))
                return notify_fail("�㲻���ñ��ɵ����⹥��\n");

        if( time()-(int)me->query_temp("qijian_end") < 4 )    
                return notify_fail(CYN"[�����߽�]���������̫��,�޷�����ʹ�ã�\n"NOR);  
                
        if(me->query_temp("no_kuang")) 
                return notify_fail("[��ɱն]��[�����߽�]��������ʹ�ã�\n"); 
  
                
        weapon = me->query_temp("weapon");
        msg = YEL  "$N���Դ󷢣����е�"+ weapon->name()+  "��籩������$nϮ����" NOR;
                          target->stary_busy(1);
        message_vision(msg,me,target);
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        lmt = random(3)+3;
        for(i=1;i<=lmt;i++)
        {
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        me->set_temp("qijian_end",time());    
        return 1;
}

