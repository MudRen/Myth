// alias.c
// Modified By Mudring@SanJie

#include <ansi.h>
#include <message.h>

#define MAX_REPEAT 100
#define MAX_ALIASES 40

mapping alias;

nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;
nosave int last_time=time(), cmd_cnt=0, cmd_cnt1=0, cmd_cnt2=0;

// speed of player input commands.
int query_cmd_count() {return cmd_cnt2;}

string process_input(string str)
{
    string *args, cmd, argstr;
    int i, j, curr_time;
    object me;

    me = this_object();
    notify_fail("什么？\n");
    clear_written();

    if (me->query_temp("block_msg/all") || !living(me))
        return "";
    if (in_edit() || in_input())
        return "";

    reset_eval_cost();

    for (i=0; i<strlen(str); i++)
    {
         if (str[i]!=' ')
         {
             str = str[i..<1];
             break;
         }
    }

    if (str == "")
        return str;

    if (cmd_cnt++ > MAX_REPEAT)
    {
        curr_time = time();
        if (curr_time - last_time < 5)
        {
//            me->add_busy(1);
            if (cmd_cnt1 == 0)
            {
                mixed busy;
                cmd_cnt2 = cmd_cnt / (curr_time - last_time + 1);
                write("你一次输入太多命令了。\n");
//                busy = me->query_busy();
//                if (intp(busy))
//                    tell_object(me, "你的行动将受限" + busy*2 + "秒。\n");
            }
            cmd_cnt1++;
            if (cmd_cnt1 > 30) cmd_cnt1 = 0;
            last_time = curr_time; 

            return "";
        } else
        {
              cmd_cnt2 = cmd_cnt / (curr_time - last_time + 1);
              last_time = curr_time;
              cmd_cnt = 0;
              cmd_cnt1 = 0;
        }
    }

    if (!wizardp(me))
    {
        if (me->query("eff_kee") < 0 || me->query("eff_sen") < 0)
        {
            tell_object(me, "你马上要死亡了，不能做任何事情。\n");
            return "";
        }
        if (me->query("kee") < 0 || me->query("sen") < 0)
        {
            tell_object(me, "你马上要昏迷了，不能做任何事情。\n");
            return "";
        }
    }
    
    if (me->query_temp("big5")) str = CONVERT_D->b5_gb(str);
	
    if (mapp(alias))
    {
        if (!undefinedp(alias[str]))
            str = replace_string( alias[str], "$*", "" );

        if (sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]))
        {
            cmd = replace_string(alias[cmd], "$*", argstr);
            args = explode(argstr, " ");
            if (j = sizeof(args))
                for (i=0; i<j; i++)
                    cmd = replace_string( cmd, "$" + (i+1), args[i] );
                str = cmd;
        }
    }

    last_input = (string)ALIAS_D->process_global_alias(str);
    log_command(last_input);

    return last_input;
}

int set_alias(string verb, string replace)
{
    if (!replace)
    {
        if (mapp(alias))
            map_delete(alias, verb);
         return 1;
    } else
    {
        if (!mapp(alias))
            alias = ([ verb:replace ]);
        else if (sizeof(alias) > MAX_ALIASES)
            return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");
        else
            alias[verb] = replace;
        return 1;
    }
}

mapping query_all_alias() {return alias;}
