#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int  myexp, yourexp,i,num,damage;
        object weapon;
     
 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("��ý�âֻ����ս����ʹ��.\n");
   if((int)me->query_skill("sanqing-jian",1) < 80)
    return notify_fail("������彣���ȼ�������!!\n");
   if(me->query_skill_mapped("force")!="zhenyuan-force")
   return notify_fail("��â��Ҫ��Ԫ�񹦵�֧�֡�\n"); 
   if( (int)me->query("max_force") < 800)
   return notify_fail("�������̫��,�����³���â!!\n");
   if( (int)me->query("force") < 400)
   return notify_fail("�������������!!\n");
   if(me->query_temp("jianmang_busy"))
     return notify_fail("���ˣ���âû�з���!\n");
    myexp = (int)me->query("combat_exp");
    yourexp = (int)target->query("combat_exp");
   msg = HIC
"\n$Nһ����Ц,���г���бָ����,�����³�һ�ų������â,�������԰���������!\n"
"$n�������,���Ž�âȴ�͵ñ���,����$n������ֱ�����!!\n\n" NOR;
message_vision(msg, me ,target);
damage=me->query_temp("apply/damage")+me->query("force_factor");
num=0;
 for (i=1;i<=6;i++) 
 {
    if( random(myexp)>random(yourexp))
        num++;
 }   
if(num>0)         
{
        damage=damage*num;
   msg = HIR
"\nֻ��$nһ���Һ�,��â��$n�Ķ�ͷ�ӹ�,����һ��Ѫ��!!\n" NOR;
message_vision(msg, me ,target);
   msg = HIW
"\n��â���羭�������ʴ�ת��һת,�ַɻ�$N�����.\n" NOR;
message_vision(msg, me ,target);
 target->receive_damage("kee",damage,me);
 if (random(damage)>target->query_temp("apply/armor"))
       target->receive_wound("kee",damage-target->query_temp("apply/armor"),me);
      COMBAT_D->report_status(target,1);
   if(!target->is_busy()) target->start_busy(2+random(3));
  target->kill_ob(me);
  
//COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);


}
else {
  msg = HIY
"\n$nȴʶ�����Ž�â������,����ԶԶ����һ��.\n" NOR;
message_vision(msg, me ,target);
me->start_busy(2);
}
me->add("force",-120);
me->set_temp("jianmang_busy",1);
call_out("jianmang_ok",3+random(5),me);
        return 1;
}
void jianmang_ok(object me) {
  if (!me) return;
  me->delete_temp("jianmang_busy");
}

