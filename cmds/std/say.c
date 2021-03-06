// say.c

#include <ansi.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string tmp;
    object *user, *wizard, *ob;
        
    ob = all_inventory(environment(me));
    ob = filter_array(ob , (: userp($1) :));

    user = filter_array( ob ,(: !wizardp($1) :));
    wizard = filter_array( ob ,(: wizardp($1) :));
    if (!block_tell(me)) return 1;

    if (!arg)
    {
        write("你自言自语不知道在说些什么。\n");
        message("say", me->name() + "自言自语不知道在说些什么。\n",
            user, ({me}));
        message("say", WHT + "["+ capitalize(getuid(me)) + "]"
            + NOR + me->name() + "自言自语不知道在说些什么。\n",
            wizard, ({me}));
        return 1;
    }

    while (sscanf(arg, "%s"+NOR+"%s", arg, tmp))
        arg += CYN + tmp;

    if ((int)me->query("kee") < (int)me->query("max_kee") / 4)
    {
        arg = replace_string(arg, " ", " ... ") + " ...";
        write(CYN "你有气无力地说道：" + arg + "\n" NOR);
        message("say", CYN + me->name() + "有气无力地说道：" + arg + "\n" NOR,
            user, ({me}));
        message("say", WHT + "[" + capitalize(getuid(me)) + "]"
            + CYN + me->name() + "有气无力地说道：" + arg + "\n" NOR,
            wizard, ({me}));
    }
    else
    {
        write( CYN "你说道：" + arg + "\n" NOR);
        message("say", CYN + me->name() + "说道：" +  arg + "\n" NOR,
            user, ({me}));
        message("say", WHT + "[" + capitalize(getuid(me)) + "]"
            + CYN + me->name() + "说道：" +  arg + "\n" NOR,
            wizard, ({me}));
    }

    // The mudlib interface of say
    all_inventory(environment(me))->relay_say(me, arg);

    return 1;
}

int help (object me)
{
        write(@HELP
指令格式: say <讯息>
 
说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
        );
        return 1;
}

