// move.c
// optimize by mudring
// Dec/01/2002

#pragma optimize
//#pragma save_binary

#include <ansi.h>
#include <dbase.h>
#include <room.h>

static int weight = 0;
static int encumb = 0, max_encumb = 0;

varargs int _move(mixed dest, int silently);
void dest_obj(object obj);

static int max_items=10;
nomask void set_max_items(int e) {max_items = e;}
nomask int query_max_items() {return max_items;}

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }

nomask void add_encumbrance(int w)
{
    object env;

    encumb += w;
    if (encumb < 0)
    {
        log_file("move.bug", encumb < 0 ? sprintf("%O encumbrance underflow.\n", this_object())
                                        : sprintf("%O encumbrance overflow.\n", this_object()));
        if (this_player())
        {
            log_file("move.bug",
                     sprintf("User: %s\nMe = %O\nEnvironment %O\nCommand: %s\n\n",
                             log_id(this_player()),
                             log_id(this_object()),
                             environment(this_player()),
                             this_player()->query_last_input()));
        }
    }

    if (encumb > max_encumb) this_object()->over_encumbrance();
    if (env = environment()) env->add_encumbrance(w);
}

void over_encumbrance()
{
    if (!userp(this_object())) return;
    tell_object(this_object(), "��ĸ��ɹ����ˣ�\n");
}

nomask int query_weight() { return weight; }
nomask void set_weight(int w)
{
    if (!environment())
    {
        weight = w;
        return;
    }
    if (w != weight)
        environment()->add_encumbrance(w - weight);
    weight = w;
}

// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

string ride_suffix (object me)
{
    string ridemsg = 0;
    object ridee = 0;

    ridee = me->ride();
    if (ridee)
        ridemsg = ridee->query("ride/msg") + "��" + ridee->name() + "��";
    return ridemsg;
}

// silently=1: after move, no look.
// silently=2: when look, only show room name. (for follow command)
// silently=0: full look.
// mon 4/20/98
varargs int move(mixed dest, int silently)
{
    if(_move(dest, silently)) return 1;

    call_out("dest_obj", 2, this_object());
    return 0;
}

// destruct obj if it failed to move and has no environment.
void dest_obj(object obj)
{
    if (obj && !environment(obj))
        destruct(obj);
}


