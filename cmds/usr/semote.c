// semote.c

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

#include "/cmds/skill/valid_system.h"
int filter_emote(string emote, int d);
int sort_emote(string e1, string e2);

int main(object me, string arg)
{
        string *e, str;
        int i;
        int d;

    if (!valid_system(me)) return 0;
        d = 0;
        e = EMOTE_D->query_all_emote();
        if (arg == "-r" || arg && sscanf(arg, "-r %d", d))
        {
                str = HIM "����ʱ��˳����ʾ" + LOCAL_MUD_NAME();
                if (d)
                {
                        str += "���" + chinese_number(d) + "�����ӵı��鶯��";
                        d *= 86400;
                        e = filter_array(e, (: filter_emote :), d);
                } else
                {
                        str += "���еı��鶯��";
                        e = sort_array(e, (: sort_emote :));
                }
                str += "\n" NOR;
        } else
        {
                str = HIW + LOCAL_MUD_NAME() + "���鶯���ܻ�\n" NOR;
                e = sort_array(EMOTE_D->query_all_emote(), 1);
        }
        str += "��������������������������������������������������������������������������\n";
        for(i=0; i<sizeof(e); i++)
                str += sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
        me->start_more(str);
        write("\n");
        return 1;
}

int filter_emote(string emote, int d)
{
        int t;

        t = (int)(EMOTE_D->query_emote(emote)["time"]);
        return (time() - t > d) ? 0 : 1;
}

int sort_emote(string e1, string e2)
{
        int t1, t2;

        t1 = (int)(EMOTE_D->query_emote(e1)["time"]);
        t2 = (int)(EMOTE_D->query_emote(e2)["time"]);
        if (t1 == t2)
        {
                if (e1 > e2) return 1;
                return -1;
        }
        return t2 - t1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : semote [-r [n]]

���ָ������г�Ŀǰ����ʹ�õ�emote��������ʹ����
ѡ�� -r ����԰���ʱ��˳����ʾ���е�emote�����ѡ��
��������˲�������ֻ��ʾ��������д��emote��

����semote -r 1����ʾ���һ���±�д���޸ĵ�emote��
HELP
    );
    return 1;
}

