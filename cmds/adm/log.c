// log.c
// created by doing

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string wiz_status;
        mapping log;
        string *ks;
        object *obs;
        string msg;
        int i;
        int flag;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if (! arg || arg == "")
                return notify_fail("����ָ��һ����ҡ�\n");

        seteuid(getuid());
        if (arg == "?")
        {
                log = EXAMINE_D->query("log_by");
                msg = "";
                if (mapp(log) && sizeof(log) > 0)
                {
                        ks = keys(log);
                        flag = 0;
                        for (i = 0; i < sizeof(ks); i++)
                        {
                                if (wiz_level(me) < wiz_level(log[ks[i]]))
                                        continue;

                                if (! flag)
                                {
                                        msg +=HIW "\nĿǰ��¼��������£�\n"
                                              HIY "������������������������������������������������\n" NOR;
                                        flag = 1;
                                }
                                msg += sprintf("%s%-14s  Ŀǰ��  %-14s ��¼��־��\n" NOR,
                                        (wizhood(me) == "(player)") ? CYN : HIY,
                                        ks[i], log[ks[i]]);
                        }
                }

                obs = filter_array(users(), (: $1->is_loging_now() :));
                obs = sort_array(obs, (: wiz_level($1) - wiz_level($2) :));
                flag = 0;
                for (i = 0; i < sizeof(obs); i++)
                {
                        string nid;

                        if (! flag)
                        {
                                msg += HIW "\nĿǰ���ڼ�¼��ʹ����������£�\n"
                                       HIY "������������������������������������������������\n" NOR;
                                flag = 1;
                        }

                        nid = obs[i]->name(1) + "(" + obs[i]->query("id") + ")";
                        msg += sprintf("%s%-20s  " HIC "%-10s  %s\n" NOR,
                                       wizardp(obs[i]) ? HIY : CYN,
                                       nid,
                                       environment(obs[i]) ? environment(obs[i])->short() : "δ֪�ص�",
                                       interactive(obs[i]) ? HIG + query_ip_name(obs[i]) : HIR "����");
                }
                if (! flag)
                        msg += "Ŀǰû��������ұ���¼��־��\n";
                else
                        msg += "\n";
                write(msg);
                return 1;
        }

        if (file_size(DATA_DIR + "login/" + arg[0..0] + "/" + arg + __SAVE_EXTENSION__) < 0)
                return notify_fail("��... û�������Ұ���\n");

        if (wiz_level(me) < wiz_level(arg))
                return notify_fail("�㲻��Ϊ�Լ�Ȩ�޸ߵ��˼�¼��־��\n");

        if (wizhood(arg) == "(admin)" && getuid(me) != "mudring")
                return notify_fail("�㲻�ܼ�¼�������־��\n");

        if (EXAMINE_D->start_log_player(arg, me->query("id")))
        {
                write("��ʼ��¼(" + arg + ")����־��\n");
                return 1;
        }

        return 0;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: log <player> | ?
 
��¼ <player> ����־����־�ļ������� /log/user/player ���档
���û������ֹͣ��¼����ҵ���־��ϵͳ��һֱ��¼��ȥ����ʹ
�˳����������߽���Ҳ����ֹͣ��

������� ? ��Ϊ�������г���ǰ��¼�������
 
HELP );
        return 1;
}

