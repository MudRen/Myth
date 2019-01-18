//baxian.c �����ɴ���weiqi...980307

#include <ansi.h>

inherit SSERVER;

void npc_attack(object invoker, object target, string npc, object where);

int cast(object me, object target)
{
	string msg;
	string npc_dir = "/d/qujing/wuzhuang/npc/";
	object where;

	if( !target ) target = offensive_target(me);

	if( !target
	||   !target->is_character()
	||   target->is_corpse()
	||   target==me)
		return notify_fail("�����������˭��\n");

	if((string)me->query("family/family_name") != "��ׯ��" )
		return notify_fail("���ֲ�����ׯ�۵��ӣ����������������ˡ�\n");

	if((string)target->query("family/family_name") == "��ׯ��" )
		return notify_fail("ͬ���භҲ�а��ɰ�æ��\n");

	if((int)me->query_skill("taiyi", 1) < 20)
	    	return notify_fail("���̫���ɷ���Ϊ����벻�����ɡ�\n");
	
	if((int)me->query("mana") < 200 )
		return notify_fail("��ķ���������û�취֪����ɡ�\n");

        if (!target->is_fighting(me))
               return notify_fail("ֻ����ս���в����ٻ����ɣ�\n");
	if((int)me->query("sen") < 10 )
		return notify_fail("���������ǲ��壬�����������������ˣ�\n");

	me->add("mana", -200);
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) 
	{
		write("�ף���һ�κ����顣\n");
		return 1;
	}

	msg = HIC "$N���һ�������ɺ��ڣ�\n"+
	       "ֻ������һ���������������Ǭλ��������"+
	       "��������λ���ɹã���������λ�����������\n"+
	       "$Nһָ$n�����ˣ�\n\n" NOR;	
	message_vision(msg, me, target);
	msg = HIC "$n����$N����������üһһӵ�����ˣ��������㣡\n" NOR;	
	message_vision(msg, me, target);
	target->kill_ob(me);
	
	where=environment(target);
	call_out("npc_attack", 2, me, target, npc_dir+"ludongbin", where);
	call_out("npc_attack", 3, me, target, npc_dir+"hexiangu", where);
	call_out("npc_attack", 5, me, target, npc_dir+"tieguaili", where);
	call_out("npc_attack", 6, me, target, npc_dir+"hanzhongli", where);
	call_out("npc_attack", 8, me, target, npc_dir+"lancaihe", where);
	call_out("npc_attack", 9, me, target, npc_dir+"hanxiangzi", where);
	call_out("npc_attack", 11, me, target, npc_dir+"caoguojiu", where);
	call_out("npc_attack", 12, me, target, npc_dir+"zhangguolao", where);

	me->start_busy(2+random(2));
	return 30+random(30);
}

void npc_attack(object invoker, object target, string npc, object where)
{
	object attacker;
	int rd;
	string tid;

	if(!invoker || !target) return;

	if( environment(invoker) != environment(target) ) return;
	if( environment(target) != where) return;

	seteuid(getuid());
	attacker = new(npc);
	attacker->move(environment(invoker));

	//do not attack too weak ppls...
	if( (int)target->query("daoxing")+(int)target->query("combat_exp") < 10000 )
	{
		tid = (string)target->query("id");
		rd = random(7);
		if( rd == 0 ) attacker->command_function("maoli " + tid);
		else if( rd == 1 ) attacker->command_function("kick " + tid);
		else if( rd == 2 ) attacker->command_function("noescape " + tid);
		else if( rd == 3 ) attacker->command_function("slogan " + tid);
		else if( rd == 4 ) attacker->command_function("hit " + tid);
		else if( rd == 5 ) attacker->command_function("hammer " + tid);
		else attacker->command_function("nip " + tid);
	}
	else
	{
		COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));
	
		// give the killing credit to the invoker.
		// so this would be counted as PK if the invoker is user.
		// mon 4/11/98
		if(target->query_temp("last_damage_from")==attacker)
			target->set_temp("last_damage_from", invoker);
	
		if(target->query_temp("last_fainted_from")==attacker)
			target->set_temp("last_fainted_from", invoker->query("id"));
	}
	destruct(attacker);
}
