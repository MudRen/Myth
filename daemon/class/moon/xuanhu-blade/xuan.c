#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
        int def;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á��������֡���\n");
    
        if( (int)me->query_skill("xuanhu-blade",1) < 40)
                return notify_fail("��Ŀǰ������ʹ�������������֡���\n");
  
        if( (int)me->query("force") < 200 )
                return notify_fail("�������������\n");
   
        if(! me->query_temp("weapon") )
                return notify_fail("������ñ�������ʹ�þ�����\n");
        me->add("force", -100);
        msg = HIC"$N����$n��ȻһЦ����ʱ������������գ�˵ʱ�٣���ʱ�죡"+
        "$N���еĵ�����˺��ͣ�ɲ�Ǽ���������������$n������ʱ��ֽ��ɷ�ס�\n"NOR;
        me->start_busy(2);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) 
        {
                //target->start_busy( (int)me->query_skill("xuanhu-blade") / 20 );
                //damage = (int)me->query_skill("xuanhu-blade", 1)+(int)me->query_skill("blade", 1);
                damage = (int)me->query_skill("blade",1);
                damage = damage + random(damage);
                def=(int)target->query_temp("apply/armor_vs_force");
                damage -=damage*def/3000;
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage,me, "pfm");
                msg += RED
"ֻ��$n�ѱ�$N�е����������Ѫ�������ȫ�����������\n"NOR;
                target->start_busy(2+ random(1+(int)me->query_skill("xuanhu-blade") / 150) );
                me->start_busy(1+random(1+(int)target->query_skill("force") / 150));
        } 
        else 
        {
                msg += HIC "����$p��æ����㿪��$P����û�еóѡ�\n" NOR;
        }
        message_vision(msg, me, target);
        if(userp(target)) target->fight_ob(me);
        else if( !target->is_killing(me) ) target->kill_ob(me);

        return 1;
}


