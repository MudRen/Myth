// npc.c
// modify by mudring@Sanjie

#include <command.h>

#define MAX_OPPENENT 4

inherit CHARACTER;
inherit F_CLEAN_UP;

nosave int keep_heart_beat = 0;

int open_heart_beat()
{
    mapping my;

    if (!clonep(this_object()))
        return 0;

    if (keep_heart_beat)
        return 1;

    if (is_fighting() || query_condition())
        return 1;

    my = query_entire_dbase();
    
    if (my["chat_chance"] || my["owner"])
    {
        keep_heart_beat = 1;
        return 1;
    }

    if ((my["kee"] < my["max_kee"])
    || (my["eff_kee"] < my["max_kee"]))
        return 1;
       
    if ((my["sen"] < my["max_sen"])
    || (my["eff_sen"] < my["max_sen"]))
        return 1;
    
    if ((my["force"] < my["max_force"])
    || (my["mana"] < my["max_mana"]))
        return 1;
    
    return 0;
}

object carry_object(string file)
{
    object ob;

/*
    // mudring Dec/05/2002
    if (!clonep()) return 0;
*/
    file = resolve_path(0, file);
    // mudring Dec/01/2002
    ob = unew(file);
    // mudring Dec/04/2002
    if (!ob && file->query("replace_file"))
        ob = new(file->query("replace_file"));
    if (!objectp(ob)) return 0;
    ob->move(this_object());
    return ob;
}

object add_money(string type, int amount)
{
    object ob;

    if (!clonep()) return 0;
    ob = carry_object("/obj/money/" + type);
    // mudring Dec/01/2002
    if (!objectp(ob)) return 0;
    ob->set_amount(amount);
    return ob;
}

int accept_fight(object who)
{
    string att;

    att = query("attitude");

    if (is_fighting())
    {
        switch(att)
        {
            case "heroism":
                command("say �ߣ����аɣ�\n");
                break;
            default:
                command("say ���ж�Ϊʤ���ⲻ������̫����\n");
                return 0;
        }
    }

    // mudring Dec/01/2002
    if ((int)query("kee") * 100 / (int)query("max_kee") >= 90
        && (int)query("sen") * 100 / (int)query("max_sen") >= 90)
    {
        switch(att)
        {
            case "friendly":
                command("say " + RANK_D->query_self(this_object())
                         + "��ô������" + RANK_D->query_respect(who)
                         + "�Ķ��֣�\n");
                return 0;
            case "aggressive":
            case "killer":
                command("say �ߣ����аɣ�\n");
                break;
            default:
                if (!is_fighting())
                    command("say ��Ȼ" + RANK_D->query_respect(who)
                            + "�ͽ̣�" + RANK_D->query_self(this_object())
                            + "ֻ�÷��㡣\n");
        }
        return 1;
    }
    else
        return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
    object *enemy_list;
    int i, flag = 0;
    object me = this_object();

    // Are we at home already?
    if (!environment()
        || environment() == home)
        return 1;

    // Are we able to leave?
    if (!living(me)
        || me->query_temp("no_return"))
        return 0;

    if (is_fighting())
    {
       enemy_list = query_enemy();
       for (i = 0; i < sizeof(enemy_list); ++i)
       {
           if (!enemy_list[i]) continue;
           if (sizeof(enemy_list[i]->query_enemy()) > MAX_OPPENENT)
           {
               message("vision", "\n"+this_object()->name() +
                       "�������һԾ�����ֵ����������ղ������������������Ǻ�����ڣ�\n\n",
                       environment(), me);
               enemy_list[i]->remove_killer(me);
               remove_enemy( enemy_list[i] );
               flag = 1;
               break;
           }
       }
       if (!flag)
           return 0;
    }

    // Leave for home now.
    message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
            environment(), me);

    // mudring Dec/01/2002
    if (move(home))
    {
        message("vision", this_object()->name() + "����ææ�����˹�����\n",
                environment(), me);
        return 1;
    }

    return 0;
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
    string *msg;
    int chance, rnd;

    if (!environment()) return 0;

    // mudring Jan/03/2003
    if (is_busy() || query_temp("no_move")) return 0;

    // mudring Dec/01/2002
    if (query("force") > 100 && query("race") == "����"
        && query("kind") != "��")
    {
        if (query("eff_kee")
            && query("kee") >= 0
            && query("kee") * 100 / query("eff_kee") <= 80)
            command("exert recover");

        if (query("eff_sen")
            && query("sen") >= 0
            && query("sen") * 100 / query("eff_sen") <= 80)
            command("exert refresh");

        if (query("eff_kee")
            && query("kee") >= 0
            && query("max_kee")
            && !is_fighting()
            && query("eff_kee") < query("max_kee")
            && query("eff_kee") >= query("max_kee") / 2)
            command("exert heal");
    }

    if (!chance = (int)query(is_fighting() ? "chat_chance_combat"
                                           : "chat_chance"))
        return 0;

    if (arrayp(msg = query(is_fighting() ? "chat_msg_combat"
                                         : "chat_msg")))
    {
        if (random(100) < chance)
        {
            rnd = random(sizeof(msg));
            if (stringp(msg[rnd]))
                say(msg[rnd]);
            else if (functionp(msg[rnd]))
                return evaluate(msg[rnd]);
        }
        return 1;
    }
}

// Default chat function: Let the npc random move to another room.
// mudring Dec/01/2002
int random_move()
{
    mapping exits;
    string *dirs, dir, last_room;
    object me = this_object();
    object env = environment(me);

    if (strsrch(base_name(env), "/d") != 0)
    {
        message("vision", me->name() + "����ææ���뿪�ˡ�\n", env, me);
        me->move(me->query("start_room"));
        message("vision", me->name() + "���˹�����\n",
                env, me);
    }

    if (!objectp(env)
        || me->is_fighting() || me->is_busy()
        || !mapp(exits = env->query("exits"))) return 0;

    dirs = keys(exits);

    if (sizeof(dirs) < 1) return 0;

    dir = dirs[random(sizeof(dirs))];
    if (stringp(last_room = me->query_temp("last_room"))
        && sizeof(dirs) > 1 && exits[dir] == last_room )
    {
        dirs -= ({dir});
        dir = dirs[random(sizeof(dirs))];
    }

    command("go " + dir);
    me->set_temp("last_room", env);

    return 1;
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
    string spell_skill;

    if (stringp(spell_skill = query_skill_mapped("spells")))
        SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
    string force_skill;

    if (stringp(force_skill = query_skill_mapped("force")))
        SKILL_D(force_skill)->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with
// his/her enabled martial art
int perform_action(string skill, string action)
{
    object weapon=this_object()->query_temp("weapon");
    string weapon_skill,martial_skill;

    if (!weapon) weapon_skill="unarmed";
    else
    {
        if (weapon->query("use_apply_skill"))
            weapon_skill = weapon->query("apply/skill_type");
        else weapon_skill = weapon->query("skill_type");
    }

    martial_skill = query_skill_mapped(skill);

    if (stringp(martial_skill) && skill == weapon_skill)
        return SKILL_D(martial_skill)->perform_action(this_object(), action);
}

// when remove
void remove()
{
    function *fun;

    if (functionp(fun = query_temp("override/destruct", 1)))
        catch(evaluate(fun, this_object()));

    ::remove();
}

// environment destruct
void move_or_destruct()
{
    remove();
}

