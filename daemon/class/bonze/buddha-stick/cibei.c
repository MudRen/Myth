// By Cigar @sjsh_SKxyj 2002-05-20
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
        int extra;
        object weapon,ob;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("buddha-stick",1)/5;
        if( !target ) target = offensive_target(me);
if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ȱ������ġ�ֻ����ս����ʹ�á�\n");
         
    
         if( (int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

              if( (int)me->query("bellicosity") > 250 ) 
              return notify_fail("���ɱ��̫�أ��޷��ɳ������ĳ���\n"); 

              if(me->query_skill("lotusforce",1) < 180) 
              return notify_fail("����ڹ����Ӳ��㣬�޷���������š�����ȱ������ġ���\n"); 
       
              if((string)me->query_skill_mapped("force")!="lotusforce") 
              return notify_fail("������ȱ������ġ���������̨�ķ�Ϊ���ӡ�\n"); 
       
              if(me->query("family/family_name")!="�Ϻ�����ɽ") 
                      return notify_fail("���Ƿ��ŵ������˴���������������\n"); 

              if(me->query("bonze/class")!="bonze") 
                      return notify_fail("��û�г��ң���ô�������������У�\n"); 

              if(me->query("class")!="bonze") 
                      return notify_fail("�����ҷ��ţ����������������衣\n"); 


              if((string)me->query_skill_mapped("spells")!="buddhism") 
              return notify_fail("���ű����Է�Ϊ���ģ���Ҫ������С�\n"); 

              if ((int)me->query_skill("buddhism",1) < 180) 
              return notify_fail("�����Դ��Ϊ�ϳ˷�����������̫������ԡ�\n"); 


        if( (int)me->query_skill("buddha-stick",1) < 180 )
                return notify_fail("����Ͷ���������������޷�ʹ�á�����ȱ������ġ���\n");

        if( time()-(int)me->query_temp("cibei_end") < 4 )  
        return notify_fail(CYN"������ȱ������ġ����������̫��,�޷�����ʹ�ã�\n"NOR);  
        if( (int)me->query_skill("stick",1) < 180 )
                return notify_fail("��Ļ���������򲻹����޷����򡸾���ȱ������ġ��ľ��裡\n");
        if( (int)me->query_skill("force",1) < 180 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á�����ȱ������ġ���\n");
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");

        message_vision(HIW "\n$N����ֹˮ���о�������֮��ڤڤ֮�д�������������������֮��ʹ����"+HIY"������ȱ������ġ���\n" NOR,me,target);
        message_vision(HIC "\n���ư����ң�̣���ʱ��ؼ����һ˿��ɬ��һ˿������һ˿��꣮����\n" NOR,me,target);
         message_vision(HIM  "\n  �� �� ��\n" NOR,me,target);
         me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

         message_vision(HIY  "\n         �� �� ��\n" NOR,me,target);
         me->set_temp("QJB_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIW  "\n                  �� �� ��\n" NOR,me,target);
              me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIR  "\n                           �� �� ��\n" NOR,me,target);
               me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIB "\n                                    �� ������ ��\n" NOR,me,target);
           me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              me->delete_temp("QJB_perform");
        me->add_temp("apply/attack",-extra);
         me->add_temp("apply/damage",-extra);
        me->add("force", -200);
      me->set_temp("cibei_end",time());  

        return 1;
}
