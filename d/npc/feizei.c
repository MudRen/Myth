// Fild��/d/npc/feizei.c
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
  "���ƻʹ�",
  "�ڼ���",
  "�����",
  "���ù�",
  "Ů����",
  "����",
});

string *feizei=({"fei-putuo","fei-moon","fei-wzg","fei-shushan","fei-hyd",
    "fei-fangcun","fei-hell","fei-jjf","fei-pansi","fei-dragon", "fei-xueshan",
     "fei-wudidong",});

void create()
{
        seteuid(getuid());
        set("channel_id","");
}

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str,m_name;
        string smp;
        smp  = "������ɽ֮��";
                   
        j = random(sizeof(families));
        k = random(sizeof(families));
        newob = new(__DIR__+feizei[random(sizeof(feizei))]);
        newob->set("target",families[k]);
        newob->invocation( j );
        reset_eval_cost();
        
        switch(families[k])
        {
                case "����ɽ���Ƕ�":
                        m_name="��������";//
                        newob->carry_object("/d/npc/obj/stick");
                        break;
                case "�¹�":
                        m_name="����ĸ";//
                        newob->carry_object("/d/npc/obj/whip");
                        break;
                case "���޵ظ�":
                        m_name="�ز�������";//
                        newob->carry_object("/d/npc/obj/whip");
                        break;
                case "�ݿ�ɽ�޵׶�":
                        m_name="����";//
                        newob->carry_object("/d/npc/obj/blade");
                        break;
                case "������":
                         m_name="�׷�����";//
                        newob->carry_object("/d/npc/obj/axe");
                           break;
                case "���ƶ�":
                        m_name="�Ʒɻ�";//
                        newob->carry_object("/d/npc/obj/spear");
                        break;
                case "��ѩɽ":
                        m_name="��������";//
                        newob->carry_object("/d/npc/obj/qin");
                        break;
                case "��ׯ��":
                        m_name="��Ԫ����";
                        if(random(2)) 
                           newob->carry_object("/d/npc/obj/staff");
                        else
                           newob->carry_object("/d/obj/drug/renshen-guo");
                        break;
                case "�Ϻ�����ɽ":
                        m_name="��������";//
                        newob->carry_object("/d/npc/obj/staff");
                        break;
                case "��������":
                        m_name="����";//
                        newob->carry_object("/d/npc/obj/fork");
                        break;
                case "��˿��":
                        m_name="��ϼ����";//
                        newob->carry_object("/d/npc/obj/whip");
                        break;
                case "��ɽ����":
                        m_name="��ɽ��ʥ";//
                        newob->carry_object("/d/npc/obj/sword");
                        break;
                case "���ƻʹ�":
                        m_name="��̫��";//
                        newob->carry_object("/d/npc/obj/mace");
                        smp = "���ƹ���";
                        break;
                case  "�ڼ���":
                        m_name="�ڼ�������";//
                        newob->carry_object("/d/npc/obj/kui");
                        smp = "�ڼ�������";
                        break;
                case  "�����":
                        m_name="���������";//
                        newob->carry_object("/d/npc/obj/magua");
                        smp = "���������";
                        break;
                case  "���ù�":
                        m_name="���ù�����";//
                        newob->carry_object("/d/npc/obj/pifeng");
                        smp = "���ù�����";
                        break;
                case  "Ů����":
                        m_name="Ů��������";//
                        newob->carry_object("/d/npc/obj/ring");
                        smp = "Ů��������";
                        break;
                case  "����":
                        m_name="��������";//
                        newob->carry_object("/d/npc/obj/shoes");
                        smp = "���ع���";
                        break;
                        
        }
          message_job( HIR+"����׷ɱ�"+HIW+m_name+HIG"�����������������"+smp+"�������Ӵ���"+families[j]+"һ��,ɱ���⡣");
}

