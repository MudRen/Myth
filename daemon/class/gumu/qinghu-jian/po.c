//��ԯ��Ĺ ������� �ơ�������
//by junhyun@SK
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
 string msg;
 object weapon, weapon2;
 int skill, ap, dp, damage;

 me->clean_up_enemy();
 target = me->select_opponent();

 skill = me->query_skill("qinghu-jian",1);

 if( !(me->is_fighting() ))
  return notify_fail(HIW"���ơ������С�"NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( time()-(int)me->query_temp("po_end") < 5 ) 
                return notify_fail("�����ö��˾Ͳ����ˣ�\n"); 
 if (!objectp(weapon = me->query_temp("weapon"))
 || (string)weapon->query("skill_type") != "sword")    
  return notify_fail("��ʹ�õ��������ԡ�\n");


 if( skill < 110)
  return notify_fail("�����������ȼ�����, ����ʹ�á��ơ������С���\n");

 if( me->query("force") < 1000 )
  return notify_fail("��������������޷��ٻ��籩����\n");

 msg = HIC "$N����"+weapon->name()+HIC"�ڿ��л���һ�˰�Բ��ͬʱ���һ��"+HIW"�ơ������С�

"+HIG"��ʱ�䣬�������˻��������˪......

"HIY"$n��ǰ�����Ǻ��⽣Ӱ���ٸие�һ�ɾ޴��ѹ��������Լ���\n";
 message_vision(msg, me, target);

 damage = 10 + random(skill / 2);

 ap = me->query_skill("fork") +4*skill ;
 dp = target->query_skill("force") + 4;

 if( dp < 1 )
  dp = 1;                        

 if( random(ap) > random(dp) )
 {
           me->add("force",-100);
          if (objectp(weapon2 = target->query_temp("weapon")))
                {
                 msg = "ͻȻ$n�����ֱ�һ�飬����";
                 msg += weapon2->name();
                 msg += "���ֶ�����\n" NOR;
                 message_vision(msg, me, target);
                 weapon2->move(environment(me));
                 return 1;
                }
  target->receive_damage("kee", damage,me,"pfm");
  target->start_busy(4+random(skill)/20);
 msg = "$n���������Ķ������ᣬ��ʱ�����ٳ���\n";
 message_vision(msg, me, target);
// me->start_busy(1);
        me->set_temp("po_end",time());
 return 1;
        }
 else
 {
   me->add("force",-100);
 if (objectp(weapon2 = target->query_temp("weapon")))
{
  msg = "����$n������$N����ͼ�����̽�����" + weapon2->name() + "��
 �÷��겻͸��ʹ$N�ġ��ơ������С�û�������á�\n"NOR;
 message_vision(msg, me, target);
  me->start_busy(2);
 return 1;
}
 msg = "˭֪$n���и�����û��������$N��ʱ�����ٳ���\n";
 message_vision(msg, me, target);
me->start_busy(2);
 return 1;
 }
                                       
 return 1;
}

