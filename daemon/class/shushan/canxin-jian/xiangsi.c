//xiangxi.c  
//created by DHXY-EVIL 2000.7.7
//Modified by vikee for xlqy-zq station 2000-12-5 9:05 .The CopyRight was keeped by DHXY-evil.

#include <ansi.h>
#include <combat.h>
#include <condition.h>
inherit SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����˼��������\n");

        if(!me->is_fighting())
                return notify_fail("����˼������ֻ����ս����ʹ�ã�\n");
        
        if (!PFM_D->valid_family(me, "��ɽ����"))
                return notify_fail("����ɽ�����á���˼��������\n");
        
        if(me->query("shushan/ask_zuidao_go") !=1 )
                return notify_fail("û�����ĵ���ᣬ�ò��˲���ġ���˼��������\n");
        
        if (me->query_skill_mapped("force")!="zixia-shengong")
                return notify_fail("����˼��������������ϼ�������ӣ�\n");
        
        if(environment(me)!=environment(target))
                return notify_fail("��Ҫ�������˲������\n");
                
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("zixia-shengong", 1) < 80)
                return notify_fail("�����ϼ����Ϊ��������ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("canxin-jian", 1) < 80)
                return notify_fail("��Ĳ��Ľ���Ϊ��������ʹ����һ�л������ѣ�\n");

        message_vision(HIM"$N��˼�����͵�ʩ�����Ľ��ľ��С���˼����������$n"+HIM"��������������\n"NOR,me,target);
        me->set("xiangsi", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        switch (random(4))
        {
         case 0:
              {
               message_vision(HIC"$n�������е���˼֮���Ⱦ�������鶾��\n"NOR,me,target);
               target->apply_condition("xiangsi",20);
               break;
               }
         case 1:
              {

               message_vision(HIB"һ�ɾ�������$n��$n�ƺ����˵���⣡\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              } 
         case 2:
              {
               message_vision(HIB"��������Ϊ���\n"NOR,me,target);
               message_vision(HIM"���޺ۣ�����ţ��������³������\n"NOR,me,target);  
               target->apply_condition("xiangsi",20);
               break;
              }
         case 3:
              {
               break;
              }
        }
        me->set("xiangsi", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        switch (random(4))
        {
         case 0:
              {
               message_vision(HIR"$n�������е���˼֮���Ⱦ�������鶾��\n"NOR,me,target);
               target->apply_condition("xiangsi",20);
               break;
              }
         case 1:
              {
               message_vision(HIC"һ�ɾ�������$n��$n�ƺ����˵���⣡\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              }
         case 2:
              {
               message_vision(HIW"��������Ϊ���\n"NOR,me,target);
               message_vision(HIB"���޺ۣ�����ţ��������³������\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              }
         case 3:
              {
         break;
              }
        }
        me->set("xiangsi", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        switch (random(4))
        {
         case 0:
              {
               message_vision(HIR"$n�������е���˼֮���Ⱦ�������鶾��\n"NOR,me,target);
               target->apply_condition("xiangsi",20);
               break;
              }
         case 1:
              {
               message_vision(HIG"һ�ɾ�������$n��$n�ƺ����˵���⣡\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              }
         case 2:
              {
               message_vision(HIW"��������Ϊ���\n"NOR,me,target);
               message_vision(HIM"���޺ۣ�����ţ��������³������\n"NOR,me,target);  
               target->apply_condition("drunk",20);
               break;
              }
         case 3:
              {
               break;
               }
        }
        me->delete("xiangsi");
//        me->start_busy(2+random(3));
        me->start_busy(2);

        message_vision(HIY"$N�ġ���˼�������ù���ϣ����ص���,�����չ�.\n"NOR,me,target);

        me->add("kee", -100);
        me->add("force", -250);
        me->add("sen",-100);
        return 1;
}


