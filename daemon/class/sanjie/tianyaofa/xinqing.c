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
                return notify_fail("��Ҫ��˭ʩչ��һ�С����项��\n");

        if(!me->is_fighting())
                return notify_fail("�����项ֻ����ս����ʹ�ã�\n");

         if ((string)me->query("class")!="sanjie")
     return notify_fail("�����������ͽ��\n"); 
         if ((string)me->query("family/family_name")!="����ɽ")
     return notify_fail("�����������ͽ��\n"); 
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((string)me->query_skill_mapped("force")!="huntianforce")
        return notify_fail("�����顱����Ҫ�û��챦�������ӡ�\n");
        if((int)me->query("force") < 600 )
                return notify_fail("����������㣡\n");

        if((int)me->query_skill("huntianforce", 1) < 200)
                return notify_fail("����������ޣ�ʹ����һ�л������ѣ�\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        i=(int)me->query_skill("tianyaofa",1);

        if( i < 200)
                return notify_fail("��İ�����������ʹ����һ�л������ѣ�\n");

        if( time()-(int)me->query_temp("xinqing_end") < 4 )
                return notify_fail("�����ң��Ĳ��ң��޷��ô��У�\n");
        message_vision(HIC"\n$N����������꣬����������ζ����ζ����ζ��\n\n"NOR,me,target);
             
        mypot=(int)me->query_skill("tianyaofa");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot/3 || !living(target) ) 
{       
        
         message_vision(HIG"\n$N����ãȻ�����߰�����������־ͳ���\n\n"NOR,me, target);  
         message_vision(HIY"\n$n��ǰ�軨��������$N�����ڸ�ʲô��\n\n"NOR,me, target);  
         COMBAT_D->do_attack_damage(me, target);
         target->receive_wound("kee",random(me->query_skill("stick")*2/5),me,"pfm");
         COMBAT_D->report_status(target);
                
         if (target->query("eff_kee")< -100 || !living(target))  
 {str=target->name()+"��"+me->name()+"�ġ��Ứһ��䡹���������Ƕ��޴�Ѱ�١�";
         CHANNEL_D->do_channel(me, "rumor",str);
         me->delete_temp("last_channel_msg");}
        if ( random(20)>3 )
{
  message_vision(HIG"\n\n$N������ľ����ȫû������ƽ���������׵ľ�ֹ��\n"NOR,me,target);
  message_vision(HIY"\n\n$n���εı��������ãȻ���������ڵĻ�������ζ��\n\n"NOR,me,target);
         COMBAT_D->do_attack_damage(me, target);
         target->receive_damage("kee",random(me->query_skill("parry")*7/5),me,"pfm");
         COMBAT_D->report_status(target);
   
              target->start_busy(1);
             }
          
}
     
         else  {message_vision(HIC"\n$N����������������Щ���ҷ������\n"NOR, target);
                me->start_busy(random(2)+1);
               }
               
        me->add("force", -150);
        me->receive_damage("sen", 50);
        me->set_temp("xinqing_end",time());
        return 1;
}
