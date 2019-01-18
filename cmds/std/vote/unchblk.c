// vote unchblk
#include <vote.h> 
#include <ansi.h>
#include <net/dns.h>

inherit F_CONDITION;

int clear_vote(object victim);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;       // valid voter numbers
  int vc;       // vote count;
  int df;
  string channel;
  string *juror, my_id;
  string my_name, v_name;

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
  {
        return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");
  }

  if(victim->query("channel/chblk_on"))
  {
        channel = "��̸";
  } else if(victim->query("channel/chblk_party"))
  {
        channel = "����";
  } else if(victim->query("channel/chblk_chat"))
  {
        channel = "����";
  } else if (victim->query("channel/chblk_rumor")) 
  {
        channel = "ҥ��";
  } else if (victim->query("channel/chblk_es")) 
  {
        channel = "����";
  } else if (victim->query("channel/chblk_club")) 
  {
        channel = "���";
  } else if (victim->query("channel/chblk_new")) 
  {
        channel = "����";
  } else if (victim->query("channel/chblk_sldh")) 
  {
        channel = "ˮ½���";
  } else return notify_fail(victim->name()+"��Ƶ���Ѿ��Ǵ򿪵��ˡ�\n");
  

  if (reason <= 0)
  {
        victim->set("vote/reason", (int)V_UNCHBLK); 
  }
  
  my_id = me->query("id");

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
        victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 ) 
  {
        victim->set("vote/juror", juror+({ my_id }) );
  } else
  {
        me->add("vote/abuse", 10);
        return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
  }

  vv = (int) ("/cmds/std/vote")->valid_voters(me)/10;
  vc = victim->add("vote/count", 1);

  df = vv - vc;
  if (vv < 10) df = 10 - vc;
  
  my_name = me->name(1);
  if (me == victim) v_name = "�Լ�";
        else  v_name = victim->name(1);

  if (df>0)
  {
        shout( HIW "�������"+my_name+"ͶƱ��"+v_name+"("+capitalize(victim->query("id"))+")"+"��"+channel+"Ƶ��������"
                        +chinese_number(df)+"Ʊ��\n" NOR);
        write( HIW "�������"+my_name+"ͶƱ��" +v_name +"��"+channel+"Ƶ��������"
                        +chinese_number(df)+"Ʊ��\n" NOR);
    
        victim->apply_condition("vote_clear", 10);
                                
  } else 
  {
        if (me != victim)
        {
        shout( HIW "�������"+my_name+"ͶƱ��"+v_name+"("+capitalize(victim->query("id"))+")"+"��"+channel+"Ƶ����"
                +v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
        write( HIW "�������"+my_name+"ͶƱ��" +v_name+"��"+channel+"Ƶ����"
                +v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
        } else 
        {
        shout( HIW "�������"+my_name+"ͶƱ���Լ���"+channel+"Ƶ����"
                +my_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
        write( HIW "�������"+my_name+"ͶƱ���Լ���"+channel+"Ƶ����"
                +my_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
        }               
        
        victim->delete_condition("maren");
        victim->apply_condition("vote_clear", -10);
  } 
        victim->delete("channel");
  
  return 1;
}

