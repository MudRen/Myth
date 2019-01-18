// jobnpc.c
// mudring Dec/15/2002

#include <command.h>

#define MAX_OPPENENT 4

inherit CHARACTER;
inherit F_CLEAN_UP;

void check_room();

int open_heart_beat()
{
    if (!clonep(this_object()))
        return 0;

    return 1;
}

object carry_object(string file)
{
    object ob;

    file = resolve_path(0, file);
    ob = new(file);
    if (ob) ob->move(this_object());
    return ob;
}

object add_money(string type, int amount)
{
    object ob;

    if (!clonep()) return 0;
    ob = carry_object("/obj/money/" + type);
    if (!objectp(ob)) return 0;
    ob->set_amount(amount);
    return ob;
}

int accept_fight(object who)
{
    if (is_fighting())
    {
        command("say ���ж�Ϊʤ���ⲻ������̫����\n");
    } else
    {
        command("say �Һ�æ��ûʱ�����Ϲ����\n");
    }
    return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
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

    if (!is_fighting() && !is_busy())
        check_room();

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
int random_move()
{
    if (this_object())
        return NPC_D->random_move(this_object());
    return 0;
}

// room cant use to job
void check_room()
{
    object me = this_object();
    object env = environment(me);

    if (!living(me)) return;

    if (env && (env->query("no_fight") ||
                env->query("no_magic") ||
                env->query("no_mieyao") ||
                env->query("alternative_die")))
    {
        random_move();
    }
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

varargs void die(object killer, int flag)
{
    if (!flag) flag = 1;
    ::die(killer, flag);
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

