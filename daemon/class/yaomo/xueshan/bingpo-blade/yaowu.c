// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="�������";
        return str;
}

string get_help(string str)                
{
        str="ָ�����������������\n"
        +"���������Ǻ���120��"
        +"�ٷְ���ʹ�Է����к�����";
        return str;
}

string msg;
int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������졹?\n");
        weapon = me->query_temp("weapon");
        if(!me->is_fighting())
                return notify_fail("��������졹ֻ����ս����ʹ��!\n");

        if((int)me->query("max_force") < 1500)
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if (!weapon || weapon->query("skill_type") != "blade"  )
                return notify_fail("�������ʹ�ñ���ʱ����ʹ�ã�\n");

        if((int)me->query_skill("bingpo-blade",1) < 120)
                return notify_fail("��ı��Ǻ����ȼ�������!\n");

        msg = MAG
"\n$N����һЦ,���е�"+weapon->name()+""+MAG"����һ��,��ʱ��ɳ��ʯ,����ֱ�����!!\n"NOR;
        message_combatd(msg, me, target, "");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add("force", -150);
        target->apply_condition("bp_poison",5+random(5) + target->query_condition("bp_poison"));
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                //        else me->kill_ob(target);
                }
        }

        //me->start_busy(1+random(2));
        me->start_busy(1);
        return 1;
}


