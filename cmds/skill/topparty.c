// top.c

#include <ansi.h>

inherit F_CLEAN_UP;


// ��������(�Ӹߵ���)
int sort_party(string f1, string f2, mapping fame)
{
        return fame[f2] - fame[f1];
}

int main(object me, string arg)
{
        mapping last, fame;
        string *fam;
        string msg;
        int delta;
        int i;

        if (! arg || arg == "party")
        {
                fame = PARTY_D->query_party_fame();
                last = PARTY_D->query_all_last_party_fame();
        
                fam = keys(fame) - ({ 0 });
                if (sizeof(fam) < 1)
                        return notify_fail("Ŀǰ������û��ʲô"
                                           "�����İ�ᡣ\n");

                fam = sort_array(fam, (: sort_party :), fame);
        
                msg = WHT "Ŀǰ������������������״��\n" NOR
                      HIY "��������������������������������\n" NOR;
                for (i = 0; i < sizeof(fam) && i < 30; i++)
                {
                        delta = fame[fam[i]] - last[fam[i]];
                        msg += sprintf("%2d. %-12s  %-9d(%s%d%s)\n",
                                       i + 1, fam[i], fame[fam[i]],
                                       (delta > 0) ? HIY "+" :
                                       (delta < 0) ? HIR : WHT,
                                       delta, NOR);
                }
        
                msg += HIY "��������������������������������\n" NOR
                       WHT "�г���" + chinese_number(i) + "����ᡣ\n" NOR;
        } else
                return notify_fail("��Ҫ��ʲô���а�\n");

        write(msg);
        return 1;
}

int help(object me)
{
   	write(@HELP
ָ���ʽ: top

�鿴Ŀǰ�������������ɵ�����״�������ȥ��仯
�ĳ̶ȡ�
HELP );
   	return 1;
}
