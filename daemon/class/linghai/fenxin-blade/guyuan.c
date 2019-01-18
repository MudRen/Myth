
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
       object weapon;
       string msg;
       int p,skill,damage;
       int d;
       
       if( !target ) target = offensive_target(me);

       if(!objectp(weapon = me->query_temp("weapon"))
        ||(string)weapon->query("skill_type") != "blade")
            return notify_fail("��ʹ�õ��������ԡ�\n");

       if( !target 
        || !me->is_fighting(target) )
            return notify_fail("����Թ��ֻ����ս���жԶ���ʹ�á�\n");


               if ( me->query("gender") =="����" ) 
                    return notify_fail("�����������к���̫���ʰ�..?\n");
       if((int)me->query_skill("fenxin-blade", 1) < 180 )
            return notify_fail("��ķ��ĵ����ȼ�����!\n");       

       if (me->query_skill_mapped("force") != "linghai-force")
            return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

       if ((int)me->query_skill("linghai-force", 1) < 180 )
            return notify_fail("����躣�ķ��ȼ�����!\n");    
      
       d = (int)me->query_skill("fenxin-blae",1);

       if ((int)me->query_skill("blade", 1) < d )
            return notify_fail("��Ļ��������������!\n");    

       if ((int)me->query_skill("lingbo-steps", 1) < 150 )
            return notify_fail("����貨΢���������!\n");    

       if ((int)me->query("sen") < 1000)
            return notify_fail("��ľ���̫��,�ƺ��޷�����һ��!\n");

       if ((int)me->query("force") < 800 )
            return notify_fail("�����ڵ�����̫��!\n");

       if ((int)me->query("max_force") < 2000 )
            return notify_fail("����������̫��!\n");

           skill = me->query_skill("fenxin-blade",1)/2;
           damage = skill*3 + random(skill);
           damage = damage*2 + random(damage);
       message_vision(MAG"$Nӭ����������������������մ��ϸ����һ��꣬\n
"MAG"��欽��Ĳ�����״������ֻ������������"+weapon->name()+"\n
"MAG"˫��������ˮ������������\n"NOR, me, target);
     message_vision(WHT"          ������δ��Թ���٣�˭����ϪҶ��Ҷ��\n"NOR,me,target);
     message_vision(WHT"            �����˪��ɾ�����ͬ��ѩ����ʫ����\n"NOR,me,target); 
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       if (random(me->query_skill("force")) > target->query_skill("force")/3){
          target->receive_damage("kee", damage,me,"pfm");
          target->receive_wound("kee", damage/2,me,"pfm");
          message_vision(HIR"$n"HIR"��$N�����Ķ�����Թ�����ס��һ��������۱�������Ѫ����!\n"NOR, me, target); 
       }
       else{
  message_vision(HIW"$n�ٺ�һЦ����$N����ò��������,���ϵľ������Ӵ���!\n"NOR,me,target);
     me->start_busy(2);
     me->add("kee",-100);
     me->add("force", -200);
     
       }          
       message_vision(MAG"\n$N���ߡ�����Цһ��������ֻ��������Ѫɫ��ȴ���Խ��ġ�\n
"MAG"���⽣Ӱ�У���������õ���Ӱ���Ʈ��������"+weapon->name()+""MAG"ֱ����$n!\n"NOR, me, target);
       message_vision(WHT"         �����մ�¶����ޣ�������������ա�\n"NOR,me,target);
       message_vision(WHT"           ���������ͺ�ɣ��·�����п�֦����\n"NOR,me,target);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       target->start_busy(2);
       target->add("force", -skill*2);    
       target->add("kee", -100);
       me->start_busy(1);
       return 1;
}

