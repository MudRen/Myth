// reclaim.c

int main(object me, string arg)
{
    int mem;
    object *ob;

    if (!SECURITY_D->valid_grant(me, "(arch)"))
        return 0;

    write("������������� " + reclaim_objects() + " ��������\n");

    ob = filter_array(objects(), (: clonep :));
    mem = sizeof(ob);
    while (mem--)
    if (!environment(ob[mem]) &&
        !interactive(ob[mem]) &&
        !ob[mem]->query_temp("body_ob"))
    {
        reset_eval_cost();
        printf("%O\n", ob[mem]);
        destruct(ob[mem]);
        ob -= ({ 0 });
        mem = sizeof(ob);
    }

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


