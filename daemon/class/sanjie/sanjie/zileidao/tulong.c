// tulong.c ����ױ�������

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�����ױ�����������\n");
		if(me->query("class") != "sanjie" )
                return notify_fail("������ױ���������ֻ������ɽ���˲ſ����ã�\n");

        if(!me->is_fighting())
                return notify_fail("������ױ���������ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("zileidao", 1) < 200)
                return notify_fail("�������ױ����������𻹲�����ʹ����һ�л������ѣ�\n");

  if (me->query_temp("sanjie_pfm_busy")) return notify_fail("�����õ�̫��̫�ľͲ����ˡ�\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision(HIC"\n$N���㾫������һת��������������$n���������У�\n"NOR,me,target);

        message_vision(HIC"\n$N��һ�С������ױ�����"NOR,me,target);
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIC"\n$N�ڶ��С������׵�����"NOR,me,target);
        me->set_temp("QJB_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        message_vision(HIC"\n$N�����С��������׺䣡"NOR,me,target);
        me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N�����С�������������"NOR,me,target);
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N�����С��������������"NOR,me,target);
        me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N�����С������ױ�������"NOR,me,target);
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N�����С���ŭ��˺���ѵأ�"NOR,me,target);
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }


  me->set_temp("sanjie_pfm_busy",1);
  me->set_temp("no_move",1);
  call_out("remove_no_move",3,me);
        call_out("remove_effect",5+random(3),me);
        return 1;
}

void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("sanjie_pfm_busy");
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
