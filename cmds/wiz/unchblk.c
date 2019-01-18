// channel block command..
// modify by mudring

#include <getconfig.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        if (! arg)
                return notify_fail("ָ���ʽ: unchblk <player id>\n");
                
        ob = UPDATE_D->global_find_player(arg);
        if (! ob)
                return notify_fail(LOCAL_MUD_NAME() + "��û������ˣ�\n");

        if (! ob->query("channel"))
        {
                UPDATE_D->global_destruct_player(ob);
                return notify_fail("����˵�Ƶ��Ŀǰ�úõġ�\n");
        }

        ob->delete("channel");
        write("�����" + ob->name(1) + "��Ƶ����\n");
        tell_object(ob, me->name() + "�������Ƶ����\n");
        log_file("cmds/chblk",
            sprintf("%s unchblk %s at %s.\n", getuid(me), getuid(ob), log_time() ));

        UPDATE_D->global_destruct_player(ob, 1);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : unchblk <���>

�������ĳ����ҵ�Ƶ����

HELP );
        return 1;
}

