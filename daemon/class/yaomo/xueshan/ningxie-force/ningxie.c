//ningxie-force��Ѫ��

#include <ansi.h>
inherit SSERVER;


int exert(object me, object target)
{
        int lvl,lvl2;
        if( !me->is_fighting() )
                return notify_fail("ֻ����ս���жԵ���ʹ�ã�\n");
        lvl = me->query_skill("ningxie-force",1);
        if(!target)target = offensive_target(me);
        if(target==me) target = offensive_target(me);
        if( (int)me->query("force") < 500 )
                return notify_fail("�������������\n");
        if( lvl < 100 )
                return notify_fail("��ġ�������Ѫ�������̫ǳ���ò�������Ѫ�󷨡���\n");
        lvl = me->query_skill("force")*me->query("force")/me->query("max_force");
        lvl2 = target->query_skill("force")*target->query("force")/(target->query("max_force")+1);
        message_vision(HIW+"$N��ɫһ������������ѩ��ĺ�����\n"+NOR,me);
        if(random((me->query("combat_exp")))>(int)target->query("combat_exp")/2 )
        {
                message_vision(HIW + "$N������������$n�����ĺ����������ţ�\n$N��ȫ�������ˣ�\n"+NOR,target,me);
                target->receive_damage("kee",target->query("kee")/4, me, "exert");
                target->receive_wound("kee",target->query("kee")/4, me, "exert");
                target->set_temp("last_damage_from", me);
                target->start_busy(lvl/(lvl2+1)+1);
        }
        else
        {
                message_vision(HIW + "$N����Σ�գ����м��ˣ��㿪�˴�ʽ��\n"+NOR,target);
        }
        me->add("force", -200);
        me->start_busy(1+random(2));
        return 1;
}


