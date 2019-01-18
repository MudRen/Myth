// cost.c
// updated by doing

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping before, after;
        int eval_cost;
        mapping info, linfo;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        seteuid(getuid());
        if (! arg) return notify_fail("ָ���ʽ��cost <ָ��> [<����> ....]\n");

        info = rusage();
        eval_cost = eval_cost();
        me->force_me(arg);
        eval_cost -= eval_cost();
        linfo = rusage();

        write(sprintf(WHT "Eval cost��%d ��λ  CPU time = %d+%d ����\n" NOR,
                      eval_cost,
                      linfo["utime"] - info["utime"],
                      linfo["stime"] - info["stime"]));
        return 1;
}

int help()
{
        write( @TEXT
ָ���ʽ��cost <ָ��> [<����> .... ]

���ָ�����������һ��ָ��ִ�������ʱ�䡣
TEXT );
        return 1 ;
}

