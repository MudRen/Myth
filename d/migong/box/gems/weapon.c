#include <ansi.h>
#include <weapon.h>

inherit M_WEAPON;
//inherit F_GEMS;
#include "gems.c"

void init_sockets(object me)
{
        set("max_sockets", 3);
        if (me->query("combat_exp") > 10000000)
                add("max_sockets", 1);
        if ((int)query("sockets/max")>5)
        set("sockets/max",5);

        if (me->query("diablo/weapon/id") != query("id")) return;

        set("sockets", me->query("diablo/weapon/sockets"));
        set_weapon_desc();
}

void setup()
{
        init_sockets(this_player());
        ::setup();
}

void spec_prop(object me, string socket, int socket_level, int mode)
{
        if (!valid_gem(socket, socket_level)) return;
        if (me->query("diablo/weapon/id") != query("id")) return;
        switch (socket) {
        case "ruby":
                break;
        case "topaz":
                break;
        case "sapphire":
                break;
        case "emerald":
                break;
        case "amethyst":
                if (mode == 1)
                        message_vision(MAG + query("name") + MAG"������͵Ĺ�âΧ����$N��������$P��ս������\n"NOR, me);
                else
                        message_vision(MAG"������ɫ��â������ɢȥ��$N��ս�����ָ�ԭ�ˡ�\n"NOR, me);
                me->add_temp("apply/attack", 50 * socket_level * mode);
                break;
        case "diamond":
                if (mode == 1)
                        message_vision(HIW"ֻ��һ���׹�ֱ͸" + query("name") + HIW"��������Ȼ������\n"NOR, me);
                else
                        message_vision(HIW"�׹⽥��������" + query("name") + HIW"��\n"NOR, me);
                me->add_temp("apply/damage", query("weapon_prop/damage") * socket_level * mode / 10);
                break;
        case "skull":
                break;
        }
        return;
}

int wield()
{
        int i, sockets, ret;
        object me = environment();

        if (!(ret = ::wield())) return 0;
        sockets = query("sockets/max");
        for (i = 1; i <= sockets; i++)
                spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), 1);
        return ret;
}

int unequip()
{
        int i, sockets, ret;
        object me = environment();

        if (!(ret = ::unequip())) return 0;
        sockets = query("sockets/max");
        for (i = 1; i <= sockets; i++)
                spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), -1);
        return ret;
}

string spec_effect(object me, object victim, int damage_bonus, string socket, int socket_level)
{
        int damage;
        string msg = "";
        object weapon;

        if (!valid_gem(socket, socket_level)) return msg;
        if (random(100) + me->query_temp("apply/magic") < 70) return msg;
        if (me->query("diablo/weapon/id") != query("id")) return msg;
        switch (socket) {
        case "ruby":
                msg = HIR"һ������͵Ļ�����$n��$pֻ���û���һ���ʹ��\n"NOR;
                damage = damage_bonus * socket_level / 5;
if ((int)victim->query("qi")+100 > damage)
                victim->receive_wound("qi", damage);
                if (wizardp(me))
                        tell_object(me, sprintf("��Ѫ���ˣ�%d\n", damage));
                break;
        case "topaz":
                msg = HIY"һ���ƹ��͵Ļ�����$n��$pֻ������˼Խ��Խģ����\n"NOR;
                damage = damage_bonus * socket_level / 15;
                if (damage > 300 * socket_level / 5)
                        damage = 300 * socket_level / 5;
if ((int)victim->query("jing")+100 > damage)
{
                victim->receive_damage("jing", damage);
                victim->receive_wound("jing", random(damage));
}
                if (wizardp(me))
                        tell_object(me, sprintf("jing damage is: %d\n", damage));
                break;
        case "sapphire":
                if (!victim->is_busy())
                        msg = HIB"һ������������Χ��$n��$pֻ��������ת�������޷�������\n"NOR;
                        victim->start_busy(random(socket_level) + 1);
                break;
        case "emerald":
                if (!victim->query_condition("emerald_poison")) {
                        msg = HIG"$nֻ��һ������Ѹ�ٵĴ��˿�������$p�ľ�����\n"NOR;
                        victim->apply_condition("emerald_poison", victim->query_condition("emerald_poison") + random(5) + 1);
                        victim->set("emerald_poison", socket_level);
                        if (!victim->is_killing(me->query("id")) && (victim->query("host_id") != me->query("id")))
                                victim->kill_ob(me);
                }
                break;
        case "amethyst":
                break;
        case "diamond":
                if (objectp(weapon = victim->query_temp("weapon"))) {
                        if (random(query("weapon_prop/damage")) > weapon->query("weapon_prop/damage") / 2
                        && random(me->query("str")) > victim->query("str") / 2) {
                                if (query("skill_type") == "sword" || query("skill_type") == "blade" || query("skill_type") == "axe") {
                                        message_vision(HIW"ֻ�������ѡ���һ�����죬$N���е�" + weapon->query("name") + HIW"�Ѿ���" + query("name") + HIW"��Ϊ���أ�\n"NOR, victim);
                                        weapon->unequip();
                                        weapon->move(environment(victim));
                                        weapon->set("name", "�ϵ���" + weapon->query("name"));
                                        weapon->set("value", 0);
                                        weapon->set("weapon_prop", 0);
                                        victim->reset_action();
                                };
                                if (query("skill_type") == "staff" || query("skill_type") == "hammer" || query("skill_type") == "club") {
                                        message_vision(HIW "$Nֻ��������" + weapon->query("name") + HIW"�ѳֲ��������ַɳ���\n" NOR, victim);
                                        weapon->unequip();
                                        weapon->move(environment(victim));
                                        victim->reset_action();
                                };
                                if (query("skill_type") == "whip") {
                                        message_vision(HIW"ֻ������ৡ���һ�����죬$N���е�" + weapon->query("name") + HIW"�Ѿ���" + query("name") + HIW"��Ϊ���أ�\n"NOR, victim );
                                        weapon->unequip();
                                        weapon->move(environment(victim));
                                        weapon->set("name", "�ϵ���" + weapon->query("name"));
                                        weapon->set("value", 0);
                                        weapon->set("weapon_prop", 0);
                                        victim->reset_action();
                                };
                        }
                }
                break;
        case "skull":
                msg = WHT"��Ȼ�䣬$nֻ������Ǻ��������ڶ����������Ƕ������˳�ȥ��\n"NOR;
                damage = damage_bonus * socket_level / 10;
                if (victim->query("qi") < damage)
                        damage = victim->query("qi");
                if (damage > 0) {
if ((int)victim->query("qi")+100 > damage)
{
                        victim->receive_damage("qi", damage);
                        me->add("qi", damage/2);
}
                        if (me->query("qi") > me->query("eff_qi"))
                                me->set("qi", me->query("eff_qi"));
                        if (wizardp(me))
                                tell_object(me, sprintf("suck qi: %d\n", damage));
                }
                damage = damage_bonus * socket_level / 20;
                if (victim->query("neili") < damage)
                        damage = victim->query("neili");
                if (damage >  0) {
if ((int)victim->query("neili")+100 > damage)
{
                        victim->add("neili", -damage);
                        me->add("neili", damage/2);
}
                        if (me->query("neili") > me->query("max_neili") * 2)
                                me->set("neili", me->query("max_neili") * 2);
                        if (wizardp(me))
                                tell_object(me, sprintf("suck neili: %d\n", damage));
                }
                break;
        }
        return msg;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int i, sockets;
        string msg = "";

        sockets = query("sockets/max");
        for (i = 1; i <= sockets; i++)
                msg += spec_effect(me, victim, damage_bonus,
query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)));
        return msg;
}

