//by dewbaby@sk_sjsh
//�����¡�

#include <ansi.h>
#include <combat.h>
inherit SSERVER;


int perform(object me, object target)
{
        object weapon,ob;
        string msg;
         int myexp,yourexp;
        int busy;    
        int hyjf;
        int damage;    
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�����¡���\n");
           if ((string)me->query("family/family_name")!="�躣��")
                return notify_fail("�㲻���躣�����ˣ�����͵ѧ���ģ�\n"); 
         if( !me->is_fighting() )
                return notify_fail("�����¡�ֻ����ս����ʹ�á�\n");

         if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("�ĸ�ʦ������������µ�?\n");

         if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

         if( (int)me->query_skill("huanyue-jianfa", 1) < 120) 
                return notify_fail("��ġ����½������������޷�ʹ�ô���!\n");

         hyjf = (int)me->query_skill("huanyue-jianfa",1);

         if( (int)me->query_skill("sword",1) < hyjf)
                return notify_fail("��Ļ��������ȼ��������޷�ʹ�������¡� ��\n");

         if (me->query("force") < 300)
                return notify_fail("�������������޷�ʹ����һ�С�\n");

         me->clean_up_enemy();
         ob = me->select_opponent();
         myexp = (int) me->query("combat_exp");
         yourexp = (int) target->query("combat_exp");
         busy = (int)me->query_skill("parry",1)/54;
message_vision(HIY"\n$N�ڿ�Ծ������ָ�����죬�ڿ��л��˸�Բ�����ֽ������ƣ����಻��������"HIW"�躣��"HIY"ǧ�ž���"BLINK""HIR"����\n"NOR,me,target);        
    
message_vision(HIR"\n\n            ���µ�����˭������ÿ��ѽڸ���Բ��\n"NOR,me,target);
message_vision(HIR"\n\n            ��ĺ�����۾����𣬱�ˮ������������\n"NOR,me,target);
message_vision(HIR"\n\n            ����Ҷ���㼸���ᣬɽ���Ѿ�׼���ߡ�\n"NOR,me,target);
message_vision(HIR"\n\n            ������Ѿ�Ӧͣ�����ֿ��µ����꺮��\n"NOR,me,target);

         damage=(int)me->query_skill("parry")+random((int)me->query_skill("sword"));
         if(random(myexp)>yourexp/8)
         {
                
          msg = HIY "��������˭���ģ�ǧɽ���¿���ϧ����ҹ��������£�������������Ϧ.....��\n" NOR;
          message_vision(msg, me, target);
          target->start_busy(3);
          target->receive_damage("kee",damage);
          target->receive_wound("kee",damage/3);
          target->receive_damage("sen",damage);
          target->receive_wound("sen",damage/2)+20;
          COMBAT_D->report_status(target);
      }
      else {
            message_vision(HIW"$n�������ģ�һ����Ц��������˾�����ϧ���Թ������³��¡���\n"NOR,me, target);
          me->start_busy(2);
          me->add("force", -100);
  

  }
          if( wizardp(me) && (string)me->query("env/combat")=="verbose" )    

          message_vision(msg, me, target); 
     return 1;  
}


