// tuntian.c
#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="ħ������";
        return str;
}

string get_help(string str)                
{
        str="ָ�������������������\n"
        +"��ʨ��ħ�ľ�����";
        return str;
}

int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 120;
        damage_adj = 120;


        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչħ�����죿\n");

        if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("���޷����о�����\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 50 ) {
                write("���ˣ�����ʨ�Ӳ�֪����ȥ�ˣ�\n");
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
                HIC "\n$N�������˾����ģ��������һֻ���������ʨ�ӣ��ſ�Ѫ������$nҧȥ��\n" NOR,
                        //initial message
                HIR "\n���$n��ҧ�˸����ţ�\n" NOR, 
                        //success message
                HIC "\n$n��æһ��������һ�ԡ�\n" NOR, 
                        //fail message
                HIC "ֻ��$nһ��ŭ������ʨ���ŵñ治�෽�򣬷���ҧ����$N��\n" NOR, 
                        //backfire initial message
                HIC "���$n��ҧ�˸����ţ�\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}

