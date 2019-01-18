// monitord.c
// by snowcat 6/20/97
//
// �벻Ҫֱ�����߱༭���ļ�
// Modify by Mudring@SanJie

#define DEBUG 0
// 10  #define RING_DIR "/u/mudring/"
#include <ansi.h>
#include <localtime.h>

inherit F_DBASE;

nosave string msg_log;
nosave int log_from; 
string query_msg_log() { return msg_log; }
varargs void mudring_log(string path, object user, string msg, int flag);
void create()
{
        seteuid(getuid());
        set("channel_id", "��ؾ���");
}

void report_system_msg (string msg)
{
        CHANNEL_D->do_channel(this_object(), "sys", msg);
        mudring_log("sys", this_object(), msg);
}

void report_system_object_msg (object ob, string msg)
{
        CHANNEL_D->do_channel(this_object(), "sys",
                ob->name() + "(" + capitalize(ob->query("id")) + ")" + msg);
        mudring_log("mon", ob, msg);
}

// all job show here
void report_quest_object_msg (object ob, string msg)
{
        CHANNEL_D->do_channel(this_object(), "qst",
                ob->name() + "(" + capitalize(ob->query("id")) + ")" + msg);
}
void report_rumor_object_msg(object ob, string msg)
{
        CHANNEL_D->do_channel(this_object(), "rumor","��˵"+
                ob->name(1) + msg);
}

// cmds monitore
void report_adm_object_msg (object ob, string msg)
{
        CHANNEL_D->do_channel(this_object(), "wiz",
                ob->name(1) + "(" + capitalize(getuid(ob)) + ")" + msg);
        mudring_log("wizedit", ob, msg);
}

// new job quest ...
void report_debug_object_msg (object ob, string msg)
{
        CHANNEL_D->do_channel(this_object(), "debug",
                ob->name(1) + "(" + capitalize(getuid(ob)) + ")" + msg);
        mudring_log("debug", ob, msg);
}

// all log use this function
// mudring Aug/05/2002
varargs void mudring_log(string path, object user, string msg, int flag)
{
#ifdef DEBUG
        string lfn;
        mixed lt;
        int t;

        if (! stringp(msg_log)) msg_log = "";

        t = time();
        msg_log += sprintf(" [%s] %s %s\n",
                           ctime(time())[11..18], getuid(user),
                           filter_color(msg));
           if (strlen(msg_log) > 0 || t - log_from > 0) { 
                lt = localtime(t);

                lfn = sprintf("check/" + path + "/%d-%d-%d", lt[LT_YEAR],
                              lt[LT_MON] + 1, lt[LT_MDAY]);
                if (! flag) {
                        assure_file(LOG_DIR + lfn);
                        log_file(lfn, msg_log);
                }
                else {
                        assure_file(RING_DIR + lfn);
                        write_file(RING_DIR + lfn, msg_log);
                }
                msg_log = ""; 
                log_from = t; 
           } 
#endif
}


string ring_time(int t)
{
    string str;
    mixed lt;
    lt = localtime(t);
    str = sprintf("%d-%d-%d", lt[LT_YEAR], lt[LT_MON] + 1, lt[LT_MDAY]);
    return str;
}

void log_file(string file, string text)
{
    file = LOG_DIR + file;
    assure_file(file);
/*
    if (text[<1] != '\n')
        text += "\n";
*/
    write_file(file, text);
/*
    if (file_size(file) > 500000)
    {
        rename(file, file + "." + time());
    }
*/
}
