#include <ansi.h>

inherit SSERVER;
int check_fight(object me, int amount, object weapon);
private int remove_effect(object me, int amount);
int perform(object me)
{
    object weapon = me->query_temp("weapon");  
    int skill;
    
    if(!me->is_fighting() )
                return notify_fail("�������˼䡹ֻ����ս����ʹ�á�\n");

    if ( (int)me->query_skill("jiuyin-xinjing", 1) < 100 )
        return notify_fail("����ڹ��ȼ�����������ʹ�á������˼䡹��\n");
	
        if (!PFM_D->valid_family(me, "��˿��"))
                return notify_fail("�������˼䡱ֻ����˿�����˲ſ����ã�\n");
    
    if ( (int)me->query_skill("yinsuo-jinling", 1) < 100 )
        return notify_fail("����������岻����죬�����������ӡ������˼䡹��\n");
    
    if (!weapon || weapon->query("skill_type") != "whip"
    || me->query_skill_mapped("whip") != "yinsuo-jinling")
        return notify_fail("�������޷�ʹ�á������˼䡹����߷�������\n");
    
    if ( (int)me->query("force") < 500 )
        return notify_fail("����������̫��������ʹ�á������˼䡹��\n");
    
    if ( (int)me->query_temp("YSJL_tian") ) 
        return notify_fail("������ʹ�á������˼䡹��\n");
    
    if (me->query_skill_mapped("force") != "jiuyin-xinjing")
        return notify_fail("����ڹ������޷�ʹ�á������˼䡹��\n");

    message_vision(HIY "$N��ʱһ���ߺȣ����������Ѫ�����۶���������������"+weapon->name()+"����ת���������ն̣���
���൱���ܡ�"+weapon->name()+"����������������ƻã����۵�����ô�������������Ǳ����˳�ȥ��\n"NOR, me);
//    me->start_busy(2);
    me->add("force", -300);          
    
    skill = me->query_skill("yinsuo-jinling")/2;
	me->add_temp("apply/dodge",  skill);    
    me->add_temp("apply/parry",  skill);
    me->add_temp("apply/attack",  skill/2);
    me->set_temp("YSJL_tian", 1);

    check_fight(me, skill, weapon);
    return 1;
}

int check_fight(object me, int amount, object weapon)
{  
    object wep;    
    if(!me) return 0;
    wep = me->query_temp("weapon");  
    if(!me->is_fighting() || !living(me) || me->is_ghost() || !wep || weapon != wep )
        remove_effect(me, amount);

    else {
	call_out("check_fight", 1, me, amount, weapon);
	me->start_perform(1, "�����˼�");
    }
    return 1;
}

private int remove_effect(object me, int amount)
{
	me->add_temp("apply/dodge", -amount);
    me->add_temp("apply/parry", -amount);
    me->add_temp("apply/attack", -amount/2);
    me->delete_temp("YSJL_tian");
    if(living(me) && !me->is_ghost())
      message_vision(GRN"���ã�$N��ʹ�����˼����������ƽϢ��һ���ָֻ���ԭ״��\n"NOR, me);
    return 0;
}
