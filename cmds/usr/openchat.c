// By Aeddy, 2004-1-4 20:40

#include <net/dns.h>
#include <ansi.h>
#include <vote.h> 
inherit F_CONDITION;


// int valid_voters(object me);

void create() { seteuid(getuid()); }
int clear_vote(object victim);
int valid_voters(object me);
int vote(object me, object victim);
int main(object me, string victim_name)
{
	object victim;

	if (((int)me->query("age")<16) && !wizardp(me))
	{
		return notify_fail("�������Ƕ�Ϸ��С����һ����ȥ��\n");
	}
	

/*
	if ((int)me->query("vote/deprived"))
	{
		return notify_fail("�����𵱳���Ū������������ͶƱȨ���£�׷��Ī����\n");
	}
*/
    if (!victim_name )
    {
		return notify_fail("����ʥ��һƱ��Ҫ������˲���Ͷ��\n");
    }
    
	
	victim = LOGIN_D->find_body(victim_name);
	if (!victim || !me->visible(victim))
		return notify_fail("��ҪͶ˭��Ʊ��\n");
          if (wizardp(victim))
            return notify_fail("��ûȨ������ʦͶƱ!\n");

	
    if (vote(me, victim) <= 0)
	{
/*		if ((int)me->query("vote/abuse")> 50)
		{
			write( HIG "����Ϊ����ͶƱ��ͶƱȨ�������ˣ�\n" NOR);
			me->set("vote/deprived", 1);
			me->apply_condition("vote_suspension", 120);
			me->delete("vote/abuse");

		}	
		*/
		return 0;
		
	};
	
	return 1;
}


int valid_voters(object me)
{
	object *list;
	int d = 0;
	int j;

    list = users();
    j = sizeof(list);
    while( j-- )
	{
		// Skip those users in login limbo.
        if( !environment(list[j]) ) continue;
        if( !me->visible(list[j]) ) continue;
		if (((int)list[j]->query("age")<16) && !wizardp(list[j])) continue;
		if ((int)list[j]->query("vote/deprived")) continue;
		
		d++;
	}
	
	return d;
}



int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  string channel;
  string *juror, my_id;
  string my_name, v_name;

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
  {
  	return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");
  }

 if(victim->query("channel/chblk_sldh"))
  {
	channel = "ˮ½���";
  } else if(victim->query("channel/chblk_chat"))
  {
	channel = "̸��˵��";
  }
   else if (victim->query("channel/chblk_sj")) 
  {
  	channel = "��������";
  }
  else if (victim->query("channel/tell_block"))
  {
//115          channel = "˵��"
     return notify_fail("˵��Ƶ������ͶƱ�����\n");
  }
  else if (victim->query("channel/chblk_rumor")) 
  {
     return notify_fail("ҥ�Դ�˵Ƶ������ͶƱ�����\n");
  }
    else return notify_fail(victim->name()+"��Ƶ���Ѿ��Ǵ򿪵��ˡ�\n");
  

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
  } else if(!wizardp(me))
  {
//	me->add("vote/abuse", 10);
  	return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
  }

  vv = (int) valid_voters(me)/10;
  vc = victim->add("vote/count", 1);

  df = vv - vc;
  if (vv < 4) df = 4 - vc;
  
  my_name = me->name(1);
  if (me == victim) v_name = "�Լ�";
  	else  v_name = victim->name(1);

  if (df>0)
  {
        shout( HIG "�������"+my_name+"ͶƱ��"+v_name+"("+capitalize(victim->query("id"))+")"+"��"+channel+"Ƶ��������"
			+chinese_number(df)+"Ʊ��\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ��" +v_name +"��"+channel+"Ƶ��������"
			+chinese_number(df)+"Ʊ��\n" NOR);
    
	victim->apply_condition("vote_clear", 10);
			        
  } else 
  {
  	if (me != victim)
  	{
        shout( HIG "�������"+my_name+"ͶƱ��"+v_name+"("+capitalize(victim->query("id"))+")"+"��"+channel+"Ƶ����"
		+v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ��" +v_name+"��"+channel+"Ƶ����"
		+v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	} else 
	{
	shout( HIG "�������"+my_name+"ͶƱ���Լ���"+channel+"Ƶ����"
		+my_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ���Լ���"+channel+"Ƶ����"
		+my_name+"��"+channel+"Ƶ�������ˣ�\n" NOR);
	}		
	
	victim->apply_condition("vote_clear", -10);
//183          victim->delete("channel/chblk_rumor");
	victim->delete("channel/chblk_chat");
	victim->delete("channel/chblk_sldh");
        victim->delete("channel/chblk_xyj");
//187          victim->delete("channel/tell_block");
  } 
  
  return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : openchat <ĳ��> 
��ָ���ʺ�����Ƶ����ҭ������ң�
��������������ر�Ƶ������ָ��
�������á�

�ο�ָ��: vote

HELP
    );
    return 1;
}

