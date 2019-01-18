#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int mypot,tapot,time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���޾��粨��ֻ����ս���в���ʹ�á�\n");

        if( (int)me->query_skill("fengbo-cha", 1) < 50 ) 
                return notify_fail("�����Ϊ�������ʹ������һ�У�\n");
                
        if(me->query_temp("fengbo_busy"))
                return notify_fail("��������ô��粨?\n");
                
        if( target->is_busy() )
                return notify_fail(target->name()+"�Ѿ���æ�ˣ���ʹ����Ư��Ҳ����ע�⵽��\n");

        message_vision(HIC"$N��չ��������һ�棬��һ�棬�ó�������С�⻷��$n��ȥ��
�俴��������������ȴ�����ﲨ�����಻����ʵ�ǰ���ɱ����\n\n"NOR,me, target);

        me->add("sen", -60);

        mypot=(int)me->query_skill("fork");
        mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
        time=(int)me->query_skill("fengbo-cha", 1)/10 - (int)target->query_skill("parry")/20;
    
        if ( time > 12 ) time = 12;
        if ( time < 5  ) time = 5;

        if ( (mypot+tapot)/4+random( mypot + tapot ) > tapot ) 
        {
                message_vision(HIR"$N��Ȼ����⻷��ס����ʱĿ�ɿڴ�����֪���룡\n"NOR,target);
                target->start_busy(time);
        }
        else 
        {
                message_vision(HIR"����ȴ��$N���ƣ����䲻����$n�������˸����ֲ�����\n"NOR,target,me);
                me->start_busy(3);
        }

        
                if( living(target) ) 
                target->kill_ob(me);
               
       
        me->set_temp("fengbo_busy",1);
        call_out("can_fengbo",3+random(5),me);
        return 1;
}
    
void can_fengbo(object me)
{
        if(!me) return;
        me->delete_temp("fengbo_busy");
}