varargs int _move(mixed dest, int silently)
{
    object ob, env, *inv, me;
    int i;
    mapping exits;
    string str="", str1="", *dirs;
    string ridemsg="";

    me = this_object();

    // If we are equipped, unequip first.
    if (query("equipped") && !me->unequip())
        return notify_fail("��û�а취ȡ������������\n");

    // Find the destination ob for moving.
    if (dest && objectp(dest))
        ob = dest;
    else if (stringp(dest))
    {
        ob = load_object(dest);
        if (!ob)
            return notify_fail("move: destination unavailable.\n");
    } else
        return notify_fail(sprintf("move: invalid destination %O.\n", dest));

    // check for max_items.
    if (!(me->is_character())
        && sizeof(all_inventory(ob)) >= ob->query_max_items())
    {
        if (ob == this_player())
            return notify_fail("������װ���¸��ණ���ˡ�\n");
        else if(userp(ob))
            return notify_fail(ob->name() + "����װ���¸��ණ���ˡ�\n");
        else
        {
            string name=ob->name();
            if (!name) name=ob->query("short");
            if (!name) name=ob->short();
                return notify_fail(name+"�Ѿ�̫ӵ���ˡ�\n");
        }
    }

    // recursive check can't move sth into itself's belonging's
    // mon 9/1/98
    env = ob;
    if (env == me) //mon 8/25/97
        return notify_fail("�㲻�ܰ���Ʒ��������֮�С�\n");
    while (env = environment(env))
    {
        if (env == me)
            return notify_fail("�㲻�ܰ���Ʒ��������֮�С�\n");
    }

    // Check if the destination ob can hold this object.
    // Beforce checking it, we check if the destination is environment of
    // this_object() (or environment of its environment). If it is, then
    // this could be like get something from a bag carried by the player.
    // Since the player can carry the bag, we assume he can carry the this
    // object in the bag and encumbrance checking is unessessary.

    env = me;
    while (env = environment(env))
        if( env==ob ) break;

    if (!env && (int)ob->query_encumbrance() + weight()
        > (int)ob->query_max_encumbrance())
    {
        if (ob == this_player())
            return notify_fail( this_object()->name() +
               "�������̫���ˡ�\n");
        else
            return notify_fail( this_object()->name() +
               "��" + ob->name() + "����̫���ˡ�\n");
    }

    env = environment();
    if (env)
    {
        env->add_encumbrance(-weight());
        if (userp(env)
            && me->value() >= 10000)
           env->save();
    }
    ob->add_encumbrance(weight());

/*
    if (me->query("clone_by_wizard"))
    {
        me->set_temp("wiz_give", me->query("clone_by_wizard"));
        me->set_temp("wiz_time", ctime(time()));
    }
*/

    if (env)
    {
        if (wizardp(env) && !userp(me))
        {
            me->set_temp("wiz_give", env->name(1) + "-" + getuid(env));
            me->set_temp("wiz_time", ctime(time()));
        }
    }

    if (me->query_temp("wiz_give") && playerp(ob) && !wizardp(ob))
    {
        object env_ob;
        string p_ob = "ĳ", wiz_msg;

        env_ob = environment(ob);
        if (env_ob)
            p_ob = (env_ob->short() ? env_ob->short()
                                    : env_ob->query("short")) + "[" + file_name(env_ob) + "]";
            wiz_msg = "��(" + p_ob + ")�õ���" + me->query_temp("wiz_give")
                + "������" + me->name(1) + file_name(me);
            MONITOR_D->report_system_object_msg(ob, wiz_msg);
            log_file("static/wiz_give", sprintf("%s %s %s\n",
                     log_id(ob), wiz_msg, log_time()));
    }

    if (userp(ob) && me->value() >= 1000000)
    {
        object env2;
        string place_me = "ĳ";
        string place_ob = "ĳ";

        if (env)
            place_me = (env->short() ? env->short()
                                     : env->query("short")) + "[" + file_name(env) + "]";
        env2 = environment(ob);
        if (env2)
            place_ob = (env2->short() ? env2->short()
                                      : env2->query("short")) + "[" + file_name(env2) + "]";
        if (env != ob)
           MONITOR_D->report_system_object_msg (ob, "����" + place_ob + "����" + place_me
               + "���õ��˼�ֵΪ" + MONEY_D->price_str(me->value()));
    }

    move_object(ob);
    if (!me) return 0;

    if (interactive(me)
        && living(me)
        && silently != 1 )
    {
        if (me->query("env/brief_all")
            || me->query("env/brief")
            || env->query("no_look"))
        {
            if (silently == 2
                || me->query("env/brief_all"))
                    tell_object(me, env->query("short") ? env->query("short") + "\n" : "\n");
            else
            if (env->query("no_look")
                && mapp(exits = env->query("exits")))
            {
                str = sprintf( "%s - %s\n    %s%s",
                   env->query("short") ? env->query("short") : "",
                   wizardp(me) ? file_name(env): "",
                    ((!me->query("env/brief"))
                      && (env->query("long"))) ? env->query("long"): "",
                    ((!me->query("env/brief"))
                      && (env->query("outdoors"))) ? NATURE_D->outdoor_room_description(): "");
            }
            else if (me->query("env/brief"))
            {
                str = sprintf( "%s\n",
                env->query("short") ? env->query("short"): "",
                file_name(env));
                if (mapp(exits = env->query("exits")))
                {
                    dirs = keys(exits);
                    for (i=0; i < sizeof(dirs); i++)
                    if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED)
                        dirs[i] = 0;
                    dirs -= ({ 0 });
                    if (sizeof(dirs) == 0)
                        str += "  ����û���κ����Եĳ�·��\n";
                     else if(sizeof(dirs) == 1)
                        str += "  ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
                     else
                        str += sprintf("  �������Եĳ����� " + BOLD + "%s" + NOR
                            + " �� " + BOLD + "%s" + NOR + "��\n",
                     implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
                }
            }

            inv = all_inventory(env);
            i = sizeof(inv);
            if (env->query("no_look"))
               i = 0;
            while (i--)
            {
                if (!me->visible(inv[i])) continue;
                if (inv[i] == me) continue;
                if (ridemsg = ride_suffix(inv[i]))
                    str1 = "  " + inv[i]->short() + " <" + ridemsg + ">\n" + str1;
                else
                    str1 = "  " + inv[i]->short() + "\n" + str1;
            }
            tell_object(me, str + str1);
        }
        else command("look");
    }

    me->ride();

    if ((me->query("is_monitored")
          || file_name(me)[0..2]=="/u/")
        && userp(ob))
        MONITOR_D->report_system_object_msg (ob,
            "�õ���" + me->query("name") + "("+file_name(me) + ")��");

    // mudring Dec/05/2002
    if (me->query("clone_by_wizard")
        && userp(ob))
    {
        MONITOR_D->report_system_object_msg (ob,
            "�õ���" + me->query("clone_by_wizard") + "���Ƶ�" + me->query("name") + "("+file_name(me) + ")��");
        log_file("static/wiz_clone", sprintf("%s �õ��� %s ���Ƶ� %s %s\n",
            log_id(ob), me->query("clone_by_wizard"), file_name(me), log_time()));
    }

    if (!silently && query("treasure") && userp(ob))
    {
        if (query("treasure") > 0)
        {
            str = "Ū����һ" + query("unit") + query("name");
            set("treasure", -1);
        }
        else
        {
            add("treasure", 1);
            if (env->query("short"))
                str = "��" + env->query("short")
                    + "����һ" + query("unit") + query("name");
            else
                str = "��" + env->name(1)
                    + "���õ���һ" + query("unit") + query("name");
        }
        MONITOR_D->report_rumor_object_msg(ob, str + "��");
    }

    return 1;
}
void remove(string euid)
{
    object me;
    object ob;
    object default_ob;

    if (!previous_object()
        || base_name(previous_object()) != SIMUL_EFUN_OB)
            error("move: remove() can only be called by destruct() simul efun.\n");

    me = this_object();
    if (userp(me) && euid != ROOT_UID)
    {
        if (euid != getuid(me))
        {
            log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
                     euid, me->query("id"),
                     ctime(time())));
            error("��(" + euid + ")���ܴݻ�������ʹ���ߡ�\n");
        }
        log_file("destruct", sprintf("%s in %O destruct on %s.\n",
                 me->query("id"),
                 environment(me),
                 ctime(time())));
        error("ֻ��ROOT���ܴݻ���ҡ�\n");
    } else
    if (me->query("equipped"))
    {
       if (!me->unequip())
           log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",
                                        file_name(me)));
    }

    if (objectp(ob = environment()))
        ob->add_encumbrance(- weight);

    if (default_ob = me->query_default_object())
        default_ob->add("no_clean_up", -1);

    me->end_log();
}

int move_or_destruct( object dest )
{
    if (userp(this_object()))
    {
        tell_object(this_object(), "һ��ʱ�յ�Ť�����㴫�͵���һ���ط�������\n");
        move(VOID_OB);
    }
}

object ride ()
{
    object me = this_object();
    string ridemsg = "";
    object ridee;

    if (ridee = me->query_temp("ridee"))
    {
        if ((environment(ridee) != environment(me)
              && environment(ridee) != me)
            || (ridee->is_character()
              && !living(ridee)))
        {
            me->set_temp("ridee",0);
            ridee->set_temp("rider",0);
            ridee = 0;
        }
    }

    if (!ridee)
    {
        me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
        me->set_temp("ride/dodge",0);
    }

    return ridee;
}

