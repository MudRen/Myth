
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
        ||(string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

       if( !target 
        || !me->is_fighting(target) )
            return notify_fail("��ʥ�����衹ֻ����ս���жԶ���ʹ�á�\n");

        if ( me->query("gender") =="����" ) 
                return notify_fail("�����������к���̫���ʰ�..?\n");

       if((int)me->query_skill("shengling-sword", 1) < 220 )
            return notify_fail("���ʥ�齣���ȼ�����!\n");       

//       if (me->query_skill_mapped("force") != "jiuyin-force")
//            return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

       if ((int)me->query_skill("jiuyin-force", 1) < 200 )
            return notify_fail("�����������ľ��ȼ�����!\n");    
      
       d = (int)me->query_skill("shengling-sword",1);

       if ((int)me->query_skill("sword", 1) < 200 )
            return notify_fail("��Ļ��������������!\n");    

       if ((int)me->query("sen") < 1000)
            return notify_fail("��ľ���̫��,�ƺ��޷�����һ��!\n");

       if ((int)me->query("force") < 800 )
            return notify_fail("�����ڵ�����̫��!\n");

       if ((int)me->query("max_force") < 2000 )
            return notify_fail("����������̫��!\n");

        if( time()-(int)me->query_temp("posui_end") < 4 ) 
                return notify_fail("����������������\n");

           skill = me->query_skill("shengling-sword",1)/2;
           damage = skill*3 + random(skill);
           damage = damage*2 + random(damage);
       message_vision(MAG"$Nӭ����������������������մ��ϸ����һ��꣬\n
"MAG"��欽��Ĳ�����״������ֻ������������"+weapon->name()+"\n
"MAG"˫��������ˮ������������\n"NOR, me, target);
     message_vision(WHT"          ������δ��Թ���٣�˭����ϪҶ��Ҷ��\n"NOR,me,target);
     message_vision(WHT"            �����˪��ɾ�����ͬ��ѩ����ʫ����\n"NOR,me,target); 
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       if (random(me->query_skill("force")) > target->query_skill("force")/3){
          target->receive_damage("kee", damage);
          target->receive_wound("kee", damage/2);
          target->start_busy(3);
          message_vision(HIR"$n"HIR"��$N�����Ķ�����Թ�����ס��һ��������۱�������Ѫ����!\n"NOR, me, target); 
       }
       else{
  message_vision(HIW"$n�ٺ�һЦ����$N����ò��������,���ϵľ������Ӵ���!\n"NOR,me,target);
       }          
       message_vision(MAG"\n$N���ߡ�����Цһ��������ֻ��������Ѫɫ��ȴ���Խ��ġ�\n
"MAG"���⽣Ӱ�У���������õ���Ӱ���Ʈ��������"+weapon->name()+""MAG"ֱ����$n!\n"NOR, me, target);
       message_vision(WHT"         �����մ�¶����ޣ�������������ա�\n"NOR,me,target);
       message_vision(WHT"           ���������ͺ�ɣ��·�����п�֦����\n"NOR,me,target);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
//       me->start_busy(1);
        me->add("force", -200);
        me->receive_damage("sen", 150);
        me->set_temp("posui_end", time());
       return 1;
}

