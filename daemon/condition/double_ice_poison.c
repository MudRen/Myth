//Cracked by Roath
// double_ice_poison.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage_kee=40, damage_sen=40;

	if(me->query("max_kee")>200)
		damage_kee=me->query("max_kee")/5;
	if(me->query("max_sen")>200)
		damage_sen=me->query("max_sen")/5;
        if(damage_kee > 300) damage_kee = 300;
        if(damage_sen > 300) damage_sen = 300;
                                                	
	me->receive_wound("sen", damage_sen);
	me->receive_wound("kee", damage_kee);
	me->set_temp("death_msg","�����������ˡ�\n");
	me->apply_condition("double_ice_poison", duration - 1);
        me->set_temp("have_poison",1);

	if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
		message_vision("$N�촽���෢������ɫʱ��ʱ�࣬��������ͣ����֪������ʲôа��\n", me);
	else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
		message_vision("$N�촽���࣬��ɫʱ��ʱ�࣬����΢΢�������������������\n", me);		
	else 
		message_vision("$N���˸�������\n", me);
		
        if( duration < 1 ) {
                me->delete_temp("have_poison");
                return 0;
                }
	return 1;
}
