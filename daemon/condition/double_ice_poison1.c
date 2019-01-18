//Cracked by Roath
// double_ice_poison.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
        int damage_kee=1000, damage_sen=1000;

	if(me->query("max_kee")>200)
                damage_kee=me->query("max_kee");
        if(me->query("max_sen")>200)
		damage_sen=me->query("max_sen")/5;
        if(damage_kee > 300) damage_kee = 3000;
        if(damage_sen > 300) damage_sen = 3000;
                                                	
	me->receive_wound("sen", damage_sen);
	me->receive_wound("kee", damage_kee);
        me->set_temp("death_msg","�ڹѸ����������ˡ�\n");
	me->apply_condition("double_ice_poison", duration - 1);

	if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
                message_vision("$N���˺ڹѸ�֮������Ǻ�Ѫ���磬������Ѫ����֫��б������һ���մӹײ������������Ľ�ʬһ�㡣\n", me);
	else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
                message_vision("$N���˺ڹѸ�֮����������б����Ŀȫ�ǣ��˲����ˣ������\n", me);         
	else 
                message_vision("$N�����Ҳ����ж��ˣ��ڹѸ�֮����\n", me);
		
	if( duration < 1 ) return 0;
	return 1;
}
