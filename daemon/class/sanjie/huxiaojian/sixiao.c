// sixiao.c ������Х

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int i,j;

	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������Х����\n");
//    ���������ж�by seng@2005-1-20
      if (!PFM_D->valid_family(me, "����ɽ")) 
                return notify_fail("��������Х��ֻ������ɽ���˲ſ����ã�\n");
        if(!me->is_fighting())
                return notify_fail("��������Х��ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("huxiaojian", 1) < 100)
                return notify_fail("��Ļ�Х�ʽ����𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("huxiaoquan", 1) < 100)
                return notify_fail("��Ļ�Х��ȭ���𻹲�����ʹ����һ�л������ѣ�\n");

        weapon=me->query_temp("weapon");

	if( me->query("env/brief_message") ){
		i=1;
	} else {
		i=0;
	}
	if( target->query("env/brief_message") ){
		j=1;
	} else {
		j=0;
	}	

	me->delete("env/brief_message");
	target->delete("env/brief_message");

 message_vision(RED"\n$N�ſھ���һ����Х�����춯�أ�ʹ��һ�С�������Х����\n"NOR, me,0,"");
            target->start_busy(1);

      message_vision(RED"\n������Х����һХ�쳾����"NOR, me,0,"");
	me->set("SaneJie", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

    message_vision(RED"\n������Х������Х��������"NOR, me,0,"");
	me->set("SaneJie", 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

    message_vision(RED"\n������Х������Х����٣�"NOR, me,0,"");
	me->set("SaneJie", 3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   message_vision(RED"\n������Х������Х����"NOR, me,0,"");
	me->set("SaneJie", 4);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete("SaneJie");

	if( i ) me->set("env/brief_message", 1);
	if( j ) target->set("env/brief_message", 1);



me->receive_damage("kee", 100,target);
	me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(3);
	return 1;
}
