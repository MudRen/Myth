// Created by waiwai@2002/12/05
// ����ļ���no_pk_time.c  killer.c 

#include <ansi.h>

int update_condition(object me, int duration)
{
	object ob1, ob2,  where;
	ob1=new("/u/waiwai/npc/ghost.c");
	ob2=new("/u/waiwai/npc/ghost.c");
	where =environment(me);

	if( wizardp(me) && !userp(me) ) return 0;

	// ֻ׷ɱ�ڰ�ȫ�����������ȫ��֮�⽻��Ѳ��׷ɱ
//	if( !where->query("no_fight") || !where->query("no_kill") || !where->query("no_magic") )  return 0;
	if( me->is_ghost() ) return 0;

	if( duration >= 15 ) {
	if( random(100) > 15 ) {
	tell_object(me,HIB"\n���������ɵص״��𲢳�����߷��˹���������\n"NOR);
	if( !wizardp(me) )  {
	message("vision",HIB"\n���������ɵص״��𲢳�����ߵ�"+log_id(me)+"���˹���������\n"NOR, environment(me), me);
	message("vision",CYN+
	me->name() + "���������������ʲô�����£�������������\n"NOR, environment(me), me);
	}
	ob1->move(where);
	ob1->kill_ob(me);
	ob1->set_leader(me);
	ob2->move(where);
	ob2->kill_ob(me);
	ob2->set_leader(me);
	}else{
	tell_object(me,HIB"\n��ĺ��������ʲô�����ڸ��ţ�����\n"NOR);
	if( !wizardp(me) ) 
	message_vision(HIB"$N�ĺ��������ʲô�����ڸ��ţ�����\n"NOR,me);
	}
	}

	else if( duration >= 1 ) {
	if( random(100) > 15 ) {
	tell_object(me,HIB"\nһ�������ɵص״��𲢳�����߷��˹���������\n"NOR);
	if( !wizardp(me) ) {
	message("vision",HIB"\n���������ɵص״��𲢳�����ߵ�"+log_id(me)+"���˹���������\n"NOR, environment(me), me);
	message("vision",CYN+
	me->name() + "���������������ʲô�����£�������������\n"NOR, environment(me), me);
	}
	ob1->move(where);
	ob1->kill_ob(me);
	ob1->set_leader(me);
	}else{
	tell_object(me,HIB"\n��ĺ��������ʲô�����ڸ��ţ�����\n"NOR);
	if( !wizardp(me) ) 
	message_vision(HIB"$N�ĺ��������ʲô�����ڸ��ţ�����\n"NOR,me);
	}
	}

//	if( !me->query_condition("no_pk_time") ) {
	if( !me->query_condition("killer") ) {
	me->clear_condition("ghost");
	return 1;
	}

	if( duration < 1 || me->query("no_poison")>0 ) return 0;
	return 1;
}

string query_type(object me) { return "ghost"; }

int no_clear_condition() { return 1; }
