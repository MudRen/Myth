/******************************************/
/* MUDLIB��Biographies         ����մ���  */
/* Created Admin By Waiwai@2001/02/18     */
/* Admin Email��wkzstory@21cn.com         */
/******************************************/
// Create by zeus@����Ц Nov.29.1999
// Last modified by waiwai@2001/04/17

#include <ansi.h>;

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int pass_time;
	object ob;

	pass_time=time()-me->query_temp("merchant/chaomai/starttime");

	if( pass_time>1800 ) {
		tell_object(me, 
HIG "�ι�(Emoc)�����㣺��Ҫ����Ļ������Ѿ��㵽�ˣ��㻹���´������ɡ�����ʧ��Ǯֱ�������������ۡ�\n" NOR );
		me->delete_temp("merchant_job");
		me->delete_temp("job");
		if ( ob=present("good check",me) )
			destruct(ob);
		if ( ob=present("check book",me) )
			destruct(ob);
		me->clear_condition("job_chaomai");
		return 0;
	} else if( pass_time > 430 && me->query_temp("job/fulltime") ) {
		tell_object(me, HIG "�ι�(Emoc)�����㣺ʱ������ķ�֮һ���㻹�ǿ��ɡ�\n" NOR );
		me->set_temp("job/quartime",1);
		me->delete_temp("job/fulltime",1);
	} else if ( pass_time > 860 && me->query_temp("job/quartime") ) {
		tell_object(me, HIG "�ι�(Emoc)�����㣺ʱ����˶���֮һ���㻹�ǿ��ɡ�\n" NOR );
		me->set_temp("job/halftime",1);
		me->delete_temp("job/quartime",1);
	} else if ( pass_time > 1290 && me->query_temp("job/halftime") ) {
		tell_object(me, HIG "�ι�(Emoc)�����㣺ʱ������ķ�֮�����㻹�ǿ��ɡ�\n" NOR );
		me->set_temp("job/lotstime",1);
		me->delete_temp("job/halftime",1);
	} else if ( pass_time > 1720 && me->query_temp("job/lotstime") ) {
		tell_object(me, HIG "�ι�(Emoc)�����㣺ʱ���Ҫ���ˣ�kick " + me->query("id") + "���㻹�ǿ��ɡ�\n" NOR );
		me->delete_temp("job/lotstime",1);
	}

	me->apply_condition("job_chaomai", duration - 1);

	if( duration < 1 || me->query("no_poison")>0 ) return 0;
	return 1;
}