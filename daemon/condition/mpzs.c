// [1;31m���ļ���ֹ��������κ�����[0m
// Created by waiwai@2001/02/18
// ����׷ɱ"��"�ļ�

#include <ansi.h>

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int ratio;
	string mp;
	// Update By waiwai@2001/06/15 ��ĳЩNpc�����ö�
	if( duration < 1 || me->query("no_poison")>0 ) return 0;

	mp = me->query("ZSmenpai");

	// ׷ɱ��ʱ����Сʱ
	if( me->query("vendettaFT") && time() - me->query("vendettaFT") > 10800 ){
		message("channel:rumor",
		HIY"������׷ɱ��"HIR+log_id(me)+"������"HIW"��"+mp+"��"HIR"׷ɱ��ʱ������ֹ��\n"NOR,users());
		me->clear_condition("mpzs");
		me->remove_all_killer();
		me->delete("vendettaFT");
		me->delete("vendetta/"+mp);
		me->save();
	 	return 1;
	}

	if( !me->query("vendettaFT") || !userp(me) ) return 0;

	ratio = (int)me->query("eff_sen")*100 / (int)me->query("max_sen");

    	if (ratio > 0) 
		tell_object(me, "��������з��飬�о����ƺ���������"+mp+"׷ɱ������\n");

	me->receive_damage("kee", duration/10);
	me->receive_damage("sen", duration/10);

//	me->apply_condition("mpzs", duration - 1);

	me->set_temp("death_msg",HIW"������"+mp+"׷ɱ�������ƶ���������\n"NOR);

	if( !duration ) return 0;

	return CND_CONTINUE;
}

