// choose.c
// modify by mudring

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "��ѩɽ", "����ɽ���Ƕ�", "�¹�",
  "�Ϻ�����ɽ", "���޵ظ�", "��˿��",
  "������", "��������", "�ݿ�ɽ�޵׶�",
  "��ׯ��", "���ƶ�", "��ɽ����",
  "����ɽ", "��ԯ��Ĺ",
});

int filter_user(object ob, string family)
{
    if (!ob || wizardp(ob))
        return 0; 

    if (ob->query("family/family_name") != family)
        return 0;

    if (ob->query("combat_exp") < 80000)
        return 0;

    return 1;
}

void choose_mpc()
{
    int i, j ,k,ppl;
    object *list, newob;
    string m_name;

    j = random(sizeof(families));
    k = random(sizeof(families));
    m_name = STATU_D->family_master(families[k]);
    list = filter_array(users(), (: filter_user :), families[j]);
    i = sizeof(list);
    while (i--)
    {
        newob = new(__DIR__"npc");
        newob->set("target",families[k]);
        if (newob->invocation(list[i], k ))
            ppl++;
        else
            destruct(newob);
    }

    if (ppl)
    {
        if (j != k)
            message_job(HIW+m_name+HIG"����"+chinese_number(ppl)
                        +"��"+families[j]+"�̿����ڱ������£��ڵ����ٻػ�����");
        else
            message_job(HIW+m_name+HIG"������"+chinese_number(ppl)
                        +"����Т���ӣ���ʦ���棬�ڵ����ٻػ�����");
    } else
    {
        message_job( HIR"�����ֻص� ���"+HIG"(Piao miao)��ң���������������ң���ڡ�");
        message_job( HIR"����ư�� ��ϼ"+HIG"(Hong xia)��������ϼ����Ϧ��ͤ��С�������⡣");
    }
}

