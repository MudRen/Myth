// npcd.c
// by mudring
#pragma optimize
#pragma save_binary
#include <command.h>

string *place = ({ // all qujing dir 37
    "/d/qujing/baotou",
    "/d/qujing/baoxiang",
    "/d/qujing/biqiu",
    "/d/qujing/chechi",
    "/d/qujing/dudi",
    "/d/qujing/fengxian",
    "/d/qujing/firemount",
    "/d/qujing/jilei",
    "/d/qujing/jindou",
    "/d/qujing/jinping",
    "/d/qujing/jisaiguo",
    "/d/qujing/maoying",
    "/d/qujing/nuerguo",
    "/d/qujing/pingding",
    "/d/qujing/pansi",
    "/d/qujing/tongtian",
    "/d/qujing/qilin",
    "/d/qujing/qinfa",
    "/d/qujing/qinglong",
    "/d/qujing/tianzhu",
    "/d/qujing/wudidong",
    "/d/qujing/wuji",
    "/d/qujing/xiaoxitian",
    "/d/qujing/yinwu",
    "/d/qujing/yuhua",
    "/d/qujing/zhujie",
    "/d/qujing/zhuzi",
});

void create() { seteuid(getuid());}

// select a random place
// mudring Nov/28/2002
string get_place(string dirs)
{
    int i;
    int j;
    object  pp;
    string p;
    mixed*  file, exit;

    file = get_dir(dirs + "/*.c", -1);

    i = sizeof(file);
    if (!i) return 0;
    for (j = 0; j < 30; j++)
    {
        p = dirs + "/" + file[random(i)][0];
        if (!objectp(pp = get_object(p)))
        {
            log_file("log", sprintf("error to place npc to %s\n", p));
            continue;
        }
        if (!pp->query("outdoors")
            || pp->query("no_fight")
            || pp->query("no_magic")
            || pp->query("no_mieyao")
            || pp->query("alternative_die")
            || !(exit = pp->query("exits"))
            || sizeof(exit) < 1)
        {
            continue;
        }
        break;
    }

    return p;
}

// place npc
// mudring Sep/09/2002
varargs void place_npc(object ob, string *in_place, string *not_place)
{
    string *kp;
    string p;
    string startroom;
    object pos;

    reset_eval_cost();

    // select the place
    if (!arrayp(in_place))
        kp = place;
    else
        kp = in_place;

    // exclude some place
    if (arrayp(not_place))
        kp -= not_place;

/*
    p = kp[random(sizeof(kp))];
    startroom = get_place(p);
*/
    while (!startroom)
    {
        p = kp[random(sizeof(kp))];
        startroom = get_place(p);
    }
    pos = get_object(startroom);

    // move to the position
    ob->move(pos);
    ob->set("place", MISC_D->find_place(pos));
// jobnpc no need startroom.
//112      ob->set("startroom", startroom);
    ob->set("where", startroom);
    ob->set_temp("moved", ({ }));
    message_vision("$N���˹�����\n", ob);
}

#define MAX_MOVED       5
// random move
// because job npc must not go no_fight room
// so use this function for job npc random move
// mudring Aug/15/2002
void random_move(object ob)
{
    mapping exits;
    string *moved;
    string dir;
    string *dirs;
//133      string *locl, *locl2;
    int i;
    object env = environment(ob);

    moved = ob->query_temp("moved");
    if (!moved) moved = ({ });
    if (sizeof(moved) >= MAX_MOVED)
    {
        // out of range, move back
        dir = GO_CMD->query_reverse(moved[sizeof(moved) - 1]);
    }
    else
    {
        if (!objectp(env) ||
            ob->is_fighting() || ob->is_busy() ||
            !mapp(exits = env->query("exits")) || !sizeof(exits))
            return 0;

        dirs = keys(exits);

        for (i = 0; i < 12; i++)
        {
             if (!sizeof(dirs))
                  return;
             dir = dirs[random(sizeof(dirs))];
/*
             locl = explode(exits[dir], "/");
             locl2 = explode(file_name(env), "/");
*/

             if (stringp(GO_CMD->query_reverse(dir)) &&
//166                   locl[sizeof(locl) - 2] == locl2[sizeof(locl2) - 2] &&
                 !exits[dir] &&
                 !exits[dir]->query("no_fight") &&
                 !exits[dir]->query("no_magic") &&
                 !exits[dir]->query("no_mieyao") &&
                 !exits[dir]->query("alternative_die"))
            {
                 break;
            }
            dirs -= ({ dir });
        }
    }

    if (sizeof(moved)
        && GO_CMD->query_reverse(dir) == moved[sizeof(moved) - 1])
    {
        // move back
        moved = moved[0..<2];
    } else
        moved += ({ dir });
    ob->set_temp("moved", moved);

    GO_CMD->main(ob, dir);
}

