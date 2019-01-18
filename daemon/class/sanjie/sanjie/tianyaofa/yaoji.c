// yaoji.c ��������

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������������\n");
		if(me->query("class") != "sanjie" )
                return notify_fail("������������ֻ������ɽ���˲ſ����ã�\n");

        if(!me->is_fighting())
                return notify_fail("������������ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 250 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	i=(int)me->query_skill("tianyaofa",1)+(int)me->query_kar();
        if( i < 50)
                return notify_fail("����������񷨼��𻹲�����ʹ����һ�л������ѣ�\n");

  	if (me->query_temp("sanjie_pfm_busy")) return notify_fail("�����õ�̫��̫�ľͲ����ˡ�\n");
	message_vision(HIC"\n$N���㾫��һ�������ڿգ�ʹ���ˡ������������ľ�����\n"NOR,me);

	me->delete("env/brief_message");
	target->delete("env/brief_message");

        me->set_temp("QJB_perform", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 200+random(100));
        me->add("force", -50);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   	me->set_temp("sanjie_pfm_busy",1);
   	me->set_temp("no_move",1);
   	call_out("remove_effect",1+random(3),me);
   	call_out("remove_no_move",1,me);
        return 1;
}

void remove_effect(object me) {
  if (me)  me->delete_temp("sanjie_pfm_busy");
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
