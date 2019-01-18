// grant.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        int opt_clear, opt_del;
        int i;
        string *opts, *gr;                
        string user;
        object ob;
        string msg;

        if (! is_root(me) && ! SECURITY_D->valid_grant(me, "(admin)"))
                return notify_fail("ֻ�й���Ա����ʹ����Ȩ���\n");
/*
        if (! me->is_admin())
        {
                switch (SECURITY_D->query_site_privilege("grant"))
                {
                case "enable":
                        break;

                default:
                        return notify_fail("�㲻��Ϊ���������Ȩ��\n");
                }
        }
*/
        if (! arg)
        {
                gr = SECURITY_D->query_grant_users();
                if (! arrayp(gr) || sizeof(gr) < 1)
                {
                        write("Ŀǰϵͳ��û���˱��������ʹ�������Ȩ����\n");
                        return 1;
                }

                msg = "Ŀǰϵͳ�б�������Զ���ʹ��������û��У�\n";
                msg += implode(gr, "��") + "��\n";
                write(msg);
                return 1;
        }

        arg = replace_string(arg, ";", " ");
        arg = replace_string(arg, ",", " ");
        opts = explode(arg, " ");
        for (i = 0; i < sizeof(opts); i++)
        {
                if (opts[i] == "")
                        continue;

                if (opts[i] == "-c") opt_clear = 1; else
                if (opts[i] == "-d") opt_del   = 1; else
                if (! stringp(user)) user = opts[i]; else
                if (file_size("/grant/" + opts[i]) < 0)
                        return notify_fail("��μ�/grant�����"
                                           "����Ȩ���Ŀǰ��û�� " + opts[i] +
                                           " �����Ŀ��\n");
                else continue;

                opts[i] = 0;
        }

        opts -= ({ 0, "" });
        if (! stringp(user))
                return notify_fail("��Ҫ��˭��Ȩ��\n");

        ob = find_player(user);

        if (opt_clear)
        {
                // ���ĳһ��������е�Ȩ��
                write("����� " + user + " ���������������ʹ��Ȩ�ޡ�\n");
                if (SECURITY_D->remove_grant(user, "*") && objectp(ob))
                        tell_object(ob, HIG + me->name(1) + "�ջ������������������ʹ��Ȩ�ޡ�\n");
                SECURITY_D->save();
                return 1;
        }

        if (! sizeof(opts))
        {
                // ��ʾһ��������е�Ȩ��
                gr = SECURITY_D->query_grant(user);
                if (! arrayp(gr) || sizeof(gr) < 1)
                {
                        write("Ŀǰ " + user + " ��û�б������κ�����ʹ��Ȩ�ޡ�\n");
                        return 1;
                }

                msg = "Ŀǰ " + user + " ���������ʹ��Ȩ���У�\n";
                for (i = 0; i < sizeof(gr); i++)
                {
                        msg += WHT + gr[i] + NOR;
                        if (i < sizeof(gr) - 1)
                        {
                                msg += "��";
                                if ((i + 1) % 8 == 0) msg += "\n";
                        }
                }
                msg += "��\n";
                write(msg);
                return 1; 
        }

        for (i = 0; i < sizeof(opts); i++)
        {
                if (opt_del)
                {
                        if (! is_root(me))
                                message_system(me->name(1) + "�ջ��� " + user +
                                               " ʹ�� " + opts[i] + " ��Ȩ�ޡ�\n");
                        write("����� " + user + " ʹ�� " + opts[i] +
                              " ��Ȩ�ޡ�\n");
                        if (SECURITY_D->remove_grant(user, opts[i]) && objectp(ob))
                                tell_object(ob, HIG + me->name(1) +
                                            "�ջ����� " + opts[i] +
                                            " ��Ȩ�ޡ�\n");
                } else
                {
                        if (! is_root(me))
                                message_system(me->name(1) + "���� " + user +
                                               " ʹ�� " + opts[i] + " ��Ȩ�ޡ�\n");
                        write("������ " + user + " ʹ�� " + opts[i] +
                              " ��Ȩ�ޡ�\n");
                        if (SECURITY_D->grant(user, opts[i]) && objectp(ob))
                                tell_object(ob, HIG + me->name(1) +
                                            "�������� " + opts[i] +
                                            " ��Ȩ�ޡ�\n");
                }
        }

        // ������Ȩ��Ϣ
        SECURITY_D->save();

        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: grant [-d | -c] <���> <����> <����> ....

��һ�������Ȩʹ��ĳЩ�����Ȼ������ұ����ܹ����е���Щ��
��ſ��ԣ����Ⲣ�������е����������Ȩ�ģ�������Բμ�Ŀ¼
/grant������ļ���

ʹ�� -d ��������ȥ��һ����Ҷ�ĳЩ�����ʹ��Ȩ�ޣ�ʹ�� -c ��
����������һ����������Ѿ������ʹ��Ȩ�ޡ�

�������<���>���ⲻ���κ����������ѡ�����������ʾ�����Ŀ
ǰ����Ȩ״����

���û���κβ���������ʵ��ǰϵͳ�б���Ȩ����ʹ���ߡ�����Բ�
ѯ /grant Ŀ¼�µ��ļ��˽�����Щ�������ͨ����Ȩʹ�á�ע�⣺
��Ȩֻ���ø�ʹ���߿���ʹ�ø�������Ǿ����ܷ�ʹ�û�Ҫ������
�����ڵ�λ�á�

�����������Ȩ����Ϣ��enable

HELP );
        return 1;
}

