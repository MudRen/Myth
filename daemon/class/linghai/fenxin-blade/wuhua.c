
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;
        if( !target ) target = offensive_target(me);

       if (!objectp(weapon = me->query_temp("weapon"))
          || (string)weapon->query("skill_type") != "blade")
                    return notify_fail("��ʹ�õ��������ԡ�\n");

                    if( !target  
                    ||      !target->is_character()  
                    ||      target->is_corpse()  
                    ||      target==me)  
                    return notify_fail("���޻���ֻ����ս���жԶ���ʹ�á�\n");

      if((int)me->query_skill("fenxin-blade", 1) < 50 )
                    return notify_fail("��ķ��ĵ����ȼ�������\n");       
            
      if ((int)me->query_skill("lingbo-steps", 1) < 80 )
                    return notify_fail("����貨΢���ȼ�������\n");    
   
      if ((int)me->query_skill("blade", 1) < 50 )
                    return notify_fail("��Ļ�������������!\n");    
     
      if ((int)me->query("force") < 200 )
                    return notify_fail("�������̫����!\n");

      if ((int)me->query("max_force") < 500 )
                    return notify_fail("����������̫��!\n");    
    message_vision(HIM"$Nǰ�����ߣ���������������"+BLINK""+ weapon->name()+ NOR" "+HIM"ԽʹԽ�죬������ӰѤ����ٻ���š�\n\n"HIC"$n"HIC"����$N��"BLINK""+weapon->name()+ NOR""+HIC"�������ߣ�����ȴ���������ۻ����ҡ�\n"NOR,me,target);
        
           target->add("force",-300);
           target->add("kee", -200);
           target->start_busy(2);
           me->start_busy(random(1));    
           
           return 1;

}




