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
        write("���������ﲻ֪����˵Щʲô��\n");
        message("say", me->name() + "�������ﲻ֪����˵Щʲô��\n",
            user, ({me}));
        message("say", WHT + "["+ capitalize(getuid(me)) + "]"
            + NOR + me->name() + "�������ﲻ֪����˵Щʲô��\n",
            wizard, ({me}));
        return 1;
    }

    while (sscanf(arg, "%s"+NOR+"%s", arg, tmp))
        arg += CYN + tmp;

    if ((int)me->query("kee") < (int)me->query("max_kee") / 4)
    {
        arg = replace_string(arg, " ", " ... ") + " ...";
        write(CYN "������������˵����" + arg + "\n" NOR);
        message("say", CYN + me->name() + "����������˵����" + arg + "\n" NOR,
            user, ({me}));
        message("say", WHT + "[" + capitalize(getuid(me)) + "]"
            + CYN + me->name() + "����������˵����" + arg + "\n" NOR,
            wizard, ({me}));
    }
    else
    {
        write( CYN "��˵����" + arg + "\n" NOR);
        message("say", CYN + me->name() + "˵����" +  arg + "\n" NOR,
            user, ({me}));
        message("say", WHT + "[" + capitalize(getuid(me)) + "]"
            + CYN + me->name() + "˵����" +  arg + "\n" NOR,
            wizard, ({me}));
    }

    // The mudlib interface of say
    all_inventory(environment(me))->relay_say(me, arg);

    return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
        );
        return 1;
}

