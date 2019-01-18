#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        
        object *inv, obj, obj1;
        int i, mypot,tapot;
        string str;

        object weapon;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���Ϭָ����\n");

        if(!me->is_fighting())
                return notify_fail("����Ϭָ��ֻ����ս����ʹ�ã�\n");

        if (!PFM_D->valid_family(me, "�Ϻ�����ɽ")) 
                return notify_fail("����Ϭָ���Ƿ��ŵ��ӵľ�ѧ��\n");
                
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 600 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        i=(int)me->query_skill("jienan-zhi",1);

        if( i < 150)
                return notify_fail("��Ľ���ָ���𻹲�����ʹ����һ�л������ѣ�\n");

        if( time()-(int)me->query_temp("lingxi_end") < 4 )
                return notify_fail("�����ö�Ͳ����ˣ�\n");
                
        message_vision(HIY"\n$N����𷨣���Ϭ�����������������ʳָ��$n���һ�㣬һ�����͵�������$nֱ�ƹ�ȥ��\n\n"NOR,me,target);
                
        mypot=(int)me->query_skill("unarmed");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot * 4/5 || !living(target) ) 
        {       
        
                message_vision(HIR"ֻ�������͡���һ�����죬$N����ʳָ�Ѿ���$n���ϴ���һ��Ѫ������\n\n"NOR,me, target);  
                COMBAT_D->do_attack_damage(me, target);
                target->receive_wound("kee",100 + me->query_str()+random(me->query_skill("unarmed")*3/5),me,"pfm");
                COMBAT_D->report_status(target);
                
                if (target->query("eff_kee")<0 || !living(target))  
                {
                        str=target->name()+"��"+me->name()+"����Ϭָ��������Ѩ����ʱ�߿���Ѫ������";
//                        CHANNEL_D->do_channel(me, "rumor",str);
                        me->delete_temp("last_channel_msg");
                }
                else 
                {
                        if ( random(10)>1 )
                        message_vision(HIY"\n$N��ָ����������$n��Ѩ���ϣ�$n��ʱ�������鶯�����á�\n"NOR,me,target);
                        target->start_busy(4+random(3));
                }
          
        }        
     
        else  
        {
                message_vision(HIC"$Nʶ����������æʹһ�����ӷ���㿪�ˣ�\n"NOR, target);
                me->start_busy(2);
        }
               
        me->add("force", -50);
        me->receive_damage("sen", 50);
        me->set_temp("lingxi_end",time());
        return 1;
}


