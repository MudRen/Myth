
// which.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
      string file;

        if(!arg)
                return notify_fail("ָ���ʽ��which <����>\n");
      file=me->find_command(arg);
        if(!file)
                write("û���ҵ� "+arg+" ������\n");
        else
                write(file+"\n" );
        return 1;
}
int help()
{
        write(@TEXT
ָ���ʽ��which <����>
���ָ������ҵ�ĳ��������ʲôĿ¼��
TEXT
        );
        return 1;
}

