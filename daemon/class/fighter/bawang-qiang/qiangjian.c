// ǹ����

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
                return notify_fail("��Ҫ��˭ʩչ��һ�С�ǹ���ﵡ���\n");

        if(!me->is_fighting())
                return notify_fail("��ǹ���ﵡ�ֻ����ս����ʹ�ã�\n");

        if (!PFM_D->valid_family(me, "������"))
                return notify_fail(HIR"��ǹ���ﵡ�"+NOR"�ǽ���������֮�ܣ�\n");

        if((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 250)
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("bawang-qiang",1) < 100)
                return notify_fail("��İ���ǹ���𻹲�����ʹ����һ�л�������!\n");

        if((int)me->query_skill("wusi-mace",1) < 100)
                return notify_fail("�����˽ﵼ��𻹲�����ʹ����һ�л�������!\n");

        weapon1=me->query_temp("weapon");
        weapon2=present("mace", me);
        if(!objectp(weapon2)) 
                return notify_fail("û���ôǹ����?\n");

        message_vision(HIC"\n$N���㾫�񣬶��ִ̳�һǹ!\n"NOR, me, target);

        me->set_temp("BWQ_perform", 1);
        COMBAT_D->do_attack(me, target, weapon1);

        message_vision(HIC"\n����$n��æ���мܣ�$N���"+weapon2->query("name")+"��������"NOR, me, target);

        weapon1->unequip();
        weapon2->wield();

        me->set_temp("BWQ_perform", 2);
        COMBAT_D->do_attack(me, target, weapon2);

        me->set_temp("BWQ_perform", 3);
        COMBAT_D->do_attack(me, target, weapon2);

        me->delete_temp("BWQ_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

/*
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
*/

        weapon2->unequip();
        weapon1->wield();

        me->start_busy(1+random(2));

        return 1;
}

