
#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="������";
        return str;
}

string get_help(string str)                
{
        str="ָ�����������������������\n"
        +"�������ˣ�";
        return str;
}

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�������ף�\n");

        if(!me->is_fighting())
                return notify_fail("������ֻ����ս����ʹ�ã�\n");
        
        if (!PFM_D->valid_family(me, "���ƶ�"))
                return notify_fail("�������ס�ֻ�л��ƶ����˲ſ����ã�\n");

        if((int)me->query("force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("moyun-shou", 1) < 50)
                return notify_fail("���Ħ���ּ��𻹲�����ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");

        message_vision("\n$N���һ���������ס���\n", me);

        target->start_busy(random(2));

        me->set_temp("moyunshou_per", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("moyunshou_per");

        me->receive_damage("kee", 50);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1+random(2));
        return 1;
}

