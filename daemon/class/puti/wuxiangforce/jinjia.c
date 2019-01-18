//Cracked by Roath
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string get_name(string str)
{
        str="������";
        return str;
}

string get_help(string str)                
{
        str="ָ�����������������\n"
        +"�����Լ��ķ�������";
        return str;
}

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("��ֻ���������ķ������Լ���\n");

        if( (int)me->query("force") < 250 )     
                return notify_fail("�������������\n");
                
        if (!PFM_D->valid_family(me, "����ɽ���Ƕ�"))
                return notify_fail("�����Ķ�͵ѧ�����书?\n");

        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("wuxiangforce",1);

        me->add("force", -250);
        me->receive_damage("kee", 10);

        message_vision(HIR"$N˫Ŀһ�������������ķ����������¶�ʱ��һƬ�����ס�������������ף�վ�����￴�����������ݡ�\n" NOR, me);

        me->add_temp("apply/armor", skill/2);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount/2);
        me->delete_temp("powerup");
        tell_object(me, "��������ķ�����һ������ϣ���⽥����ȥ�ˡ�\n");
}


