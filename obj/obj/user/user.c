// user.c

#include <ansi.h>
#include <origin.h>
#include <user.h>
#include <command.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_BACKUP;
inherit F_ENCODING;

nosave int net_dead;
int    is_net_dead()    { return net_dead || ! interactive(this_object()); }
int    is_player()      { return clonep(); }
int    is_pker()        { return query_condition("no_pk_time"); }

nosave int last_age_set;

void create()
{
    ::create();
    set_name("ʹ�������", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
    set_temp("terminal_type", term_type);
    message("system", "�ն˻���̬�趨Ϊ " + term_type + "��\n", this_object());
}

void reset()
{
    if ((int)query("potential") - (int)query("learned_points") < 100)
        add("potential", 1);
    if ((int)query("thief") > 0)
        add("thief", -1 );
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
    string id;

    id = query("id", 1);
    if (!id) id = geteuid();
    if (!id) id = getuid();
    if (!stringp(id)) return 0;

    return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

// override set function
mixed set(string idx, mixed para)
{
    if (idx == "name" && clonep(this_object()) &&
        geteuid(this_object()))
    {
        NAME_D->change_name(this_object(), para, 1);
        return para;
    }
    else
    return ::set(idx, para);
}

int save(int raw)
{
    int res;

    if (!raw) save_autoload();
    res = ::save();
    if(!raw) clean_up_autoload();           // To save memory

#if INSTALL_EXAMINE
    EXAMINE_D->examine_player(me);
#endif
    return res;
}

int backup()
{
    int res;

    save_autoload();
    res = ::backup();
    clean_up_autoload();            // To save memory
    return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
    int userage;
    string suserage;
        
    if (environment()&&environment()->query("no_time"))
    {        
        last_age_set = time();
        return;
    }
    if (!last_age_set) last_age_set = time();
    add("mud_age", time() - last_age_set);
    last_age_set = time();
    userage=14 + (int)query("age_modify")/86400 + (int)query("mud_age")/ 86400;
    set("age", userage);
    suserage=sprintf("%d",userage);
    if ((int)query("mud_age")%86400 < 16
        && !query("shengri/"+suserage))
    {
        if (query("combat_exp")<20000) return;
        tell_object(this_object(),"ף�����տ��֣���ϲ�㽫����ر���������\n");
        this_object()->set("shengri/"+suserage,1);
        this_object()->set("birthday",1);
    }
}

void setup()
{
    mapping fabao_map;
    string  *fabao_list, *id_list, *t_list;
    int             i;
    object  newob,newbag;
    string  fabao_id;

    // We want set age first before new player got initialized with
    // random age.
    update_age();

    ::setup();
    restore_autoload();

    // here We restore the self-made fabao
    fabao_map = query("fabao");
    if (!mapp(fabao_map))
        return;

    fabao_list = keys(fabao_map);
    for(i=0; i<sizeof(fabao_list); i++)
    {
        newob = new("/obj/fabao");
        if (newob )
        {
            newob->set("owner_id", query("id"));
            newob->set("series_no", fabao_map[fabao_list[i]]);
            if (!newob->restore())
            {
                tell_object(this_object(), "���� restore fabao. \n");
                destruct(newob);
                continue;
            }
            fabao_id = (string)newob->query("id");
            if (!fabao_id)
            { // mon 9/5/98
                destruct(newob);
                continue;
            }
            fabao_id = replace_string(fabao_id, " ", "_");
            newob->set("id", fabao_id);
            seteuid(fabao_id);
            export_uid(newob);
            seteuid(getuid());

            id_list = ({ fabao_id });
            t_list = explode(fabao_id, "_");
            if (sizeof(t_list) > 1)
            {
                id_list += t_list;
            }
            newob->set_name(newob->query("name"), id_list);
            if (stringp(newob->query("default_file")))
                newob->set_default_object( newob->query("default_file") );
             newob->save();
            newob->move(this_object());
        }
    }

    if (query("doing"))
        CLOSE_D->continue_doing(this_object());
}

private void user_dump(int type)
{
    object me = this_object();

    switch(type)
    {
    case DUMP_NET_DEAD:
        if (environment())
        {
            tell_room(environment(), query("name") + "���߳��� " +
                NET_DEAD_TIMEOUT / 60 + " ���ӣ��Զ��˳�������硣\n");
        }
        catch(command("quit"));
        if (objectp(me) && ! query("doing"))
        {
            // command quit failed.
            QUIT_CMD->force_quit(me);
        }
        break;

    case DUMP_IDLE:
        // use input keep idle bug have fixed ...mudring
        if (!environment(me)->query("chat_room"))
        {
            // wizard idle auto visible ...mudring.
            if (wizardp(me))
            {
                if (!query("env/invisibility"))
                {
                    me->set("env/invisibility",1);
                    tell_object(me, "���ķ���ʱ�������ϵͳ����ת���Զ������С�\n");
                }
            }
            else
            {
                 tell_object(me, "�Բ������Ѿ��������� " 
                     + IDLE_TIMEOUT/60 + " �����ˣ����´�������\n");
                 if (environment())
                 {
                     tell_room( environment(), "һ��紵�����������е�" + query("name")
                         + "��Ϊһ�ѷɻң���ʧ�ˡ�\n", ({me}));
                 }
                 command("quit");
                 if (objectp(me) && ! query("doing"))
                 {
                     // command quit failed.
                     QUIT_CMD->force_quit(me);
                 }
                                   
                 return;
            }
        }
        if (in_input() && (!wizardp(me)))
        {
            tell_object(me, "�Բ������Ѿ��������ַ������� " 
                + IDLE_TIMEOUT/60 + " �����ˣ����´�������\n");
            tell_room( environment(), "һ��紵�������������ַ����е�" + query("name")
                + "��Ϊһ�ѷɻң���ʧ�ˡ�\n", ({me}));
            command("quit");
            if (objectp(me) && ! query("doing"))
            {
                // command quit failed.
                QUIT_CMD->force_quit(me);
            }
            return;
        }
        break;
    default:
        return;
    }
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
    object link_ob;

    this_object()->remove_interactive();

    if (! query("doing"))
        set_heart_beat(0);

    if (objectp(link_ob = query_temp("link_ob")))
    {
        if (link_ob->query_temp("ip_number"))
        {
            link_ob->set("last_on", time());
            link_ob->set("last_from",
                link_ob->query_temp("ip_number"));
            link_ob->save();
        }
        destruct(link_ob);
    }

    // no_net_dead room force quit... mudring 
    if (! environment()
        || (environment(this_object())->query("no_net_dead")))
    {
                QUIT_CMD->force_quit(this_object());
                return;
    }

    net_dead = 1;

        
    if (userp(this_object()) && ! query("doing"))
    {
        // wizard no net_dead ...mudring Sep/19/2002
        if (wizardp(this_object()))
            call_out("user_dump", 90, DUMP_NET_DEAD);
        else
            call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
             if(query("id")!="stey")
               {
        tell_room(environment(), query("name") + "�����ˡ�\n", this_object());
        CHANNEL_D->do_channel(load_object(LOGIN_D), wiz_level(this_object())?"wiz":"sys", filter_color(short(1)) + " �����ˡ�");
            }
        remove_all_enemy();
    }
    else
    {
        if (environment())
            message("vision", name() + "�����ˡ�\n",
                environment(), ({ this_object() }));
        CHANNEL_D->do_channel(load_object(LOGIN_D), wiz_level(this_object())?"wiz":"sys",filter_color(short(1)) + " �����ˡ�");
    }
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
    set_heart_beat(1);
    net_dead = 0;
    remove_call_out("user_dump");
    tell_object(this_object(), "����������ϡ�\n");
}

