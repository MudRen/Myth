// rm.c
// created by doing
// added log and monitord by mudring

#include <ansi.h>
 
inherit F_CLEAN_UP;
 
private int rm_item(string file, int rm_dir, object me);
int rm_dir(string dir);
int help(object me);

int main(object me, string arg)
{
        string file;
        string dir;
        int rm_dir;
        int count;
        string path;
        mixed flist;
        int i;
 
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        seteuid(geteuid(me));
 
        if (! arg)
        {
                help(me);
                return 1;
        }

        if (sscanf(arg, "-R %s", dir) == 1)
        {
                if (me && ! is_root(me))
                {
                        write("ֻ�й���Ա����ʹ�� -R ������\n");
                        return 1;
                }

                if (strsrch(dir, "*") != -1)
                {
                        write("Ϊ�˰�ȫ�����ʹ�� -R �Ĳ�����ʱ����ʹ��ͨ�����\n");
                        return 1;
                }

                if (dir == "/")
                {
                        write("�㲻��ɾ����Ŀ¼��\n");
                        return 1;
                }

                rm_dir = 1;
        } else
        {
                dir = arg;
                rm_dir = 0;
        }

        file = resolve_path(me->query("cwd"), dir);
        flist = get_dir(file);
        if (arrayp(flist)) flist -= ({ ".", ".." });
        if (! arrayp(flist) || ! sizeof(flist))
        {
                write("û������ļ���\n");
                return 1;
        }

        path = "";
        while ((i = strsrch(file, "/")) != -1)
        {
                path += file[0..i];
                file = file[i + 1..<1];
        }

        if (rm_dir)
                MONITOR_D->report_adm_object_msg(me,
                  HIR " Rmdir " + path + file+ "/��waiting..." NOR);

        count = 0;
        for (i = 0; i < sizeof(flist); i++)
        {
                count += rm_item(path + flist[i], rm_dir, me);
        }

        if (count) {
                MONITOR_D->report_adm_object_msg(me,
                  HIR " Rm " + path + file + "..." NOR);
                write(HIY "�ܹ���" + count + "���ļ����ɹ�ɾ����\n" NOR);
                log_file("cmds/edit/" + geteuid(me),

                sprintf("Rm %s%s at %s from %s\n",
                  path, file, log_time(), query_ip_number(me) ) );
        }
        else
                write("û��ɾ���κ��ļ���\n");
        return 1;
}

private int rm_item(string file, int rm_dir, object me)
{
        switch (file_size(file))
        {
        case -1:
                write("û������ļ���\n");
                return 0;

        case -2:
                if (rm_dir)
                        return rm_dir(file);

                if (rmdir(file))
                        write("�ɹ���ɾ����Ŀ¼(" + file + ").\n");
                else
                        write("��û��ɾ����Ŀ¼��Ȩ�޻�����ͼɾ��һ��"
                              "�ǿյ�Ŀ¼(" + file + ")��\n");
                return 0;
                
        default:
                SECURITY_D->backup_file(file);
                if (rm(file))
                        return 1;

                if (! SECURITY_D->valid_read(file, me, "ls"))
                        return 0;

                write("��û��ɾ��(" + file + ")��Ȩ�ޡ�\n");
                return 1;
        }
}
 
int rm_dir(string dir)
{
        mixed *file;
        int count;
        int i;

        if (! is_root(previous_object()))
                return 0;

        count = 0;
        if (dir[strlen(dir) - 1] != '/') dir += "/";
        file = get_dir(dir, -1);

        i = sizeof(file);
        while (i--)
        {
                reset_eval_cost();
                if (file[i][1] != -2)
                        if (rm(dir + file[i][0]))
                                count++;
        }

        i = sizeof(file);
        while (i--)
        {
                reset_eval_cost();
                if (file[i][1] == -2)
                        count += rm_dir(dir + file[i][0]);
        }

        write (HIC "ɾ��Ŀ¼(" + dir + ")��\n" NOR);
        rmdir(dir);
        return count;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : rm [-R] ������
 
��ָ�������ɾ��ĳ��������Ŀ¼�����ʹ����-R����������ɾ���ǿյ�Ŀ
¼��ʹ�øò������ҪС�ģ�����ɾ����·����

see also: cp, mv
HELP );
        return 1;
}

