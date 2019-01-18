// cd.c
// modify by mudring

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string dir;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        if (! arg)
                arg = user_path(me->query("id"));
        dir = resolve_path(me->query("cwd"), arg);

        seteuid(geteuid(me));
        if (file_size(dir) != -2)
                return notify_fail("û�����Ŀ¼��\n");

                if (dir != "/")
        if (! MASTER_OB->valid_read(dir, me, "cd"))
                return notify_fail("��û��Ȩ�޷��ʸ�Ŀ¼��\n");

        if(dir[strlen(dir)-1]!='/') dir += "/";
        me->set("cwd", dir);
        write("��ǰĿ¼���Ϊ��" + dir + "\n");
        return 1;       
}

int help(object me)
{
        write(@HELP
ָ���ʽ : cd <��Ŀ¼��>, cd .. , and cd

��Ŀǰ�ο���Ŀ¼����ָ������Ŀ¼��ص���һ��Ŀ¼; ���ֱ�ӻص��Լ�����Ŀ¼��
HELP );
        return 1;
}