// for select task place
// mudring Dec/12/2002
object task_place(string dir)
{
    string startroom;
    object pos;

    startroom = get_place(dir);
    pos = get_object(startroom);
    pos->set("place", MISC_D->find_place(pos));

    return pos;
}

// select a npc for job
// mudring Dec/12/2002
object task_npc()
{
    int i, j;
    object room;
    object task, *living;

    reset_eval_cost();

    living = livings(); 
    living -= users();

    for (i = 0;i < sizeof(living); i++)
    {
        j = random(sizeof(living));

        if (j <= 1 || j == sizeof(living) - 1) continue;
        task = living[j];
         
        if (!objectp(task)
            || userp(task)
            || !task->query("startroom")      
            || task->query("env/invisibility")
            || task->query("taskguai")
            || task->query("race") != "����"
            || !objectp(room = environment(task))
            || room->query("no_fight"))
                continue;

        if (strsrch(file_name(room),"/d/") < 0) 
                continue;

        if (strsrch(file_name(room),"/d/hellfire/") > 0) 
                continue;
        if (strsrch(file_name(room),"/d/quest/") > 0) 
                continue;
        task->set("place", MISC_D->find_place(room));
        task->set("where", room);
        break;
    } 

    return task;
}

// recovers thier hp status
// mudring Sep/08/2002
varargs void full_hp_status(object me, int raw)
{
    int force, mana;

    force = (int)me->query("max_force");
    mana  = (int)me->query("max_mana");

    me->set("eff_kee", (int)me->query("max_kee"));
    me->set("kee", (int)me->query("max_kee"));
    me->set("eff_sen", (int)me->query("max_sen"));
    me->set("sen", (int)me->query("max_sen"));

    me->set("force", force * 2);
    me->set("mana", mana * 2);

    if (userp(me) && raw)
    {
        me->set("food",me->max_food_capacity());
        me->set("water",me->max_water_capacity());
        me->clear_condition();
        if (me->is_ghost()) me->reincarnate();
        if (!living(me)) me->revive();
    }
}

// npc set the basic parameter from ob
// mudring Sep/08/2002
void set_npc_hp(object me, object ob, int scale)
{
    mapping my, hp_status;

    hp_status = ob->query_entire_dbase();
    my = me->query_entire_dbase();

    if (!scale)
    {
        if (undefinedp(my["scale"]))
            my["scale"] = 100;
        scale = my["scale"];
    }

    my["str"] = 30;
    my["int"] = 30;
    my["con"] = 30;
    my["cps"] = 30;
    my["cor"] = 30;
    my["spi"] = 30;
    my["per"] = 30;
    my["kar"] = 30;

    my["max_kee"]       = hp_status["max_kee"] * scale / 100;
    my["eff_kee"]       = my["max_kee"];
    my["kee"]           = my["max_kee"];
    my["max_sen"]       = hp_status["max_sen"] * scale / 100;
    my["eff_sen"]       = my["max_sen"];
    my["sen"]           = my["max_sen"];
    my["max_mana"]      = hp_status["max_mana"]* scale / 100;
    my["mana"]          = my["max_mana"] * 2;
    my["max_force"]     = hp_status["max_force"]* scale / 100;
    my["force"]         = my["max_force"] * 2;
    my["force_factor"]  = hp_status["force_factor"];
    my["mana_factor"]   = hp_status["mana_factor"];
     my["combat_exp"]    = hp_status["combat_exp"] / 100* scale ;
       my["daoxing"]       = hp_status["daoxing"] / 100* scale ;

    me->full_hp_status(me);
}

