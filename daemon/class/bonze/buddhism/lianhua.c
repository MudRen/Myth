#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int cast(object me)
{
        int skill;
        me=this_player();


        if( (int)me->query_skill("buddhism", 1) < 50 )
                return notify_fail("��Ĵ�˷𷨵ȼ�������\n");
        if (!PFM_D->valid_family(me, "�Ϻ�����ɽ")) 
                return notify_fail("���Ƿ��ŵ��Ӳ����á��������塹��\n");
        if( (int)me->query("mana") < 300 )     
                return notify_fail("��ķ���������\n");
        if( (int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㡣\n");
        if( (int)me->query("sen") < 300 )
                return notify_fail("��ľ����㡣\n");
        if( (int)me->query_temp("anti_magic") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("spells");

        me->add("mana", -100);
        me->receive_damage("kee", 30);
        me->receive_damage("sen", 30);

        message_vision(
                HIC"$N΢һ���񣬱���ó�һ���������ɫ�������֡�\n" NOR, me);

        me->set_temp("anti_magic", skill);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->delete_temp("anti_magic");
        tell_object(me, "�����İ���������ȥ�ˡ�\n");
        return;
}

