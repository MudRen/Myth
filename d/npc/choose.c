// Fild��/d/npc/choose.c
// Changed to heart_beat() by mudring@sjsh......

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "��ѩɽ",
  "����ɽ���Ƕ�",
  "�¹�",
  "�Ϻ�����ɽ",
  "���޵ظ�",
  "��˿��",
  "������",
  "��������",
  "�ݿ�ɽ�޵׶�",
  "��ׯ��",
  "���ƶ�",
  "��ɽ����",
  "����ɽ",
  "��ԯ��Ĺ",
});

void create()
{
        seteuid(getuid());
        set("channel_id","");
//
       call_out("start",5);
}
void start()
{
        this_object()->apply_condition("ximo_choose",360);
     this_object()->choose_mpc();
}

void choose_mpc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str,m_name;
        list = users();
        i = sizeof(list);

        if (i < 10) return;

        j = random(sizeof(families));
        k = random(sizeof(families));
        while( i-- ) {
                if (!wizardp(list[i]) && list[i]->query("family/family_name") == families[j]
                && (list[i]->query("combat_exp") + list[i]->query("daoxing"))> 80000 )

                {
                newob = new(__DIR__"npc");
                newob->set("target",families[k]);
                if(newob->invocation(list[i], k ))
                ppl++;
                else
                destruct(newob);
                }
        }
        
        reset_eval_cost();
        
        switch(families[k])
        {
                case "����ɽ���Ƕ�":
                        m_name="��������";//
                        break;
                case "�¹�":
                        m_name="����ĸ";//
                        break;
                case "���޵ظ�":
                        m_name="�ز�������";//
                        break;
                case "�ݿ�ɽ�޵׶�":
                        m_name="����";//
                        break;
                case "������":
                        m_name="�׷�����";//
                        break;
                case "���ƶ�":
                        m_name="�Ʒɻ�";//
                        break;
                case "��ѩɽ":
                        m_name="��������";//
                        break;
                case "��ׯ��":
                        m_name="��Ԫ����";
                        break;
                case "�Ϻ�����ɽ":
                        m_name="��������";//
                        break;
                case "��������":
                        m_name="����";//
                        break;
                case "��˿��":
                        m_name="��ϼ����";//
                        break;
                case "��ɽ����":
                        m_name="��ɽ��ʥ";//                             
                        break;
                case "����ɽ":
                        m_name="������ʦ";//
                        break;       
                case "��ԯ��Ĺ":
                        m_name="Ů�";//
                        break;
        }
        if (ppl)
        {
        if (j != k)
//103          message("channel:job",HIG"��"+HIR+families[k]+HIG+"��"+HIW+m_name+HIG"����"+chinese_number(ppl)+"��"+families[j]+"�̿����ڱ������£��ڵ����ٻػ�����\n"NOR,users());
        message_job( HIW+m_name+HIG"����"+chinese_number(ppl)+"��"+families[j]+"�̿����ڱ������£��ڵ����ٻػ�����");
        else
//106          message("channel:job",HIG"��"+HIR+families[k]+HIG+"��"+HIW+m_name+HIG"������"+chinese_number(ppl)+"����Т���ӣ���ʦ���棬�ڵ����ٻػ�����\n"NOR,users());
        message_job( HIW+m_name+HIG"������"+chinese_number(ppl)+"����Т���ӣ���ʦ���棬�ڵ����ٻػ�����");
        }
        else
        {
        message_job( HIR"�����ֻص� ���"+HIG"(Piao miao)��ң���������������ң���ڡ�");
        message_job( HIR"����ư�� ��ϼ"+HIG"(Hong xia)��������ϼ����Ϧ��ͤ��С�������⡣");
        }
}

