// liushen.c �����һ

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
                return notify_fail("��Ҫ��˭ʩչ��һ�С������һ����\n");

        if(!me->is_fighting())
                return notify_fail("�������һ��ֻ����ս����ʹ�ã�\n");
		if(me->query("class")!="sanjie")
           return notify_fail("�������һ��ֻ������ɽ���˲ſ����ã�\n");

        if((int)me->query("force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("liushenjue", 1) < 100)
                return notify_fail("�����������𻹲�����ʹ����һ�л������ѣ�\n");

	me->delete("env/brief_message");

	message_vision(HIR"\n$N���һ���������һ����\n"NOR, me);


	me->set_temp("liushenjue_per", 6);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete_temp("liushenjue_per");

	me->receive_damage("kee", 50);
	me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(2);
	return 1;
}
