// Modified By Longer 
 
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
        set("name",""); 
        remove_call_out("choose_npc"); 
        call_out("choose_npc",10); 
} 
 
void choose_npc() 
{ 
        int i, j ,k,ppl; 
        object *list, newob; 
        string str,m_name; 
        list = users(); 
        i = sizeof(list); 
 
        if (i < 5){ 
        remove_call_out("choose_npc"); 
        call_out("choose_npc",120); 
        return; 
        } 
 
        j = random(sizeof(families)); 
        k = random(sizeof(families)); 
        while( i-- ) { 
                if (!wizardp(list[i]) && list[i]->query("family/family_name") == families[j] 
                && (list[i]->query("combat_exp") + list[i]->query("daoxing"))> 20000 ) 
 
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
                        m_name="��������(Master puti)";// 
                        break; 
                case "�¹�": 
                        m_name="����ĸ(Xi wangmu)";// 
                        break; 
                case "���޵ظ�": 
                        m_name="�ز�������(Dizang pusa)";// 
                        break; 
                case "�ݿ�ɽ�޵׶�": 
                        m_name="����(Yu shu)";// 
                        break; 
                case "������": 
                        m_name="�׷�����(lao ren)";// 
                        break; 
                case "���ƶ�": 
                        m_name="�Ʒɻ�(huang feihu)";// 
                        break; 
                case "��ѩɽ": 
                        m_name="��������(Dapeng mingwang)";// 
                        break; 
                case "��ׯ��": 
                        m_name="��Ԫ����(Zhenyuan daxian)"; 
                        break; 
                case "�Ϻ�����ɽ": 
                        m_name="��������(Guanyin pusa)";// 
                        break; 
                case "��������": 
                        m_name="����(Ao guang)";// 
                        break; 
                case "��˿��": 
                        m_name="��ϼ����(zixia xianzi)";// 
                        break; 
                case "��ɽ����": 
                        m_name="��ɽ��ʥ(jian sheng)";//                              
                        break; 
                case "����ɽ": 
                        m_name="������ʦ(Chunyang tianshi)";// 
                        break; 
                case "��ԯ��Ĺ": 
                        m_name="Ů�";// 
               
        } 
        if (ppl) 
        { 
        if (j != k) 
        message("system",HIG"��"+HIR+families[k]+HIG+"��"+HIW+m_name+HIG"����"+chinese_number(ppl)+"��"+families[j]+"�̿����ڱ������£��ڵ����ٻػ�����\n"NOR,users()); 
        else 
        message("system",HIG"��"+HIR+families[k]+HIG+"��"+HIW+m_name+HIG"������"+chinese_number(ppl)+"����Т���ӣ���ʦ���棬�ڵ����ٻػ�����\n"NOR,users()); 
        remove_call_out("choose_npc"); 
        call_out("choose_npc",300); 
        } 
        else 
        { 
        message("system",HIG"��������Ե��Ů����������һ��̾�˿�����\n"NOR,users()); 
        message("system",HIG"��������Ե��Ů�����(nu wa)����������,һ�����,һ���滨!\n"NOR,users()); 
        remove_call_out("choose_npc"); 
        call_out("choose_npc",60); 
        } 
} 
 

