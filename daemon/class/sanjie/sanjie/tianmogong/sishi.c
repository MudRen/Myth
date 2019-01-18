// sishi.c ��ħ��ʴ

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int qi_gain, qi_lost, ap, dp, success;
	string msg;	

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
	return notify_fail("������ȡ˭��������\n");
    
	if( target == me ) return notify_fail("����ˣ�\n");

	if(target->query_temp("netdead")) return notify_fail("�û��٣���̫�񻰰ɣ�\n");

	if( (int)me->query_skill("tianmogong", 1) < 40 )
		return notify_fail("��ġ���ħ������Ϊ̫�ͣ�������ȡ������\n");

	if( (string)me->query("class") != "sanjie" )
		return notify_fail("�㲢������ɽ���ˣ�������ȡ������\n");

        if(!me->is_fighting()||!target->is_fighting())
                return notify_fail("ֻ����ս������ȡ������\n");

	if( (int)me->query("kee")  > 3*(int)me->query("max_kee")/2 )
		return notify_fail("��������̫����ӯ��������Ҫ��ը�ˡ�\n");

	qi_lost = target->query("kee") / 5;

	if(qi_lost < 5 )
		return notify_fail("�Է����Ͼ�Ҫ������û��ʲô��ե���ˡ�\n");
	
	msg = HIR"\n$N�����Ц��¶����ɭɭ��������$n"NOR+HIR"�ıǿ״��˹�ȥ���������һ����\n" NOR;

	success = 1;

	ap = me->query_skill("force");
	ap = ap * ap * ap /10 ;
	ap += (int)me->query("combat_exp");
	dp = target->query("combat_exp");
	if( random(ap)+ap/2 < random(dp)+dp/2 ) success = 0;

	ap = (int)me->query("max_mana");
	dp = (int)target->query("max_mana");
	if( random(ap*2) < dp ) success = 0;

	if(success == 1 ){
		msg +=  HIR "���$n"NOR+HIR"ͷƤһ�飬ֻ������������ԴԴ���ϵ����˳�ȥ��\n" NOR;
		qi_lost=qi_lost-random(qi_lost/2);
		target->receive_damage("kee", qi_lost, me);

		qi_gain = qi_lost;
		if( (int)target->query("max_kee") < (int)me->query("max_kee") )
			qi_gain = qi_gain * (int)target->query("max_kee")/(1+(int)me->query("max_kee"));

		if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
			qi_gain = qi_gain * (int)target->query("combat_exp")/(1+(int)me->query("combat_exp"));

		if( qi_gain > 0 ) me->add("kee", qi_gain);

		if( qi_gain > 0 
		&& (int)me->query("combat_exp") < (int)target->query("combat_exp") 
		&& (int)me->query_skill("tianmogong",1) <= 200
		&& random(3) < 1 )
		{
			me->improve_skill("tianmogong", qi_gain);
		} else {
			if( qi_gain < 0 ) qi_gain =1;
			me->improve_skill("tianmogong", qi_gain, 1);
		}
	} else {
		msg +=  HIR "���$nһŤͷ�����˿�ȥ��\n" NOR;	
	} 

	message_vision(msg, me, target);
	if( success == 1 ) COMBAT_D->report_status(target);

	if( living(target) ) target->kill_ob(me);

	me->start_busy(4);        
	return 1;
}
