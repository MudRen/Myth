#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, forcee;
        int kee_wound;

	where=environment(me);
	if( where->query("no_fight") )
		return notify_fail("��ȫ���ڲ�����������������\n");
        if( !me->is_fighting() )
                return notify_fail("��תǬ��ֻ����ս����ʹ�á�\n");
        if( me->query("family/family_name")!="����ɽ")
                return notify_fail("��������ɽ�Ĳ����á���תǬ������\n");
        if( (int)me->query("force") < 800 )
                return notify_fail("�������������\n");
	if( (int)me->query("kee") < 200)
		return notify_fail("������������ˡ�\n");
        if( (int)me->query_skill("huntianforce", 1) < 120 )
                return notify_fail("��Ļ��챦����Ϊ��������ʹ����һ�л������ѣ�\n");
                
        skill = me->query("force");
	forcee = target->query("force")/5-50;
        me->add("force", -400);
        me->receive_damage("kee", 150);

        me->start_busy(3);
	message_vision(HIR "\n$N������ϣ���������˫�ֶ���һָ�������������������ڼ��ã�\n��ʱ���ذ��������޹⣬��صߵ���\n��һ����������ġ���תǬ������\n\n"
NOR, me);
        if( skill +random(skill) > target->query("max_force"))
        {
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        kee_wound = me->query("eff_kee")/(6+random(8));
	me->receive_damage("kee", 50);
	target->add("kee", -kee_wound);	
	target->add("eff_kee", -(kee_wound));
	target->add("force",-(forcee));
	me->add("force", -100);
	message_vision(HIW"$n�����ڵء��������أ�ȫ��������ʧ��\n"NOR,me, target);
	target->start_busy(1);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
         }
         }
         else 	message_vision(HIY"����$p������$P����ͼ����û���ϵ���\n" NOR, me, target);
         	       
        return 1;
}

