//Cracked by Roath
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object soldier;
	int strategy,leadership, exp, MAX_GUARD;
	if ((string)me->query("class") != "official")
	return notify_fail("�㲻�ǳ�͢���٣������Լ��չ��Լ��ɣ�\n");
        if( !me->is_fighting() )
        return notify_fail("����û����Ҫɱ�㣡\n");
	if((int)me->query("sen")< 100)
	return notify_fail("�����̫���ˣ�\n");
	strategy = (int)me->query_skill("strategy");
	leadership = (int)me->query_skill("leadership");
	exp = (int)me->query("combat_exp");
	if(strategy < 10 || leadership < 10)
	return notify_fail("�����������֮��̫���ˣ�û��Ը�����㣡\n");	
	MAX_GUARD = strategy * leadership / 10000 + 1;
	if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("�������ڵĹ�λ�����Ѿ��ܵ��㹻�ı�����\n");
	seteuid(getuid());
	me->receive_damage("sen",100);
	soldier= new("/obj/npc/danei");
	soldier->move(environment(me));
        soldier->invocation(me, (leadership+strategy));
        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
        me->remove_all_killer();
	message_vision(HIB "\n$N����һ������Ԯ��\n" NOR, me);	
	message_vision(HIB "\n$NӦ��������\n" NOR, soldier);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��alert
 
���ָ���ù�Ա���������������Լ�.
 
HELP
    );
    return 1;
}
