//Cracked by Roath

//Ansi 99.8
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg;
   int damage, ap;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("��Ҫ��˭ʩ�����񡹣�\n");

   if((int)me->query_skill("pansi-dafa", 1) < 100 )
     return notify_fail("�����˿�󷨻�򲻹����Ŀ��ܺ����������񡹣�\n");
   if(!me->query("pansi/love_master"))
     return notify_fail("�㻹���ᡸ�������ַ�����\n");

 if((int)me->query("mana") < (int)me->query("max_mana") )
return notify_fail("��ķ��������������������񡹿���Ҳû��ʲô�ã�\n");

if((int)me->query("force") < (int)me->query("max_force") )
    return notify_fail("������������������������񡹿���Ҳû��ʲô�ã�\n");

 if((int)me->query("sen") < 10 )
     return notify_fail("���������ǲ��壡\n");

me->set("mana", 0);
me->set("force", 0);

   msg = HIR "$N�������˼������ģ�����һ����������ڴˣ�������ֳ�һλС��ʹ��\nֻ�����Ź��������ಡ���һ����һֻ��ɫС����$n������£�\n" NOR;
   message_vision(msg,me,target);
   msg = HIM "\n
	         ,@@@@@@,
��������    �� ,@@@@@""@@, ( ��   _  _
������  ����,��@@@@@ 6.6)@ [)�� ( @@ )
������  �� {{^L@@@C��_-_)@ [ )�� (��)
��  ������ {{!L(@@@) (@@'��[��)   ()
������  �� {{!!K) /�� )---.[.__) ������ 
������  ����\`!!K( ,�� )---[---._)
������  ���� `~`~, L��)|_.->>>==I======> ��\n"NOR;

   ap = me->query_skill("spells") ;
   damage = (me->query("force")+ me->query("mana")) / 20;
   damage += (int)me->query("sen")/5 + ap + (int)me->query("mana_factor") - random((int)target->query("mana_factor"));
        damage = damage + random(damage);
        if (damage > 1200) damage = 1150+ random(75);
        msg += HIC "���$n��������һ�����У������鶾��\n" NOR;		
        target->apply_condition("xiangsi",20);
        target->receive_wound("kee", damage,me,"pfm");
   message_vision(msg, me, target);
   if( damage > 0 ) COMBAT_D->report_sen_status(target);

   if( !target->is_fighting(me) ) 
   {
     if( living(target) ) 
     {
        if( userp(target) ) target->fight_ob(me);
        else target->kill_ob(me);
     }
     me->kill_ob(target);
   }

   me->start_busy(2+random(2));
   return 10+random(20);
}
