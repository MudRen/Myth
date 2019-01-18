// ice_poison.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage_kee=10, damage_sen=10;

	if(me->query("max_kee")>200)
		damage_kee=me->query("max_kee")/30;
	if(me->query("max_sen")>200)
		damage_sen=me->query("max_sen")/30;
        if(damage_kee > 5) damage_kee = 5;
        if(damage_sen > 5) damage_sen = 5;
                                                	
	me->receive_wound("sen", damage_sen);
	me->receive_wound("kee", damage_kee);
	me->set_temp("death_msg","�������ĺ��ⶳ���ˡ�\n");
	me->apply_condition("bp_poison", duration - 1);

	if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
		message_vision("$N�촽���෢������������ͣ����֪������ʲôа��\n", me);
	else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
		message_vision("$N�촽���࣬����΢΢�������������������\n", me);		
	else 
		message_vision("$N���˸�������\n", me);
		
	if( duration < 1 ) return 0;
	return 1;
}


