// thunder.c

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="������";
        return str;
}

string get_help(string str)                
{
        str="�׹����ֵ����ˣ���ν���ס����׼����ף����ף�ˮ�ף����ף�\n"
        +"���ס�����ΪȮ�ף����Σ����ӥ�ǣ����ֳָ������ֳ�׶��\n"
        +"�������ڻ��У��������¡��������׹��ܻ����������治Т\n"
        +"֮�ˡ�\n\n"
        +"ָ�����������������򡡣�������������\n"
        +"�����繥�����ˡ�";
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
                return notify_fail("��Ҫ��˭ʩչ�����䣿\n");

        if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("���޷����о�����\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 50 ) {
                write("��⣬�׹����첻���\n");
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
                "shen",                 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "\n$N�������˾����ģ�����߳�λ��ͷӥ�ǵ��׹�������ִ����������׶����׶�������$n��ͷ��ը��һƬ���ף�\n" NOR,
                        //initial message
                HIR "\n���$n�����������ð���ǣ����񲻶����������ڵأ�\n" NOR, 
                        //success message
                HIC "\n˭֪$n���޷�Ӧ�����������Ƶġ�\n" NOR, 
                        //fail message
                HIC "�����׹���$n�Է���һ����һ��ʧ��֮�����׶�ը����$N��ͷ����\n" NOR, 
                        //backfire initial message
                HIC "���$n�����������ð���ǣ����񲻶����������ڵأ�\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}

