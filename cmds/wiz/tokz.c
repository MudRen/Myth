// tokz.c
// by mudring

inherit F_CLEAN_UP;

string JAIL="/d/city/kezhan";

int main(object me, string arg)
{
    int online;
    object who, env;

    seteuid(geteuid(me));

    if (!arg) return notify_fail("����Ҫ��˭�ͻؿ�ջ��\n");
    arg=replace_string(arg,"#"," ");
    arg=replace_string(arg,"."," ");

    who = UPDATE_D->global_find_player(arg);

    if (env=environment(who))
        message_vision("�����̽��һֻ���ֽ�$Nץ���������ˡ�\n", who);

    who->move(JAIL);
    who->set("startroom",JAIL);
    if (who->query("punished"))
        who->delete("punished");

    log_file("cmds/to_kezhan",
        sprintf("%s send %s tokz at %s.\n",
            getuid(this_player()), getuid(who), log_time()));
    write("�㽫"+who->query("name")+"("+arg+")�ͽ��˿�ջ��\n");

    UPDATE_D->global_destruct_player(who, 1);
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��tokz id 

Send <id> to kz.
HELP
    );
    return 1;
}


