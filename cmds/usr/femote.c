/*
 * modify name to femote.c
 * make code less
 * by ken@XAJH
 */

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        mapping emote;
        string *e, *loop;
        string syntax;
        int l;
        string result="", msg;
        int count=0;

        loop = ({ "others_target", "others_self", "others" });
        if (! arg)
                return help(me);

        if (time() - me->query_temp("scan_time") < 20 &&
            ! wizardp(me))
                return notify_fail("�ȵȣ�ϵͳ������......\n");

        syntax = replace_string(arg, "%", "");
        l = -1;
        while (l != strlen(syntax))
        {
                l = strlen(syntax);
                syntax = replace_string(syntax, "**", "*");
        }
        syntax = replace_string(syntax, "*", "%*s");
        if (syntax[0..2] != "%*s") syntax = "%*s" + syntax;
        if (syntax[strlen(syntax)-3..<1] != "%*s") syntax = syntax + "%*s";

        foreach (e in sort_array(EMOTE_D->query_all_emote(), 1))
        {
                emote = EMOTE_D->query_emote(e);
                for (int j = 0; j < sizeof(loop); j++ )
                {
                        msg = emote[loop[j]];
                        if (msg && sscanf(msg, syntax))
                        {
                                result += sprintf(HIR "%s\n"+NOR+"����: %s\n", e, msg);
                                count++;
                                if (count > 200)
                                        return notify_fail("���ҵ��ķ�������"
                                                "�� emote ̫�࣬������ָ����"
                                                "���ֽ���������\n");
                        }
                }
        }

        if (result == "")
                return notify_fail(LOCAL_MUD_NAME() + "���޷��ϲ�ѯ������ emote��\n");
        else
                result = "\n��ѯ���"
                         "\n------------------------------------------------------------\n"
                                + result;
        result = replace_string(result, "$n", "ĳ��");
        result = replace_string(result, "$N", me->name(1));
        result = replace_string(result, "$P", "��");
        result = replace_string(result, "$p", "(��/��)");
        result = replace_string(result, "$S", RANK_D->query_self(me));
        result = replace_string(result, "$s", RANK_D->query_self_rude(me));
        result = replace_string(result, "$R", "׳ʿ");
        result = replace_string(result, "$r", "����");
        result = replace_string(result, "$C", "������");
        result = replace_string(result, "$c", "���");

        result += "------------------------------------------------------------\n";
        result += sprintf("��%s�У�������%s���� emote ���� %d ����\n",
                          LOCAL_MUD_NAME(), arg, count);
        me->set_temp("scan_time",time());
        me->start_more(result);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : femote �ؼ���
���ܣ��г�Ŀǰ���к�ָ���ؼ��ֵ� emote�����磺

femote *����һ�ţ���������*��* ����
femote ����һ

ֻҪƥ�䵽��femoteָ���Ĺؼ��֣�������һ������������ƥ���
�ַ�����ʹ����"*"�� ����ƥ���κε��ʡ����ҵ�ʱ�����е�����Ӧ
��ת����"*"��

Dean, ken@XAJH
HELP );
    return 1;
}

