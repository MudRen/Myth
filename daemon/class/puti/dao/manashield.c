#include <ansi.h>

string get_name(string str)
{
        str="������";
        return str;
}

string get_help(string str)                
{
        str="ָ�������������������\n"
        +"�����������ɷ�100���������1000"
        +"�����Լ��ķ�������";
        return str;
}

int cast(object me, string spl,object target)
{
        int skill,flag;

        if( me->query_temp("apply/manashieldflag") )
                return notify_fail("�������������ڷ�����״̬��\n");
                
        if (!PFM_D->valid_family(me, "����ɽ���Ƕ�"))
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á������ܡ�?\n");

        if( (int)me->query("mana") < 300 )
                return notify_fail("��ķ�������ʹ�÷����ܣ�һ��Ҫ��300������\n");
                
        if( (int)me->query("max_mana") < 1000 )
                return notify_fail("��ķ�����Ϊ����ʹ�÷�����!\n");
        
        
        skill = me->query_skill("dao",1);
        if(skill<100)
                return notify_fail("��ĵ����ɷ���Ϊ��������\n");

        me->add("mana", - 300);

        message_vision(
                HIM "$N�����۾�ĬĬ���˼������ֻ����˫��һ�ӣ�һ�������İ�͸�����Ƴ�����$N����ǰ��\n" NOR, me);

        me->set_temp("apply/manashieldflag", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (skill/2)+30);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me)
{
        me->delete_temp("apply/manashieldflag");
        tell_object(me,HIM "����ǰ�ķ����ܽ�����ʧ�ˣ�\n" NOR);
}

