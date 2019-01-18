// transfer.c
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{	
	object zhenshen;

	if ( me->is_fight() )
		return notify_fail("�㻹��ս����Ҫ�����Ǿ���������\n");

	if ( me->is_ghost() )
		return notify_fail("���Ѿ��ǹ��ˣ���Ҫ��ʲô��\n");

	if( (string)me->query("family/family_name")=="���޵ظ�" )
		return notify_fail("���ǹ��࣬������ʲô���ǡ�\n");

	if( (int)me->query("max_mana") <100 )
		return notify_fail("��ķ���������\n");
	
	if( (int)me->query("daoxing") < 30000 )
		return notify_fail("��ĵ��в����������˿��º��ѻ�����\n");
	
	if( (int)me->query("mana") - (int)me->query("max_mana") < 50)
		return notify_fail("��ķ������㣡\n");

	if( me->query_temp("in_hell") )
		return notify_fail("��Ļ����Ѿ������ˣ�\n");

	if( environment(me)->query("hell"))
		return notify_fail("�����������ˣ�\n");

	me->receive_damage("sen", 30);
	me->add("mana", -30);

	if( (int)me->query_skill("spells", 1) - 30 < 10 ) {
		write("��ʧ���ˣ�\n");
                return 1;
        }

	me->set_temp("in_hell", 1);

	message_vision("$N�����૵����˼������\n", me);
	message_vision(YEL"һ��������$N��������������Ʈȥ��ת�۾Ͳ����ˡ�\n"NOR, me);

	seteuid(getuid());
	zhenshen= new("/obj/npc/zhenshen");
	zhenshen->move(environment(me));
	zhenshen->invocation(me);
	me->set_temp("zhenshen", zhenshen);
	me->move("/d/death/gate");
	message_vision("�ĳ��������磬�ֳ���$N��Ӱ�ӡ�\n", me);
	me->apply_condition("in_hell", 1);	
	
  
  return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : cast chuqiao
 
���ָ��������������ǣ���Ļ�����ᵽ�����С�

ʹ�����ָ���ǻ��൱��Σ�գ���Ϊ��ʱ��Ļ����ڵ����л��ܵ���
�������в����һ���棬�������������Ҳ�ᴦ���ޱ���״̬������
��ɱ��������������Ϊһ������ɹ�Ĺ»�Ұ��

HELP
    );
    return 1;
}

