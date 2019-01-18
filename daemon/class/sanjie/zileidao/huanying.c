#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail(RED"��ʲô��Ц��ûװ������ôʹ�����λ�Ӱ����\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("�����λ�Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("zileidao", 1) < 90 )
   return notify_fail(WHT"������׵���������죬��ʹ���������λ�Ӱ����\n"NOR);
    if( (int)me->query_skill("huntianforce", 1) < 70 )
         return notify_fail(RED"��Ļ��챦����Ϊ�������������λ�Ӱ��������ʽ��\n"NOR);
    if ((int)me->query("max_force")<300)
   return notify_fail(RED"���������Ϊ���㣬�޷����㡸���λ�Ӱ����������\n"NOR);
    if ((int)me->query("force")<200)   
          return notify_fail(HIC"����������������û�ܽ������λ�Ӱ��ʹ�꣡\n"NOR);
  
    msg = HIC "$N���һ����ȫ���Ĵ��ζ���$nֻ����$N����������Ӱ�����쵶��ϯ�������\n $n����һ�ܣ���$N������·��$nֻ��סһ����\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/3||
   random((int)target->query("combat_exp")) < (me->query("combat_exp")) )
    {
   //me->start_busy(2);
  // target->start_busy(random(3));
   damage = (int)me->query_skill("zileidao", 1);
   damage = damage + random(damage);
   target->receive_damage("kee", damage);
   target->receive_wound("kee", damage/3);
//   target->add("eff_kee", -damage/2);
   target->receive_damage("sen", damage/3);
//   target->add("eff_sen", -damage/4);
   msg += HIC"$n����û����ܣ���ʱ����������$n��ͷ��\n"+HIR"$n��Ѫ����$n�Ծ���ǰһƬ�ʺ죬��ס���ߣ�\n"NOR;
   me->add("force", -damage/5);
     me->start_busy(random(3));
   if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                                  } 
    }else
    {
   me->start_busy(2);
   msg += HIY"����$p���Կ����������У����������̹Ȼ��ԣ�����ֻ�м�ס����ʵ�С�\n"NOR;
    }
    message_vision(msg, me, target);
    return 1;
}
