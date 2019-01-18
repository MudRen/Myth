#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        int skill, skill1, skill2;
        object weapon1, weapon2;

        if(!target) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С������ҡ���\n");

        if(!me->is_fighting())
                return notify_fail("�������ҡ�ֻ����ս����ʹ�ã�\n");

        if(me->query("family/family_name")!="�䵱ɽ������")
                return notify_fail("��������Ӳ����á������ҡ���\n");

        if((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 250)
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("xuantian-sword",1) < 100)
                return notify_fail("������콣����������죬ʹ����һ�л�������!\n");

        if((int)me->query_skill("chunqiu-blade",1) < 100)
                return notify_fail("��Ĵ��ﵶ����������죬ʹ����һ�л�������!\n");

        weapon1=me->query_temp("weapon");
        weapon2=present("sword", me);
        if(!objectp(weapon2)) 
                return notify_fail("û����ôʩչ�������ҡ�?\n");

        message_vision(HIM"\n$N����"+weapon1->query("name")+HIM"ˢˢ����������ֱ��$nȫ��Ҫ��!\n"NOR, me, target);

        me->set_temp("CQD_perform", 1);
        COMBAT_D->do_attack(me, target, weapon1);
        COMBAT_D->do_attack(me, target, weapon1);
        COMBAT_D->do_attack(me, target, weapon1);
        COMBAT_D->do_attack(me, target, weapon1);

        message_vision(HIC"\n$n��æ�ڴ�$N�ĵ���������ʱ��$N���"+weapon2->query("name")+HIC"��$n��ȥ��"NOR, me, target);

        weapon1->unequip();
        weapon2->wield();

        me->set_temp("CQD_perform", 2);
        COMBAT_D->do_attack(me, target, weapon2);
        COMBAT_D->do_attack(me, target, weapon2);

        me->set_temp("CQD_perform", 3);
        COMBAT_D->do_attack(me, target, weapon2);
        COMBAT_D->do_attack(me, target, weapon2);

        me->delete_temp("CQD_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        weapon2->unequip();
        weapon1->wield();

        me->start_busy(2);

        return 1;
}

