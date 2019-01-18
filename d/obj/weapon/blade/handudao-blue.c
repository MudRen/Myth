//handudao-blue.c
//this blade has ice_poison with it...weiqi, 970926.
//add duandao�ϵ�����...weiqi, 980203.

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIB "����" NOR, ({"ice blade", "blade", "dao"}));
	set_weight(5000);
	set("unit", "��");
	set("long", "һ�ѵ���ɫ����Ө͸�����䵶���Դ�ѩɽ��ǧ�겻���ĺ����Ƴɡ�\n");
	set("value", 8000);
	set("material", "ice");
	set("wield_msg",
"$N��ৡ���һ�����һ��$n�������У��������һ�����⣡\n");
	set("unwield_msg",
"$N�����е�$n�������䣬������������˿�����\n");

	init_blade(20);

	if( clonep(this_object()) ) {
		set_default_object(__FILE__);
	}
	setup();
}

void init()
{
	add_action("do_duandao", "duandao");

	remove_call_out("do_melt");
	call_out("do_melt", 1);
}

void do_melt()
{
   if(this_object()) call_out("melt", 40+random(40));
}

void melt()
{
	object env;

        if(!this_object()) return;
// no pk date...
// mudring Feb/03/2005
if (userp(this_object())) return;

	env=environment(this_object());

	if( env->is_character() )
	{//a player or a NPC.
		if( (int)env->query_skill("ningxie-force", 1) < 20 )
		{
			message_vision("$N�������������ģ�ʪʪ�ģ�ԭ���Ǳ������ˡ�\n", env);
			env->apply_condition("ice_poison", 10);
			//note, �ж��ˡ�
			destruct(this_object());
			return;
		}
	}

	else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
	{//a room.
		if( (string)env->query("outdoors") != "xueshan" )
		{
			tell_object(env,"�������ڻ�����һ̲ˮ�����õ������ǡ�\n");
			destruct(this_object());
			return;
		}
	}

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int diff;

	if( damage_bonus < 0 ) return 0;
	diff = random((int)me->query("force_factor")+1) - random((int)victim->query("force_factor")/2+1);
	//here we let force_factor determine who hurts who:)
	//the attacker has more chance of course.

	if(diff > 0)
	{
		victim->apply_condition("ice_poison", diff + (int)victim->query_condition("ice_poison") );
		message_vision("$N����һ�������˵��ϵĺ�����\n", victim);
	}
	else if(diff < -3)
	{//for very weak ppl or npc, also possible to "force back", this
	 //is to ensure it'll not happen.
		me->apply_condition("ice_poison", -diff + me->query_condition("ice_poison") );
		message_vision("$N����һ����ԭ���ǵ��Ϻ�����$n���˻��������˲��ɷ�������\n", me, victim);
	}
	else 
		message_vision("$N����һ����Ϯ����������˵��ϵĺ�����\n", victim);
}

int do_duandao(string arg)
{
	string msg;
	int success, ap, dp;
	object me, target;

	me = this_player();
	
	if( this_player()->is_busy() )
		return notify_fail("����æ���أ����п������ϵ���\n");

	if( me->query("force") < 300 ) return notify_fail("��Ҫ������������������\n");

	if( ! arg )
	{
		message_vision(HIW "$N����һ��ֻ�������Ľ���һ�ѱ�����ʱ��Ϊ������Ƭ��\n" NOR, me);
		me->start_busy(3);

		me->add("force", -100);
		destruct(this_object()); //let this ice blade disappear.
		return 1;
	}

	//now find the target...
	if( !objectp( target = present(arg, environment(me)) ) )
		return notify_fail("�����ñ�����˭��\n");

	if( !target->is_character() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if( !living(target) )
		return notify_fail(target->name() + "���޻���֮����һ������ȥ���ɣ��α���ҫ����\n"); 

	if(target==me)     return notify_fail("����ɱ��\n");

	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("�㲻��������͵Ϯ���ˡ�\n");

	msg = HIW
"$N����һ��ֻ�������Ľ���һ�ѱ�����ʱ��Ϊ������Ƭ��$n�����ȥ��\n" NOR;
	//produce kill here...
	target->kill_ob(me);

	success = 1;
	ap = me->query_skill("throwing");
	ap = ap * ap * ap /10 ; //usually no throwing skill, so not useful...
	ap += (int)me->query("combat_exp");
	ap = 2*ap; //make it easier.
	
	dp = target->query_skill("dodge");
	dp = dp * dp * dp /10 ; //dodge is useful here.
	dp += target->query("combat_exp");
	if( random(ap + dp) < dp ) success = 0;
	//here we compared exp and throwing, dodge levels. 

	//now check if the target is busy or no_move...
	//if so, we set success = 1.
	if(success == 0)
	{//here only check this if previously failed.
		if( target->is_busy() || target->query_temp("no_move") ) 
		//target can not move at all...
		{
			if( target->query("force")/40 > (10+me->query("force_factor")) )
			//btw, target still have chance...
			{		
				msg +=  HIW "���$n��Ȼ�������ã��˹�Ӳ��֮�£���Ҳ�����󺦡�\n" NOR;
				message_vision(msg, me, target);	
				me->start_busy(3);

				me->add("force", -200);
				destruct(this_object()); //let this ice blade disappear.
				return 1;	
			}
			else success = 1; 
		}
	}//end of check �������á�

	if(success == 1 )
	{
		msg +=  HIW "���ǧ��Ƭ����û����룬$n��ʱ����һ���ҽУ�\n" NOR;
		message_vision(msg, me, target);

		//here also apply poison..
		target->apply_condition("ice_poison",  5 + (int)me->query("force_factor")/5 + (int)target->query_condition("ice_poison") );

		target->receive_wound("kee", random(3*me->query("force_factor"))+50, me);
		COMBAT_D->report_status(target);
	}    
	else
	 {
		msg +=  HIW "���$n����һ�������˿�ȥ��\n" NOR;
		message_vision(msg, me, target);		
	}
	
	me->start_busy(3);

	me->add("force", -200);
	destruct(this_object()); //let this ice blade disappear.
	return 1;	
}

