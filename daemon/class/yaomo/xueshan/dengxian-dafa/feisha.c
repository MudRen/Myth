// feisha.c

#include <ansi.h>

//#define SPELL_D "/adm/daemons/spelld"

inherit SSERVER;

string get_name(string str)
{
        str="��ɰ��ʯ";
        return str;
}

string get_help(string str)                
{
        str="ָ���������������\n"
        +"���÷�ɰ��ʯ�����Է���";
        return str;
}

int cast(object me, object target)
{
        int success_adj, damage_adj;
        success_adj = 110;
        damage_adj = 100;
        
        if( (string)me->query("class") != "yaomo" )
                return notify_fail("ֻ����ħ����ʩչ��ɳ��ʯ��\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��ɳ��ʯ��\n");
                
        if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");
                
        if((int)me->query("sen") < 100 )
                return notify_fail("���޷����о���\n");
                
        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);
        if( random(me->query("max_mana")) < 150 ) 
        {
                write("��ʧ���ˣ�\n");
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
                        "both",
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                        HIC "\n$NͻȻ�ڿն��𣬿��иߺ��� �� �� �磬��̫��֮��������ľ��$n��ȥ��\n
                        " NOR,
                        //initial message
                        HIR "\n���$n�����÷ֲ��嶫��������\n" NOR,
                        //success message
                        HIC "\n$n�������У�ΡȻ������\n" NOR,
                        //fail message
                        HIC "ɳľ��ʯ��$n�ķ���һ�ƣ�����$N��ȥ��\n" NOR,
                        //backfire initial message
                        HIC "���$n�����÷ֲ��嶫��������\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );
        me->start_busy(1+random(2));
        return 3+random(5);
}

