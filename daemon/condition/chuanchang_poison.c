//Cracked by Roath
// chuanchang_poison.c

#include <ansi.h>

int update_condition(object me,int duration)
{
	int damage_kee = me->query("max_kee")/10; 
	int damage_sen = me->query("max_sen")/10;
	int myyf = me->query_skill("yaofa", 1)/10;
	int ff = me->query("force")/100;

	// ������, ������
	if(ff < 1) ff = 1;
	damage_kee /= ff;
	damage_sen /= ff;

	// ������, ������
	if(myyf < 1) myyf = 1;
	damage_kee /= myyf;
	damage_sen /= myyf;

	if(damage_kee < 10) damage_kee = 10;
	if(damage_sen < 10) damage_sen = 10;

        me->receive_wound("sen", damage_sen);
        me->receive_wound("kee", damage_kee);
        me->set_temp("death_msg","�������������ˡ�\n");
        me->apply_condition("chuanchang_poison", duration - 1);
        me->set_temp("have_poison",1);

	if ((int)me->query("kee") < (int)me->query("max_kee")/4)
		message_vision(HIR "$N���絶�������������£��������ò��ᡣ\n" NOR, me);
	else if ((int)me->query("kee") < (int)me->query("max_kee")/2)
		message_vision(RED "$N˫����ס����������������������۵�������\n" NOR, me);
	else
		message_vision("$N�е�����һʹ�����ɵû���һ����\n", me);

        if( duration < 1 ) {
                me->delete_temp("have_poison");
                return 0;
                }
        return 1;
}
