// Update by waiwai@2001/02/18

#include <ansi.h>

int update_condition(object me, int duration)
{
	// Update By waiwai@2001/06/15 ��ĳЩNpc�����ö�
	if( duration < 1 || me->query("no_poison")>0 || wizardp(me) ) return 0;

	if( duration >= 1 ) {
        tell_object( me , HIY "�����˾���֮��,ֻ����ȫ����������λ��,ʮ��ʹ�࣡����\n" NOR);

	message("vision", 
	me->name(1) + "[1;37m���ϵľ���֮�谵�˷���,���������ڵ��ϱ��ֳ���Ϊʹ��ı��飡����[0m \n",
	environment(me), me);

	if(me->is_fighting()) me->start_busy(1);

        me->add("kee",-150);
        me->add("sen",-150);
        me->add("force",-150);

       if( me->query("force") < 0 ) me->set("force",0);
	me->set_temp("death_msg",HIG"����֮�趾�˷�������������\n"NOR);
//	me->set("killbyname","����֮�趾�˷�������\n"NOR);

        me->apply_condition("hart",duration -1);
        COMBAT_D->report_status(me, 1);
	}
	return 1;
}
