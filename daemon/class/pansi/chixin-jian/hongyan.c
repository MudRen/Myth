// jie 2001-2-3
// chixin-jian ���հ׷�

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,lvl;
	int i;
	object weapon,ob;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���հ׷�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("���հ׷�ֻ�ܺͳ����鳤������ͣ�\n");
//        if (!PFM_D->valid_family(me, "��˿��"))
//        return notify_fail("�����հ׷���ֻ����˿�����˲ſ����ã�\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("���հ׷�ֻ�ܺͳ����鳤������ͣ�\n");
	if ( (string) me->query_skill_mapped("sword") != "chixin-jian")
	return notify_fail("���հ׷�ֻ�ܺͳ����鳤������ͣ�\n");
//        if (me->query_skill_mapped("force")!="jiuyin-xinjing")
//                return notify_fail("ֻ���þ����ľ��������ú��հ׷���\n");
        if((int)me->query("force") < 100 )
                return notify_fail("�������������\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
        if( time()-(int)me->query_temp("hongyan_end") < 3 )   
                return notify_fail(CYN"����������ô���̾��\n"NOR);   
        extra = me->query_skill("chixin-jian",1) / 8;
        extra += me->query_skill("yueying-wubu",1) / 8;
        me->add_temp("apply/attack", extra);    
	me->add_temp("apply/damage", extra);
	me->receive_damage("kee", 100);
	msg = HIM  "$N��̤����Ӱ�貽�ݣ��������裬ʹ���۳����鳤�����ݵľ��裭��
	\n"HIR"             ������"HIW"�׷���
	\n"MAG"����ֻ��$N����ƮƮ��ȹ�����ǣ�������Թ���ɷ��\n\nʹ�����龡�⴦�������������е�"+ weapon->name() +MAG"��˫ָ�ֵ����ޱ������뵰����$n��\n\n" NOR;
        target->start_busy(1);
	message_vision(msg, me, target);
	msg =  HIW ""+ weapon->name() +HIW"���糤����գ��·���ʧ��������\n\n" NOR;
        message_vision(msg, me, target);
        me->clean_up_enemy();
        ob = me->select_opponent();
		lvl=extra;
    if(lvl>3) lvl =3;
	for(i=0;i<lvl;i++)
	{
	msg = HIY "$N��Ŷ��Х�������䣭������
				      ��Ϊ�������Ƶ˼�ź��籡������\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
//        me->start_busy(random(extra/4));
//        me->start_busy(2+random(2));
        me->set_temp("hongyan_end",time());   
	return 1;
}
