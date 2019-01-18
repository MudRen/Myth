// auth.c
// Doing

#include <ansi.h>

inherit F_CLEAN_UP;

string  auth_msg(mapping ruler, mapping default_ruler, string euid, string status);
int     in_map(string usr, mapping m, string index);
int     remove_from_map(string usr, mapping m, string index);
mapping add_into_map(string usr, mapping m, string index);
void    reset_security();
string  title(string t);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob;
        string msg;
        string dir;
        string para;
        string usr;
        string euid;
        string status;
        mapping dtr, der, dtw, dew; // t = trusted e = exclude
        mapping ctr, cer, ctw, cew; // r = read    w = write
        mapping etr, eer, etw, eew; // d = default e = extend  c = current
        int flag;

        if (getuid(me)!="mudring" && getuid(me)!="stey") return 0;

        if (! is_root(me) && ! SECURITY_D->valid_grant(me, "(admin)"))
                return notify_fail("��û��Ȩ�޷��ʰ�ȫϵͳ��\n");

        seteuid(geteuid(me));
        dtr = SECURITY_D->query_security("default_trusted_read");
        der = SECURITY_D->query_security("default_exclude_read");
        dtw = SECURITY_D->query_security("default_trusted_write");
        dew = SECURITY_D->query_security("default_exclude_write");
        etr = SECURITY_D->query_security("extend_trusted_read");
        eer = SECURITY_D->query_security("extend_exclude_read");
        etw = SECURITY_D->query_security("extend_trusted_write");
        eew = SECURITY_D->query_security("extend_exclude_write");
        ctr = SECURITY_D->query_security("trusted_read");
        cer = SECURITY_D->query_security("exclude_read");
        ctw = SECURITY_D->query_security("trusted_write");
        cew = SECURITY_D->query_security("exclude_write");
        if (! arg)
        {
                msg = "Ŀǰ�ļ����ڰ�ȫ��������Ϣ(��ɫ��ʾȱʡ����)��\n";
                msg += HIR + title("��ȡ��ֹ") + NOR;
                msg += auth_msg(cer, der, 0, 0);
                msg += HIC + title("��ȡ���") + NOR;
                msg += auth_msg(ctr, dtr, 0, 0);
                msg += HIR + title("д���ֹ") + NOR;
                msg += auth_msg(cew, dew, 0, 0);
                msg += HIC + title("д�����") + NOR;
                msg += auth_msg(ctw, dtw, 0, 0);
                write(msg);
                return 1;
        } else
        if (arg == "read")
        {
                msg = "Ŀǰ�ļ����ڰ�ȫ��������Ϣ�ж�ȡ������(��ɫ��ʾȱʡ����)��\n";
                msg += HIR + title("��ȡ��ֹ") + NOR;
                msg += auth_msg(cer, der, 0, 0);
                msg += HIC + title("��ȡ���") + NOR;
                msg += auth_msg(ctr, dtr, 0, 0);
                write(msg);
                return 1;
        } else
        if (arg == "write")
        {
                msg = "Ŀǰ�ļ����ڰ�ȫ��������Ϣ��д�������(��ɫ��ʾȱʡ����)��\n";
                msg += HIR + title("д���ֹ") + NOR;
                msg += auth_msg(cew, dew, 0, 0);
                msg += HIC + title("д�����") + NOR;
                msg += auth_msg(ctw, dtw, 0, 0);
                write(msg);
                return 1;
        }

        if (sscanf(arg, "%s %s %s", usr, dir, para) != 3)
        {
                para = 0;
                if (sscanf(arg, "%s %s", usr, dir) != 2)
                {
                        dir = 0;
                        usr = arg;
                }
        }

        if (dir == "-clear")
        {
                remove_from_map(usr, etr, 0);
                remove_from_map(usr, eer, 0);
                remove_from_map(usr, etw, 0);
                remove_from_map(usr, eew, 0);

                SECURITY_D->set_security("extend_trusted_read", etr);
                SECURITY_D->set_security("extend_exclude_read", eer);
                SECURITY_D->set_security("extend_trusted_write", etw);
                SECURITY_D->set_security("extend_exclude_write", eew);
                reset_security();

                write("����˸��û����еķ�����Ϣ������ȱʡ���á�\n");
                return 1;
        }

        if (dir)
        {
                dir = resolve_path(me->query("cwd"), dir);
                dir = "/" + implode(explode(dir, "/") - ({ "" }), "/");
        }

        if (usr[0] == '(')
        {
                status = usr;
                euid = "Every";
        } else
        {
                status = wizhood(usr);
                euid = usr;
        }

        if (! dir)
        {
                msg = "Ŀǰ����" CYN + euid + status +
                      NOR "��Ȩ��(��ɫ��ʾȱʡ����)��\n";
                msg += HIR + title("��ȡ��ֹ") + NOR;
                msg += auth_msg(cer, der, euid, status);
                msg += HIC + title("��ȡ���") + NOR;
                msg += auth_msg(ctw, dtw, euid, status);
                msg += HIR + title("д���ֹ") + NOR;
                msg += auth_msg(cew, dew, euid, status);
                msg += HIC + title("д�����") + NOR;
                msg += auth_msg(ctw, dtw, euid, status);
                write(msg);     
                return 1;
        }

        if (! para)
        {
                msg = CYN + euid + status + NOR "�Ե���("
                      YEL + dir + NOR ")��Ȩ�ޣ�";
                if (SECURITY_D->valid_read(dir, euid == "Every" ? status : euid, "ls"))
                        msg += WHT "�ɶ� " NOR;
                else
                        msg += HIR "��ֹ��ȡ " NOR;

                if (SECURITY_D->valid_write(dir, euid == "Every" ? status : euid, "ls"))
                        msg += WHT "��д\n";
                else
                        msg += HIR "��ֹд��\n";
                write(msg);
                return 1;
        }

        switch (para)
        {
        case "can_read":
        case "not_read":
                if (in_map(usr, dtr, dir))
                {
                        write("ȱʡ������<���Զ�ȡ����>���Ѿ������˶�"
                              "���û�(��)��Ŀ¼�ķ���Ȩ��˵����\n");
                        break;
                }

                if (in_map(usr, der, dir))
                {
                        write("ȱʡ������<��ֹ��ȡ����>���Ѿ������˶�"
                              "���û�(��)��Ŀ¼�ķ���Ȩ��˵����\n");
                        break;
                }

                if (para == "can_read")
                {
                        remove_from_map(usr, eer, dir);
                        etr = add_into_map(usr, etr, dir);
                } else
                {
                        remove_from_map(usr, etr, dir);
                        eer = add_into_map(usr, eer, dir);
                }

                SECURITY_D->set_security("extend_trusted_read", etr);
                SECURITY_D->set_security("extend_exclude_read", eer);
                reset_security();
                write("�ɹ����޸��� " CYN + usr + NOR " ��Ŀ¼ " WHT + dir + NOR " �Ķ�ȡȨ�ޡ�\n");
                break;

        case "can_write":
        case "not_write":
                if (in_map(usr, dtw, dir))
                {
                        write("ȱʡ������<����д�����>���Ѿ������˶�"
                              "���û�(��)��Ŀ¼�ķ���Ȩ��˵����\n");
                        return 1;
                }
        
                if (in_map(usr, dew, dir))
                {
                        write("ȱʡ������<��ֹд�����>���Ѿ������˶�"
                              "���û�(��)��Ŀ¼�ķ���Ȩ��˵����\n");
                        return 1;
                }

                if (para == "can_write")
                {
                        remove_from_map(usr, eew, dir);
                        etw = add_into_map(usr, etw, dir);
                } else
                {
                        remove_from_map(usr, etw, dir);
                        eew = add_into_map(usr, eew, dir);
                }

                SECURITY_D->set_security("extend_trusted_write", etw);
                SECURITY_D->set_security("extend_exclude_write", eew);
                reset_security();
                write("�ɹ����޸��� " CYN + usr + NOR " ��Ŀ¼ " WHT + dir + NOR " ��д��Ȩ�ޡ�\n");
                break;

        case "unknow":
        case "none":
        case "inherit":
        case "default":

                flag  = remove_from_map(usr, etr, dir);
                flag |= remove_from_map(usr, eer, dir);
                flag |= remove_from_map(usr, etw, dir);
                flag |= remove_from_map(usr, eew, dir);
                if (! flag)
                {
                        write("ԭ��û�й��ڸ��û�(��)��Ŀ¼�ķ���Ȩ�����á�\n");
                        break;
                }

                SECURITY_D->set_security("extend_trusted_read", etr);
                SECURITY_D->set_security("extend_exclude_read", eer);
                SECURITY_D->set_security("extend_trusted_write", etw);
                SECURITY_D->set_security("extend_exclude_write", eew);
                reset_security();
                write("�ɹ���ȡ���� " CYN + usr + NOR " ��Ŀ¼ " WHT + dir + NOR " �ķ���Ȩ�ޡ�\n");
                break;
                
        default:
                write ("Ȩ�޲�������Ϊ can_read��not_read��can_write��"
                       "not_write��unknow �е�һ�֡�\n");
                break;
        }

        return 1;
}