// get ob skills max level
// mudring Sep/09/2002
int get_skill_level(object ob)
{
    mapping skill_status;
    int *skl_lvl, max_lvl, i;

    skill_status = ob->query_skills();
    i = sizeof(skill_status);

    if (i > 0)
    {
        skl_lvl = values(skill_status);
        max_lvl = skl_lvl[0];

        while (i--)
        {
            if (skl_lvl[i] > max_lvl)
                max_lvl=skl_lvl[i];
        }
        if (max_lvl < 50)
            max_lvl = 50;
    }
    else
        max_lvl = 50;

    return max_lvl;
}
void do_reset_me (object me)
{
        int i;
        object *inv;
        mapping skill_status, map_status;
        string *skillnames, *mapnames;

        reset_eval_cost();
        if ( mapp(map_status = me->query_skill_map()) )
        {
                mapnames = keys(map_status);
                for(i=0; i<sizeof(mapnames); i++)
                {
                        me->map_skill(mapnames[i]);
                }
        }

        if ( mapp(skill_status = me->query_skills()) )
        {
                skillnames = keys(skill_status);
                for(i=0; i<sizeof(skillnames); i++)
                {
                        me->delete_skill(skillnames[i]);
                }
        }

        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
                destruct (inv[i]);
        }

        me->set("str", 30);
        me->set("per", 30);
        me->set("int", 30);
        me->set("age", 30);

        me->set("weapon", 0);
        me->set("armor", 0);

        me->set_skill("force",  60);
        me->set_skill("spells", 60);
        me->set_skill("unarmed",60);
        me->set_skill("sword",  60);
        me->set_skill("dodge",  60);
        me->set_skill("parry",  60);

        me->set("max_gin", 600);
        me->set("eff_gin", 600);
        me->set("gin", 600);
        me->set("max_kee", 600);
        me->set("eff_kee", 600);
        me->set("kee", 600);
        me->set("max_sen", 600);
        me->set("eff_sen", 600);
        me->set("sen", 600);
        me->set("force", 600);
        me->set("max_force", 600);
        me->set("mana", 600);
        me->set("max_mana", 600);
        me->set("force_factor", 20);
        me->set("combat_exp", 100000);
        me->set("daoxing", 100000);

        me->setup();
        reset_eval_cost();

}

// npc copy other's skill
// mudring Sep/09/2002
void copy_npc_skill(object me, object ob, int scale)
{
    mapping skill_status, map_status;
    string *sname, *mname;
    int i, temp, skill_level;

    if (!scale) scale = 100;

    if (!ob->query_skills())
        return;

    if (mapp(skill_status = me->query_skills()))
    {
        skill_status = me->query_skills();
        sname = keys(skill_status);
        temp = sizeof(skill_status);
        for (i = 0; i < temp; i++)
            me->delete_skill(sname[i]);
    }

    if (mapp(skill_status = ob->query_skills()))
    {
        skill_status = ob->query_skills();
        sname = keys(skill_status);
        skill_level = get_skill_level(ob) * scale / 100;

        for (i = 0; i < sizeof(skill_status); i++)
            me->set_skill(sname[i], skill_level);
    }

    if (mapp(map_status = me->query_skill_map()))
    {
        mname = keys(map_status);
        temp = sizeof(map_status);
        for (i = 0; i < temp; i++)
            me->map_skill(mname[i]);
    }

    if (mapp(map_status = ob->query_skill_map()))
    {
        mname = keys(map_status);
        for (i = 0; i < sizeof(map_status); i++)
            me->map_skill(mname[i], map_status[mname[i]]);
    }
}

// copy a npc from ob
// mudring Sep/10/2002
void copy_npc(object me, object ob, int scale)
{
    set_npc_hp(me, ob, scale);
    copy_npc_skill(me, ob, scale);
}

void random_set_skills(int level ,object me)
{
int  j, k; 
mixed*  file;

             file = get_dir( "/adm/npc/skillcontrol/*.c", -1 ); 
             j = random(sizeof(file));
         ("/adm/npc/skillcontrol/"+file[j][0])->set_skills(level,me);

        ("/adm/npc/skillcontrol/"+file[j][0])->set_skills(level,me);
}
