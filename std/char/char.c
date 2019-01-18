// char.c
// modify by mudring@Sanjie

#pragma optimize
//#pragma save_binary

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>
#include <combat.h>

inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;

#define SCHEME_CMD      "/cmds/usr/scheme"

// Use a tick with longer period than heart beat to save cpu's work
static int next_beat;

void create()
{
    seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
    seteuid(getuid(this_object()));

    set_heart_beat(1);
    next_beat = time() + 4 + random(11);

    enable_player();
    set_max_items(30);

    CHAR_D->setup_char(this_object());
}

void heart_beat()
{
    int t;
    int period;
    int wimpy_ratio, cnd_flag;
    mapping my;
    object ob, me, room;
    string prompt;

    if (!objectp(room=environment())) return;

    me = this_object();
    my = query_entire_dbase();

    if (userp(me) && living(me) && mapp(my["env"]))
    {
        // update prompt
        prompt = my["env"]["prompt"];
        if ((prompt == "time" || prompt == "mud" || prompt == "hp")
            && is_waiting_command() && !me->is_attach_system())
        {
            write_prompt();
        }
    }

    // Added by mudring
    if (my["force"] < 0) my["force"] = 0;
    if (my["max_force"] < 0) my["max_force"] = 0;
    if (my["mana"] < 0) my["mana"] = 0;
    if (my["max_mana"] < 0) my["max_mana"] = 0;
    if (my["combat_exp"] < 0) my["combat_exp"] = 0;
    if (my["daoxing"] < 0) my["daoxing"] = 0;
    if (my["potential"] - my["learned_points"]< 0) my["potential"] = my["learned_points"];

/*
    if (my["eff_kee"] > my["max_kee"]) my["eff_kee"] = my["max_kee"];
    if (my["kee"] > my["eff_kee"]) my["kee"] = my["eff_kee"];
*/

    // If we are dying because of mortal wounds?
    if (my["eff_kee"] < 0 || my["eff_sen"] < 0)
    {
        QUEST->quest_kill(me);
        remove_all_enemy();
        die();
        if (!me || !living(me))
            return;
    }

    // If we're dying or falling unconcious?
    if (my["kee"] < 0 || my["sen"] < 0) 
    {
        QUEST->quest_kill(me);
        remove_all_enemy();
        if (!living(me)) die();
        else unconcious();
        if (!me || !living(me))
            return;
    }

    // Do attack if we are fighting.
    // mudring Jan/03/2003
    continue_action();
    if (is_busy() || query_temp("no_move"))
    {
        if (query_temp("pending") && is_fighting() && !userp(me))
            me->interrupt_me();
    } else
    {
        // Is it time to flee?
        if (is_fighting() &&
            intp(wimpy_ratio = (int)query("env/wimpy")) &&
            wimpy_ratio > 0 &&
            (my["kee"] * 100 / my["max_kee"] <= wimpy_ratio ||
             my["sen"] * 100 / my["max_sen"] <= wimpy_ratio))
            GO_CMD->do_flee(me);
            // Do attack or clean up enemy if we have fleed.
        else
            attack();
    }

    if (my["doing"] == "scheme")
        // executing schedule now
        SCHEME_CMD->execute_schedule(me);

    if (! me) return;
    // mon add check living. 8/3/98
    if (!userp(me) && living(me))
    {
        me->chat();
        // chat() may do anything -- include destruct(this_object())
        if (!me) return;
    }

    if ((t = time()) < next_beat) return;
    else next_beat = t + 6 + random(9);

    if (!living(me)) return;
    cnd_flag = update_condition();
/*
// comment this by mudring...
    // If we are compeletely in peace, turn off heart beat.
    // heal_up() must be called prior to other two to make sure it is called
    // because the && operator is lazy :P
    if (((cnd_flag & CND_NO_HEAL_UP) || !heal_up()) &&
        !is_fighting() &&
        !interactive(me))
    {
        if (environment())
        {
            ob = first_inventory(environment());
            while (ob && !interactive(ob))
            ob = next_inventory(ob);
        }
        if (!ob) set_heart_beat(0);
    }
*/
    heal_up();
    if (!interactive(me)) return;

    // Make us a bit older. Only player's update_age is defined.
    // Note: update_age() is no need to be called every heart_beat, it
    //       remember how much time has passed since last call.
    me->update_age();

    if (living(me))
    {
        period = t - ((int) my["last_save"]);
        if (period < 0 || period > 15 * 60)
        {
            string msg;
            msg = HIG "�������洢�����ĵ����Ѿ��Զ����̡�\n" NOR;;
            if (! me->save())
                msg = HIR "�����ݱ��������������쳣�����ĵ�"
                      "�����δ���ʧ�ܡ�\n" NOR;
            set("last_save", t);
            tell_object(me, msg);
        }
    }

    if (query_idle(me) > IDLE_TIMEOUT)
        me->user_dump(DUMP_IDLE);
}

// added by snowcat 6/27/1997
int command_function (string arg)
{
    command (arg);
    return 1;
}

// this function is extensively referenced, for example from id(),
// present(), ... so must be fast.
int visible(object ob)
{
    int lvl, invis;

    invis = ob->query("env/invisibility");

    if (ob->query("env/invv") && wizardp(ob) 
     && (getuid(this_object()) != "stey" 
     || getuid(this_object()) != "mudring"
       || getuid(this_object()) != "seng"
             || getuid(this_object()) != "longer")) return 0;
    if (wizardp(this_object())) return 1;

    if (!invis) invis = ob->query_temp("invisiblity");

    if (invis)
    {
        if (wizardp(ob)) return 0;
        if (!userp(ob)) return 0;
        if (query("env/invisibility")) return 1;
        return 0;
    }

    if (ob->is_ghost())
    {
        if (is_ghost()) return 1;
        if (query_temp("apply/astral_vision")) return 1;
        return 0;
    }
    return 1;
}

int command( string str )
{
    reset_eval_cost();
    return command_function(str);
}

