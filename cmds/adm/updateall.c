// updateall.c
// by Doing

#include <ansi.h>

inherit F_CLEAN_UP;

int update_dir(object me, string dir, int continueable, int *total);
int update_file(object me, string file);

int main(object me, string arg)
{
        string dir;
        int continueable;
        int *total = ({0});

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        seteuid(geteuid(me));

        continueable = 0;
        if (! arg || sscanf(arg, "%s %d", dir, continueable) != 2)
                dir = arg;

        if (! dir)
        {
                dir = me->query("cwd");
                if (! dir)
                        return notify_fail("��Ҫ���±����Ǹ�·���µ�����\n");
        } else
        {
                dir = resolve_path(me->query("cwd"), dir);
        }
        if (dir[strlen(dir) - 1] != '/')
                dir += "/";

        if (file_size(dir) != -2)
                return notify_fail("û��" + dir + "���·����\n");

        me->set("cwd", dir);

        MONITOR_D->report_adm_object_msg(me, "�����������У����Ժ򣮣���");
        if (! update_dir(me, dir, continueable, total))
        {
                write(HIR "��������������ֹ��\n" NOR);
        }

        if (total[0] > 0)
                write(HIC "�ܹ���" + HIW + total[0] + HIC "���������ɹ����룡\n" NOR);
        else
                write(HIC "û�б����κε�����\n" NOR);

        return 1;
}

int update_dir(object me, string dir, int continueable, int *total)
{
        int i;
        int l;
        int filecount, compcount;
        mixed *file;
        string filename;

        if (! is_root(previous_object()))
                return 0;

        file = get_dir(dir, -1);
        if (! sizeof(file))
        {
                if (file_size(dir) == -2)
                        write(dir + "���Ŀ¼�ǿյġ�\n");
                else
                        write("û��" + dir + "���Ŀ¼��\n");
                return 1;
        }

        write (HIY "��ʼ����Ŀ¼" + dir + "����������ļ���\n" NOR);
        i = sizeof(file);
        compcount = 0;
        filecount = 0;
        while (i--)
        {
                reset_eval_cost();
                if (file[i][1] != -2)
                {
                        filecount++;
                        filename = file[i][0];
                        l = strlen(filename);
                        if (filename[l - 1] != 'c' || filename[l - 2] != '.')
                                continue;

                        if (! update_file(me, dir + filename) &&
                            ! continueable)
                                return 0;

                        compcount++;
                        total[0]++;
                        if ((compcount % 70) == 0)
                                write("\n");
                }

                // continue to compile next file
        }
        write(HIC "\n������Ŀ¼" + dir + "�µ�" + HIW + filecount + HIC +
              "���ļ�������������" + HIW + compcount + HIC + "��������\n" NOR );

        i = sizeof(file);
        while (i--)
        {
                reset_eval_cost();
                if (file[i][1] == -2)
                {
                        file[i][0] += "/";
                        write("\n");
                        if (! update_dir(me, dir + file[i][0], continueable, total) &&
                            ! continueable)
                                return 0;
                }
        }
        return 1;
}

int update_file(object me, string file)
{
        object obj;
        object *inv;
        string err;
        int i;

        if (file == "/cmds/adm/updateall.c")
                // Don't re-compile the updateall.c
                return 1;

        write (".");
        if (obj = find_object(file))
        {
                if (obj == environment(me))
                {
                        if (file_name(obj) == VOID_OB)
                                return notify_fail("\n�㲻���� VOID_OB �����±��� VOID_OB��\n");

                        inv = all_inventory(obj);
                        i = sizeof(inv);
                        while(i--)
                        {
                                if (userp(inv[i])) inv[i]->move(VOID_OB, 1);
                                else inv[i] = 0;
                        }
                }
                destruct(obj);
        }

        if (obj) return notify_fail("\n�޷�����ɳ�ʽ�롣\n");

        err = catch( call_other(file, "???") );
        if (err)
        {
                printf( "\n��������\n%s\n", err );
                return 0;
        } else
        {
                if ((i = sizeof(inv)) && (obj = find_object(file)))
                {
                        while(i--)
                                if (inv[i] && userp(inv[i])) inv[i]->move(obj, 1);
                }
        }

        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : updateall <·����> [1]
 
���ָ����Ը���ĳ��·���µ�ȫ������, �����µ������������
������. �������β���־1�� �������������ʱ��������ֹ��
HELP
    );
    return 1;
}

