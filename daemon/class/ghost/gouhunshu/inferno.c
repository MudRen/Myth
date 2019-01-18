//Cracked by Roath

#include <ansi.h>

inherit SSERVER;
int check_damage(object me, object target, int time);
int generate_msg(object me);

int cast(object me, object target)
{
        int time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��������ȥ��˭��\n");

        if((int)me->query_skill("gouhunshu") < 30 )
                return notify_fail("��Ĺ������ȼ���������\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ��������ˣ�\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("������ľ����㣡\n");

        if( (int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㡣\n");

        if( random(me->query("max_mana")) < 50 ) {
                write("��κ��󲻴��顣\n");
                return 1;
        }

        time = 2 + (int)me->query_skill("gouhunshu",1) / 50;
        if ( time > 5 ) time=5;

        message_vision(HIB"$N˫��һ�꣬��ʱȼ��һ����ɫ�Ļ��棬����׹�Ʈ����$n��\n"NOR, me, target);

        check_damage(me, target, time);

        return 3+random(5);

}

int check_damage(object me, object target, int time)
{
        int ap,dp,damage,success;

        if( !target
        || !me 
        || environment(me) != environment(target)) {
                remove_call_out("check_damage");
                return 1;
        }

        ap= (int)me->query_skill("spells");
        ap= ap*ap*ap/10;
        ap= ap+(int)me->query("daoxing");

        dp= (int)target->query_skill("spells");
        dp= dp*dp*dp/10;
        dp= dp+(int)target->query("daoxing");

        damage=(int)me->query("max_mana")/10 - random((int)target->query("max_mana")/10);
        damage+=(int)me->query("mana_factor");
        success=1;

        if( damage < 0 ) success = 0;
        if( random(ap+dp) < dp ) success = 0;
        if( (int)me->query("mana") < 30 ) success = 0;
        if( (int)me->query("kee")  < 30 ) success = 0;
        if( environment(me)->query("no_fight")
        || environment(me)->query("no_magic") ) success = 0;

        if( success )
        {

                message_vision(HIB"\n��ž����һ����ɫ������$N����ȼ������Ȳ�����$N£�����롣\n"NOR, target);
                target->receive_damage("kee", random(damage), me, "cast");
                target->receive_wound("kee", damage/3, me, "cast");
                COMBAT_D->report_status(target);
                me->receive_damage("kee", 25);
                me->add("mana", -25);
                me->start_busy(2);
        } else {
                tell_room(environment(target), "\n���ܵ���׻�Ʈ���š�����\n");
        }

        time--;

        if( time ) {
                call_out("generate_msg", 4, me);
                call_out("check_damage", 8, me, target, time);
        }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
// modified by tree,2001-7-24
                        if( !environment(me)->query("no_fight") && !environment(me)->query("no_magic") )
                        {
                                if( userp(target) ) target->fight_ob(me);
                                else target->kill_ob(me);
                        }
                }
                me->kill_ob(target);
        }


        return 1;
}

int generate_msg(object me)
{
        string *msgs=({
                "\n��ž����һ����ɫ����������\n",
                "\n����׻��ڿ�����Ʈ���š�����\n",
                "\nһ����ɫ����ӵ���ð�˳�����\n",
                "\n����ž��ž���ر�ȼ�š�����\n",
        });
        if( !me ) return 1;
        tell_room( environment(me), msgs[random(sizeof(msgs))]);
}

