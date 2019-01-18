#include <ansi.h>
#include <armor.h>

inherit CLOTH;
//inherit F_GEMS;
#include "gems.c"

void init_sockets(object me)
{
        set("max_sockets", 3);
        if (me->query("combat_exp") > 10000000)
                add("max_sockets", 1);
        if ((int)query("sockets/max")>5)
        set("sockets/max",5);

        if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;

        set("sockets", me->query("diablo/" + TYPE_CLOTH + "/sockets"));
        set_armor_desc();
}

void setup()
{
        init_sockets(this_player());
        ::setup();
}

void spec_prop(object me, string socket, int socket_level, int mode)
{
        if (!valid_gem(socket, socket_level)) return;
        if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;
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
                        message_vision(MAG + query("name") + MAG"ɢ��һƬ��ɫ�ƹ⻷����$N������$P�������Ե�Խ��Խ���ʣ�\n"NOR, me);
                else
                        message_vision(MAG"��ɫԽ��Խ����$N����������¶�˳�����\n"NOR, me);
                me->add_temp("apply/defense", 50 * socket_level * mode);
                break;
        case "diamond":
                if (mode == 1)
                        message_vision(HIW"ֻ��$N���ϵ�" + query("name") + HIW"���澧���������������䣡\n"NOR, me);
                else
                        message_vision(HIW"�����ģ�" + query("name") + HIW"�ƺ��ָֻ���Ѱ����\n"NOR, me);
                me->add_temp("apply/armor", query("armor_prop/armor") * socket_level * mode / 10);
                break;
        case "skull":
                break;
        }
        return;
}

int wear()
{
        int i, sockets, ret;
        object me = environment();

        if (!(ret = ::wear())) return 0;
        sockets = query("sockets/max");
        for (i = 1; i <= sockets; i++)
                spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), 1);

        remove_call_out("check_fight");
        call_out("check_fight", 1, me);

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

        remove_call_out("check_fight");

        return ret;
}

int spec_effect(object ob, object me, int damage, string socket, int socket_level)
{
        int i, def = 0;

        if (!valid_gem(socket, socket_level)) return def;
        if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return 0;
        if (random(100) + me->query_temp("apply/magic") < 70) return def;

        switch (socket) {
        case "ruby":
                break;
        case "topaz":
                break;
        case "sapphire":
                break;
        case "emerald":
                if (!ob->query_condition("emerald_poison")) {
                        message_vision(HIG"$n��У����ã�ֻ��һ������Ѹ�����쵽$p���ֱۣ�\n"NOR, me, ob);
                        ob->apply_condition("emerald_poison", ob->query_condition("emerald_poison") + random(5) + 1);
                        ob->set("emerald_poison", socket_level);
                        if (!ob->is_killing(me->query("id")) && (ob->query("host_id") != me->query("id")))
                                ob->kill_ob(me);
                }
                break;
        case "amethyst":
                break;
        case "diamond":
                message_vision(HIW"$nֻ��$N�����ƺ���һ��������$p�ľ�����ȥ���٣�\n"NOR, me, ob);
                def = -damage * socket_level / 10;
                break;
        case "skull":
                if (objectp(ob->query_temp("weapon")))
                        i = damage * socket_level / 20;
                else
                        i = damage * socket_level / 10;
                if (i > 0) {
                        message_vision(WHT"��Ȼ$N��Χ������ʢ��$nֻ�е���Ѫ��ӿ���޷��Կأ�\n"NOR, me, ob);
                        ob->receive_damage("qi", i);
                        ob->receive_wound("qi", random(i));
                        if (wizardp(me))
                                tell_object(me, sprintf("�����˺����� %d\n", i));
                }
                break;
        }
        return def;
}

int ob_hit(object ob, object me, int damage)
{
        int i, sockets, ret = 0;

        sockets = query("sockets/max");
        for (i = 1; i <= sockets; i++)
                ret += spec_effect(ob, me, damage,
query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)));
        return ret;
}

void spec_recover(object me, string socket, int socket_level)
{
        int i;

        if (!valid_gem(socket, socket_level)) return;
        if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;
        if (random(100) + me->query_temp("apply/magic") < 70) return;

        switch (socket) {
        case "ruby":
                if (me->query("max_qi") > me->query("eff_qi") || me->query("eff_qi") > me->query("qi")) {
                        message_vision(HIR"ֻ��$N���˿ں��������Ѫ����ʱֹס�ˣ����˿��ƺ�Ҳ��ʼ�������ϣ�\n"NOR, me);
                        me->add("eff_qi", 50 * socket_level);
                        if (me->query("eff_qi") > me->query("max_qi"))
                                me->set("eff_qi", me->query("max_qi"));
                        me->add("qi", 100 * socket_level);
                        if (me->query("qi") > me->query("eff_qi"))
                                me->set("qi", me->query("eff_qi"));
                }
                break;
        case "topaz":
                if (me->query("max_jing") > me->query("eff_jing") || me->query("eff_jing") > me->query("jing")) {
                        message_vision(HIY"ֻ��$N��˫�ۿ���֮�������֣������ʱ����\n"NOR, me);
                        me->add("eff_jing", 20 * socket_level);
                        if (me->query("eff_jing") > me->query("max_jing"))
                                me->set("eff_jing", me->query("max_jing"));
                        me->add("jing", 40 * socket_level);
                        if (me->query("jing") > me->query("eff_jing"))
                                me->set("jing", me->query("eff_jing"));
                }
                break;
        case "sapphire":
                if (me->is_busy() && me->is_busy() <= (socket_level + 1) / 2 + 1) {
                        message_vision(HIB"$Nֻ��һ�ɾ�����������������ȫ����������Ѩ�������ĳ������һ���ͨ��\n"NOR, me);
                        me->start_busy(1);
                }
                break;
        case "emerald":
                break;
        case "amethyst":
                break;
        case "diamond":
                break;
        case "skull":
                break;
        }
        return;
}

void check_fight(object me)
{
        int i, sockets;

        if (!me || !query("equipped")) return;
        if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;
        if (living(me) && me->is_fighting()) {
                sockets = query("sockets/max");
                for (i = 1; i <= sockets; i++)
                        spec_recover(me, query(sprintf("sockets/socket%d", i)),
query(sprintf("sockets/socket%d_level", i)));
        }

        call_out("check_fight", 1, me);
}

