// reclaim.c

int main(object me, string arg)
{
    if (!SECURITY_D->valid_grant(me, "(arch)"))
        return 0;

/*
    write("������������� " + reclaim_objects() + " ��������\n");
*/
    CRON_D->auto_clear();
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : reclaim

�ô� : �������ڼ����������õı��������, �Լ��ټ������ʹ�á�
HELP
     );
     return 1;
}

