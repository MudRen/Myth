// feizei.c
// rewritten by mudring

#include <ansi.h>

inherit F_DBASE;

string *dirs = ({
    "/d/xueshan",
    "/d/lingtai",
    "/d/moon",
    "/d/nanhai",
    "/d/death",
    "/d/pansi",
    "/d/jjf",
    "/d/sea",
    "/d/gumu",
    "/d/qujing/wudidong",
    "/d/qujing/wuzhuang",
    "/d/qujing/kusong",
    "/d/qujing/shushan",
    "/d/qujing/changan",
    "/d/qujing/wuji",
    "/d/qujing/baoxiang",
    "/d/qujing/tianzhu",
    "/d/qujing/nuerguo",
    "/d/qujing/yuhua",
});

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

string *feizei = ({
    "fei-putuo",     "fei-moon",    "fei-wzg",
    "fei-shushan",   "fei-hyd",     "fei-fangcun",
    "fei-hell",      "fei-jjf",     "fei-pansi",
    "fei-dragon",    "fei-xueshan", "fei-wudidong",
});

void choose_npc()
{
    int i, j;
    object newob;
    string m_name;
    string smp;
    string where;

    smp  = "������ɽ֮��";
                   
    j = random(sizeof(families));
    newob = new(__DIR__+feizei[random(sizeof(feizei))]);
    newob->set("target", families[j]);
    newob->copy_status(newob);
    NPC_D->place_npc(newob, dirs);
    where = newob->query("place");
    reset_eval_cost();
        
    switch(families[j])
    {
    case "����ɽ���Ƕ�":
        m_name="��������";//
        newob->carry_object(__DIR__"obj/stick");
        break;
    case "�¹�":
        m_name="����ĸ";//
        newob->carry_object(__DIR__"obj/whip");
        break;
    case "���޵ظ�":
        m_name="�ز�������";//
        newob->carry_object(__DIR__"obj/whip");
        break;
    case "�ݿ�ɽ�޵׶�":
        m_name="����";//
        newob->carry_object(__DIR__"obj/blade");
        break;
    case "������":
        m_name="�׷�����)";//
        newob->carry_object(__DIR__"obj/axe");
        break;
    case "���ƶ�":
        m_name="�Ʒɻ�";//
        newob->carry_object(__DIR__"obj/spear");
        break;
    case "��ѩɽ":
        m_name="��������";//
        newob->carry_object(__DIR__"obj/qin");
        break;
    case "��ׯ��":
        m_name="��Ԫ����";
        if (random(2)) 
            newob->carry_object(__DIR__"obj/staff");
        else
            newob->carry_object("/d/obj/drug/renshen-guo");
        break;
    case "�Ϻ�����ɽ":
        m_name="��������";//
        newob->carry_object(__DIR__"obj/staff");
        break;
    case "��������":
        m_name="����";//
        newob->carry_object(__DIR__"obj/fork");
        break;
    case "��˿��":
        m_name="��ϼ����";//
        newob->carry_object(__DIR__"obj/whip");
        break;
    case "��ɽ����":
        m_name="��ɽ��ʥ";//
        newob->carry_object(__DIR__"obj/sword");
        break;
    case "���ƻʹ�":
        m_name="��̫��";//
        newob->carry_object(__DIR__"obj/mace");
        smp = "���ƹ���";
        break;
    case  "�ڼ���":
        m_name="�ڼ�������";//
        newob->carry_object(__DIR__"obj/kui");
        smp = "�ڼ�������";
        break;
    case  "�����":
        m_name="���������";//
        newob->carry_object(__DIR__"obj/magua");
        smp = "���������";
        break;
    case  "���ù�":
        m_name="���ù�����";//
        newob->carry_object(__DIR__"obj/pifeng");
        smp = "���ù�����";
        break;
    case  "Ů����":
        m_name="Ů��������";//
        newob->carry_object(__DIR__"obj/ring");
        smp = "Ů��������";
        break;
    case  "����":
        m_name="��������";//
        newob->carry_object(__DIR__"obj/shoes");
        smp = "���ع���";
        break;
    }

    message_job(HIR"����׷ɱ�"HIW + m_name + HIG"�����������������"
                + smp + "�������Ӵ���" + where + "һ��,ɱ���⡣");
}

