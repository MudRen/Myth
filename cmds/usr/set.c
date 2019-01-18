// set.c
 
#define MAX_ENV_VARS      20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only, *allowed;
    mixed data;
    mapping env;
 
    wiz_only = ({"invisibility", "immortal"});
    allowed = ({
        "block_tell", "brief", "brief_message", "brief_all",
        "no_accept", "no_teach", "wimpy", "public","allow_map",
        "no_tune","no_automete", "combatd","qq_no","qq_talk","qq_renzheng",
        "fengbo-cha", "destination", "prompt"
        });
 
    env = me->query("env");
 
    if (!arg || arg=="")
    {
        write("��Ŀǰ�趨�Ļ��������У�\n");
        if (!mapp(env) || !sizeof(env))
            write("\tû���趨�κλ���������\n");
        else
        {
            terms = keys(env);
            for(i=0; i<sizeof(terms); i++)
                printf("%-20s  %O\n", terms[i], env[terms[i]]);
        }
        return 1;
    }
 
    if (sscanf(arg, "%s %s", term, data) != 2)
    {
          term = arg;
          data = "YES";
    }

    if (!wizardp(me) && strlen(data) > 10 ) return notify_fail ("�������̫���ˡ�\n");
    if (!wizardp(me) && strlen(term) > 20 ) return notify_fail ("�������̫���ˡ�\n");
 
    if (term && term != "")
    {
        if (mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS)
            return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");
        sscanf(data, "%d", data);

    if (!wizardp(me)
        && (member_array(term, allowed) == -1))
        return notify_fail("��ֻ���趨 help settings �ж�����Ļ���������\n");

    if (term == "wimpy" && (!intp(data) || data < 0 || data > 80))
    {
        return COMMAND_DIR"usr/wimpy"->help(me);
    }

    if (term == "combatd" && (!intp(data) || data < 0 || data > 4))
    {
        return notify_fail("combatd��ֵֻ������Ϊ0-4֮������֡�\n");
    }

    me->set("env/" + term, data);
    printf("�趨����������%s = %O\n", term, data);

    return 1;
  }
  return help();
}
 
int help()
{
  write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"��
 
ȡ�������趨���� unset ָ�
 
��������Щ�������������趨����� help settings��
TEXT
  );
  return 1;
}

