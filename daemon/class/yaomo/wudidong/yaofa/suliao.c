// ������������

#include <ansi.h>

int cast(object me, object target)
{
	int mymana=me->query("mana"), cost=200, cure;
	string msg;

	if(me->is_busy())
		return notify_fail("����æ���أ������������ɣ�\n");
	if(me->query("family/family_name") != "�ݿ�ɽ�޵׶�"
	|| me->query_skill("yaofa", 1) < 70)
		return notify_fail("������࣬����޷��������ơ�\n");

        if( mymana < cost*2 )
                return notify_fail("��ķ���������\n");

	if (cost<mymana/2) cost=mymana/2-1;

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		cost=cost*2;

	cure=me->query("max_kee")-me->query("eff_kee");
	cure=cure/2;

	if(!me->is_fighting())
	{
		cost=cost/2;
		msg=HIY"$N˫�־�����ǰ����������״�����˼����䡣\n"NOR,
		msg+=HIY"�漴��$N��˫����ȫ�����²���һ�飬˫�ֵ������˿ھ�Ȼ���˴�룡\n"NOR;
		me->start_busy(random(8-me->query_kar()/5));
	}
	else
	{
		msg=HIY"��æ֮�У�$NͻȻԽ��սȦ����ָ���˶��䡣\n"NOR;
		msg+=HIY"һ˲�䣬$N�沿������ʢ����������ȥʱ��$N���ϴ���˿ھ�Ȼ�Ѿ��տ��ˣ�\n"NOR;
		me->start_busy(1);
	}
        me->receive_curing("kee", cure);
        me->add("mana", -cost);
	message_vision(msg, me);
        return 1;
}


