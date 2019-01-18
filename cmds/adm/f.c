// f.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string msg;
        string target;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if (! arg) return notify_fail("��Ҫ����˭��ʲô��\n");

        if (sscanf(arg, "%s %s", target, arg) != 2 ||
            ! objectp(ob = find_player(target)) &&
            ! objectp(ob = present(target, environment(me))))
        {
                // û��������󣬲鿴���һ�εĿ��ƶ���
                if (! objectp(ob = me->query_temp("last_control")))
                        return notify_fail("����û������˿ɹ�����ơ�\n");
                if (stringp(target)) arg = target + " " + arg;
        }

        if (ob == me)
                return notify_fail("�����Լ���....�����̫��������\n");

        if (wiz_level(me) <= wiz_level(ob) &&
            wiz_level(ob) && ! is_root(me))
                return notify_fail("�㲻�ܿ���Ȩ�ޱ��Լ��ߵ���ʦ��\n");

        me->set_temp("last_control", ob);
        ob->delete_temp("notify_fail");
        if (! ob->force_me(arg))
        {
                if (! stringp(msg = ob->query_temp("notify_fail")))
                        msg = ob->name(1) + "�޷�ִ��������\n";
                write(msg);
        }

        return 1;
}

int help(object me)
{
        write( @HELP
ָ���ʽ: f <sb> do sth.

���ָ�������������һ��������ж��������������������ĳ���ˣ�
��ô�Ժ���Ҫ���������ID��
HELP );
        return 1;
}

