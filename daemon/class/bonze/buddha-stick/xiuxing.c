
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "stick")
                return notify_fail(WHT"û�й�����ô���Ͷ������\n"NOR);

        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�������ģ���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("buddha-stick", 1) < 90 )
                return notify_fail(WHT"���Ͷ����������죬ʹ�����������ģ�����������\n"NOR);
 
        if ((int)me->query_skill("lotusforce", 1) < 90 )
                return notify_fail(WHT"����̨�ķ���򲻹���ʹ�����������ģ�����������\n"NOR);

        if (!PFM_D->valid_family(me, "�Ϻ�����ɽ")) 
                return notify_fail("ֻ�з������˲ſ����á������ģ�����������\n");

        if ((int)me->query("max_force") < 600)
                return notify_fail(WHT"��������Ϊ���㡣\n"NOR);

        if ((int)me->query("force") < 600)
                return notify_fail(WHT"��������������������ʹ���������ģ�����������\n"NOR);

        if ((int)me->query_skill("buddhism",1) < 90)  
                return notify_fail("�����Է�Ϊ�ϳ˷�����������̫�\n");  
 
        me->delete("env/brief_message"); 
     
        message_vision(HIW"\n$N��ϥ�����������д�Ի������Ӧ��ס���ġ���Ӧ��ס�Ƿ��ġ���Ӧ������ס�ġ�\n"NOR, me, target); 
        message_vision(HIW"\n����һ���������㡣��������̥����ʪ�������������Թʡ�������ס��Ϊ��ס�ʡ�\n"NOR, me, target); 
        message_vision(HIW"\n����ɫ����ɫ�������������롣���������������롣���������缰����˵�����գ������գ�������\n\n"NOR, me, target);
        

        if( ((random(me->query("combat_exp")) + (me->query("combat_exp")/2) > (int)target->query("combat_exp")/2 ))) 
        {
                message_vision(HIY"$n��$N�ķ������ж������ó���������֪���롣\n"NOR,me,target);
                damage = me->query_skill("buddha-stick",1) + random(me->query_skill("buddha-stick",1));
                me->add("force", -200);
                me->recevive_damage("kee", 200);
                me->start_busy(1);
                target->start_busy(2+random(2));
                target->receive_damage("kee", damage/2,me,"pfm");
                target->receive_wound("kee", damage/2,me,"pfm");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
         }
        else
        {
                me->start_busy(2);
                me->add("kee", -100);
                message_vision(HIC"$n�ȵ��������ֲ��Ƿ������ˣ��αغ����������裿��\n"NOR,me,target);
                me->add("force", -120);
         }
   
   
         return 1;
}
