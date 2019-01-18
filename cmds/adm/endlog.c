// endlog.c
// created by doing

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string wiz_status;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if (! arg)
                return notify_fail("����ָ��һ����ҡ�\n");

        wiz_status = SECURITY_D->get_status(me);

        seteuid(getuid());

        if (EXAMINE_D->end_log_player(arg, me->query("id")))
        {
                write("ֹͣ��¼(" + arg + ")����־��\n");
                return 1;
        }

        return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: endlog <player>
 
ֹͣ��¼ <player> ����־����������ұ�����Ϊ���ü�¼��־��
��������ý�ȡ�������� admin��ֻ�еȼ������ڿ�ʼ��¼��־�ߵ�
��ʦ���ܹ�ȡ����¼��־��
 
HELP );
        return 1;
}

