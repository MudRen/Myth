// Jiz

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="�������";
        return str;
}

string get_help(string str)                
{
        str="ָ���������������\n"
        +"������𣬺캢���ľ��У�";
        return str;
}

int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 110;
        damage_adj = 90;

        if( !target ) target = offensive_target(me);

         if( !me->is_fighting() ) 
         return notify_fail("ֻ��ս���в���ʹ���������\n"); 

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("��Ҫ��˭���������\n");

        if((int)me->query_skill("pingtian-dafa", 1) < 30 )
                return notify_fail("���ƽ��󷨻�򲻹���������ó����\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("��ķ��������������������û��ʲô�ã�\n");

        if((int)me->query("force") < 100 )
                return notify_fail("��������������޷�����������\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���������ǲ��壬����Լ������ˣ�\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 50 ) {
                message_vision(HIM"$N���������дʡ�������ʲôҲû�з�����\n"NOR,me);
                return 1;
        }
        
        me->receive_wound("kee", 10);

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
HIC "$N�����ڱ���������������ʱ��Ѫֱð��ͻȻ��Ȼ��������������һ����$n��ȥ��\n" NOR,
                        //initial message
HIC "���$n���յý�ͷ�ö\n" NOR,
                        //success message
HIC"\n�����$n�㿪�ˡ�\n"NOR,
                        //fail message
HIC "������汻$n�Է���һ�ƣ�����$N�ؾ��ȥ��\n" NOR,
                        //backfire initial message
HIR"\n���$n��ܲ��������յý�ͷ�ö\n" NOR,
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(2+random(2));
        return 3+random(5);
}


