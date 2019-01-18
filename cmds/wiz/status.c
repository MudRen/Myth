// status.c
// updated by doing

#include <localtime.h>

inherit F_CLEAN_UP;

int help(object me);

int filter_for_heart_beat(object ob);

int si;

int stat_fun(mapping st, object ob)
{
        string bn;

        bn = file_name(ob);
        sscanf(bn, "%s#%*d", bn);
        if (! st[bn]) st[bn] = 1; else st[bn]++;
        if (! (si++ & 0xFFF))
                reset_eval_cost();
        return 0;
}

int main(object me, string arg)
{
        object ob;
        string msg;
        mixed lt;
        mapping st;
        string bn;
        string *ks;
        object *obs;
        int i;

#if 0
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;
#endif

        seteuid(getuid());

        lt = localtime(time());
        msg = sprintf("%d/%d/%d  %d:%d:%d\n",
                      lt[LT_YEAR], lt[LT_MON] + 1, lt[LT_MDAY],
                      lt[LT_HOUR], lt[LT_MIN], lt[LT_SEC]);
        if (arg == "object")
        {
                st = ([]);
                si = 0;
                printf ("result = %O\n", sizeof(objects((: stat_fun, st :))));

                // ѡ�����Ƴ��� 50 ������Ʒ
                reset_eval_cost();
                ks = keys(st);
                ks = filter_array(ks, (: $(st)[$1] >= 50 :));

                // ����
                reset_eval_cost();
                ks = sort_array(ks, (: $(st)[$2] - $(st)[$1] :));

                // ѡ��ǰ100��
                msg += "Ŀǰϵͳ���� " + si +
                       " ����Ʒ�����и��ƶ��󳬹� 50 ������Ʒ���£�\n";
                for (i = 0; i < sizeof(ks) && i < 100; i++)
                        msg += sprintf("%3d. %-40s %d\n",
                                       i + 1, ks[i], st[ks[i]]);
                me->start_more(msg);
                return 1;
        }

        obs = objects((: filter_for_heart_beat :));
        msg += (string)mud_status(arg == "detail" ? 1 : 0);
        msg += sprintf("Object with heart beating: %d\n", sizeof(obs));
        if (arg == "detail")
                msg += sprintf("%O\n", obs);
        me->start_more(msg);

        return 1;

}

int filter_for_heart_beat(object ob)
{
        return query_heart_beat(ob);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : status [detail | object]

���ô�ָ��ɵ�֪�й�ϵͳ����Ϣ��
HELP );
        return 1;
}

