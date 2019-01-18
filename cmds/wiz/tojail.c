// tojail.c
// by mudring

inherit F_CLEAN_UP;

string JAIL="/d/wiz/jail";

int main(object me, string arg)
{
    int online;
    object who, env;

    seteuid(geteuid(me));

    if (!arg) return notify_fail("����Ҫ��˭������Σ�\n");
    arg=replace_string(arg,"#"," ");
    arg=replace_string(arg,"."," ");

    who = UPDATE_D->global_find_player(arg);
    if (!objectp(who))
    {
        write("û������ˣ�\n");
        UPDATE_D->global_destruct_player(who);
        return 1;
    }

    if (env=environment(who))
        message_vision("�����̽��һֻ���ֽ�$Nץ���������ˡ�\n", who);

    who->move(JAIL);
    who->set("punished",1);
    who->set("startroom",JAIL);

    if (!wiz_level(who))
    log_file("cmds/to_jail",
        sprintf("%s send %s tojail at %s.\n",
            getuid(this_player()), getuid(who), log_time()));
    write("�㽫"+who->query("name")+"("+arg+")�ͽ��˼��Ρ�\n");

    UPDATE_D->global_destruct_player(who, 1);
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��tojail id 

Send <id> to jail.
HELP
    );
    return 1;
}