string title(string t)
{
        return "�������������������������� " + t +
               " ��������������������������\n";
}

string auth_msg(mapping ruler, mapping default_ruler, string euid, string status)
{
        string *ks;
        string *arr;
        string msg;
        string line;
        int i, k;
        int l;

        msg = "";
        ks = sort_array(keys(ruler), (: strcmp($1, $2) :));
        for (i = 0; i < sizeof(ks); i++)
        {
                arr = ruler[ks[i]];
                if (! arrayp(arr) || ! sizeof(arr)) continue;
                line = 0;
                l = 0;
                for (k = 0; k < sizeof(arr); k++)
                {
                        if ((euid || status) &&
                            arr[k] != euid && arr[k] != status)
                                continue;

                        if (! line) line = sprintf(WHT "%-24s: ", ks[i]);
                        if (l >= 3)
                        {
                                l = 0;
                                line += "\n" + sprintf("%-24s  ", "");
                        }

                        if (default_ruler[ks[i]] &&
                            member_array(arr[k], default_ruler[ks[i]]) != -1)
                                line += CYN;
                        else
                                line += WHT;
                        line += sprintf("%-13s", arr[k]);
                        l++;
                }
                if (line) msg += line + "\n";
        }
        if (msg == "")
                msg = WHT "û�����ơ�\n" NOR;
        else
                msg += NOR;
        return msg;
}

