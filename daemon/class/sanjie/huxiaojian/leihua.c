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
                return notify_fail("��Ҫ��˭ʩչ��һ�С��Ứһ��䡹��\n");

        if(!me->is_fighting())
                return notify_fail("���Ứһ��䡹ֻ����ս����ʹ�ã�\n");

    if (!PFM_D->valid_family(me, "����ɽ"))
     return notify_fail("�����������ͽ��\n"); 
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((string)me->query_skill_mapped("force")!="huntianforce")
        return notify_fail("���Ứһ��䡱����Ҫ�û��챦�������ӡ�\n");
        if((int)me->query("force") < 600 )
                return notify_fail("����������㣡\n");

        if((int)me->query_skill("huntianforce", 1) < 200)
                return notify_fail("����������ޣ�ʹ����һ�л������ѣ�\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        i=(int)me->query_skill("huxiaojian",1);

        if( i < 200)
                return notify_fail("��Ľ�����������ʹ����һ�л������ѣ�\n");

        if( time()-(int)me->query_temp("fantian_end") < 4 )
                return notify_fail("����������ô����ˮ���ǲ����۾���ɳ���ˣ�\n");
message_vision(HIC"\n˼��������̣�����˼��ʱʱ������$N������˼��������ͷ��˫��΢��������������\n\n"NOR,me,target,"");
message_vision(HIR"\n���������������������Ứһ��䡱\n\n"NOR,me,target,"");
                
        mypot=(int)me->query_skill("huntianforce");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot/3 || !living(target) ) 
{       
        
  message_vision(HIG"\n$N���к��ᣬ����δ�䣬$n�ں�֮��ӿ����ͷ��\n\n"NOR,me, target,""); 
 message_vision(HIY"\n��˼����ǧ����Ľǧǧ�����ܵ�����ͷѹ�ֶ���Ŀ��밧�\n\n"NOR,me, target,"");  
         COMBAT_D->do_attack_damage(me, target);
   target->receive_wound("kee",random(me->query_skill("huntianforce")*2/5),me,"pfm");
         COMBAT_D->report_status(target);
                
         if (target->query("eff_kee")< -1000 || !living(target))  
 {str=target->name()+"��"+me->name()+"�ġ��Ứһ��䡹���������Ƕ��޴�Ѱ�١�";
         CHANNEL_D->do_channel(me, "rumor",str);
         me->delete_temp("last_channel_msg");}
        if ( random(20)>2 )
{
 message_vision(HIG"\n\n$N˫Ŀ�Ѿ�ģ������������Σ����е������˺ۻ�������Ứ��\n"NOR,me,target,"");
 message_vision(HIY"\n\n��˼��������$n��Χ��$n�����о��Լ����еĿտյ�����\n\n"NOR,me,target,"");
         COMBAT_D->do_attack_damage(me, target);
     target->receive_damage("kee",random(me->query_skill("parry")),me,"pfm");
         COMBAT_D->report_status(target);
   
              target->start_busy(1);
             }
          
        if ( random(20)>4 )
{
 message_vision(HIG"\n\n$Ņͷ����$n�����Σ����λ��仨��ȥ����ˮ����ˮ���������Ứ��\n"NOR,me,target, "");
message_vision(HIY"\n\n$n����$N����ˮ��������Ứ���䣬�ں�֮�ⷺ������ͷ��\n\n"NOR,me,target, "");
         COMBAT_D->do_attack_damage(me, target);
         target->receive_wound("sen",random(me->query_skill("spells")*7/4));
         COMBAT_D->report_status(target);
   
             }
          
        if ( random(20)>10 )
{
message_vision(HIG"\n\n��Ȼ������ˣ��ο�Ϊ֮���ᣬ$N�������ڿ��е��Ứ˫���������ͻ��Ứ��䡣\n"NOR,me,target,"");
message_vision(HIY"\n\n$n��$N��¶΢Ц���в��죬�����ۼ���������$N���Ứ���裬�ٸд��Ʋ�������Ѿ�����\n\n"NOR,me,target,"");
         COMBAT_D->do_attack_damage(me, target);
  target->receive_wound("kee",random(me->query_skill("huntianforce")*2),me,"pfm");
         COMBAT_D->report_status(target);
                me->start_busy(1);
              target->start_busy(1+random(2));
   
             }
          
}
     
    else  {message_vision(HIC"\n$N�������壬���Ѷ��������һ�棬��$N�������ã������ӣ�\n"NOR, target,0,"");
                me->start_busy(random(2)+1);
               }
               
        me->add("force", -150);
        me->receive_damage("sen", 50);
        me->set_temp("fantian_end",time());
        return 1;
}
