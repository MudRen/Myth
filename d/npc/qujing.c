// Fild��/d/npc/qujing.c
// Changed to heart_beat() by mudring@sjsh......

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "�ڼ���",
  "�����",
  "���ù�",
  "Ů����",
  "����",
  "��ƽ��",
  "��ׯ��",
  "������",
  "�շ���",
  "�����",
  "���Ϲ�",
  "���ٹ�",
  "���޹�",
  "����ׯ",
  });

void create()
{
        seteuid(getuid());
        set("channel_id","");

}

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str;
        object ts,swk,zbj,shs;               

        k = random(sizeof(families));        
        ts = new(__DIR__"ts");
        ts->set("target",families[k]);
        ts->invocation(k);
        message_job( HIW+"��������"+HIG"������! ��˵��������ʦͽ�Ѿ�����"+families[k]+"�ˣ����Ų��þͻᵽ����ɽ�ˡ�");
        reset_eval_cost();
}

  
