#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
int main(object me,string arg)
{
        string mud, file, msg, *files;
        if ( me != this_player(1))
                return notify_fail(geteuid(this_player(1)) + "ǿ����ʹ��" + file_name(this_object()) +"����ʧ��!\n");
        if (!arg) 
                return help(me);
        if (sscanf(arg, "%s %s", mud, file)!= 2 )
                return help(me);
        file = resolve_path(me->query("cwd"), file);
        if (file_size(file) < 0 )
                return notify_fail("�޴��ļ���ΪĿ¼!\n");
        msg = read_file(file);
        if (!msg || msg == "")
                return notify_fail("���ܴ��Ϳ��ļ�!\n");
        files = explode(file, "/");
        file = files[sizeof(files)-1];
        "/adm/daemons/network/services/transfer_q.c"->send_msg(me, mud, file, msg);
        write("��Ϣ���ύ,��ȴ�!\n");
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : transfer MUD_NAME FILE_NAME

����������ΪMUD_NAME ��mud����һ������ΪFILE_NAME���ļ�!
HELP
     );
     return 1;
}

