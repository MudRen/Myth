//Cracked by Roath
// vote_clear.c
// by Marz 04/21/96

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		if (duration > -5) {
			tell_object(me, HIM "��Ϊ��Ӧ���˲��࣬�����ͶƱȡ���ˡ�\n" NOR);
                        shout(HIW "���������Ϊ��Ӧ���˲��࣬��" + me->name(1) + "��ͶƱȡ���ˡ�\n" NOR);
		}
		me->delete("vote/reason");
	        me->delete("vote/juror");
       		me->delete("vote/count");
		            
		return 0;
	}
	
	me->apply_condition("vote_clear", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "vote";
}