int in_map(string usr, mapping m, string index)
{
        string *arr;

        if (! m || ! arrayp(arr = m[index]))
                return 0;

        if (member_array(usr, arr) != -1)
                return 1;

        return 0;
}

int remove_from_map(string usr, mapping m, string index)
{
        string *arr;
        string *ks;
        int i;
        int flag;

        if (! m)
                return 0;

        if (! index)
        {
                // lookup the mapping
                ks = keys(m);
                flag = 0;
                for (i = 0; i < sizeof(ks); i++)
                        flag |= remove_from_map(usr, m, ks[i]);
                return flag;
        }

        if (! arrayp(arr = m[index]))
                return 0;

        if (member_array(usr, arr) == -1)
                return 0;

        arr -= ({ usr });
        if (! sizeof(arr))
                map_delete(m, index);
        else
                m[index] = arr;
        return 1;
}

mapping add_into_map(string usr, mapping m, string index)
{
        string *arr;

        if (! m)
                m = ([ index : ({ usr }) ]);
        else
        if (! arrayp(arr = m[index]))
                m += ([ index : ({ usr }) ]);
        else
        if (member_array(usr, arr) == -1)
        {
                arr += ({ usr });
                m[index] = arr;
        }

        return m;
}

void reset_security()
{
        SECURITY_D->save();
        SECURITY_D->reset_security();
}

int help(object me)
{
        write(@HELP
ָ���ʽ : auth
           auth read | write
           auth <user> | <wizhood> -clear
           auth <user> | <wizhood> [ <directory> [ can_read | not_read | can_write | not_write | unknow ] ]

�������������ѯ��������ʦ��Ȩ�ޡ� ���ָ�� read | write  ������ѯ
��ȡ����д���Ȩ����Ϣ��

���ָ��һ���û������飬��ʾ��ѯ�������ø��û�(��)�İ�ȫȨ�ޣ����
ʹ���˲��� -clear ��ʾҪ������û�������ĵ�����Ȩ�ޡ����ָ����Ŀ
¼�����ø��û�(��)��Ŀ¼�ķ���Ȩ�ޡ����� unknow ��ʾ����Ը�Ŀ¼��
�����ã����̳��ϼ�Ŀ¼��Ȩ�ޡ�

ע�⣺����������Ϣ���޸ľ�����Υ��ȱʡ���ã������ȱʡ����ָ��ĳ��
�û�(��)���ܻ��ǿ��Է���ĳ��Ŀ¼���㲻�����������á���Ȼ��ȱʡ����
���ָ�������飬����Զ��û��ڽ������á����磺
ȱʡ���ã�(arch)���ܷ���/backup/
��������� test �û�����/backup/

HELP
    );
    return 1;
}


