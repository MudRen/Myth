// edit.c
// Modified by mudring@sjsh

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string file)
{
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        if (! file)
                return notify_fail("ָ���ʽ��edit <����>\n");

        if (in_edit(me))
                return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");

        seteuid(geteuid(me));
        file = resolve_path(me->query("cwd"), file);

        if (!(int)SECURITY_D->valid_write(file,me,"write"))
                return notify_fail("��û���㹻�Ķ�дȨ����\n");

        foreach (object user in users())
        if (file == "/"+in_edit(user) )
                return notify_fail("�����ͻ��"+user->name(1)+"("+capitalize(user->query("id"))+")"+"���ڱ༭���ļ�("+file+")��\n");

        MONITOR_D->report_adm_object_msg(me,HIR" edit " + file + "!"NOR); 
        log_file("cmds/edit/"+geteuid(me), sprintf("edit %s at %s from %s.\n",
                                        file, log_time(),
                                        query_ip_number(me)));

        printf("�༭�ļ���%s\n",file);
        me->set("cwf", file);
        SECURITY_D->backup_file(file);
        ed(file);

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : edit <����>, edit here

���ô�һָ���ֱ�������ϱ༭������

HELP );
        return 1;
}

