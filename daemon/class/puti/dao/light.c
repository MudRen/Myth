// light.c

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="�����";
        return str;
}

string get_help(string str)                
{
        str="��ĸ��˾����֮Ů���ֳ����������������Ӣ��ò���ţ�˫\n"
        +"�ָ��־����������÷������ۣ��Գ����䡣\n\n"
        +"ָ��������������衡������������\n"
        +"�����繥�����ˡ�";
        return str;
}


int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 100;
        damage_adj = 100;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�������\n");

        if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("���޷����о�����\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 50 ) {
                write("������ĸ����û�ա�\n");
                return 1;
        }
        

        SPELL_D->attacking_cast(
                me, 
                        //attacker 
                target, 
                        //target
                success_adj,    
                        //success adjustment
                damage_adj,     
                        //damage adjustment
                "qi",           
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "\n$N�������˾����ģ�����߳�һλ��ò���ŵĵ�ĸ��˫�ָ���һöͭ����ͭ����ת����������һ���������$n��\n" NOR,
                        //initial message
                HIR "\n������͡���һ��������$n����͸�������\n�ϳ�һ��������Ѫ����ֱ�䵽��������ĵ��£�\n" NOR, 
                        //success message
                HIC "����ͣ���һ��$n�ŵ���һ�ɽ�ζ������ֻ�յ��˼���ͷ����\n" NOR, 
                        //fail message
                HIC "���ǽ�ⱻ$n�Է�������������$N��ȥ��\n" NOR, 
                        //backfire initial message
                HIR "�������$n����͸��������ϳ�һ��������Ѫ����ֱ�䵽��������ĵ��£�\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}


