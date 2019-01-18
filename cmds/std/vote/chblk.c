// vote chblk
#include <vote.h> 
#include <ansi.h>

inherit F_CONDITION;

int clear_vote(object me);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;       // valid voter numbers
  int vc;       // vote count;
  int df;
  string *juror, my_id;

  if (me == victim)
  {
        if (random(2)) me->add("vote/abuse", 10);
        return notify_fail("�㲻�ǿ���Ц�ɣ����ı�������Ȩ��\n");
  }

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_CHBLK))
  {
        return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");
  }

  if( victim->query("channel/chblk_on") ) 
  {
        return notify_fail(victim->name()+"��Ƶ���Ѿ��ǹرյ��ˡ�\n");
  }

  if (reason <= 0)
  {
        victim->set("vote/reason", (int)V_CHBLK); 
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

  if (df>0)
  { 
        shout( HIW "�������"+me->name(1)+"ͶƱ�ر�"+victim->name(1)+"("+capitalize(victim->query("id"))+")"
                        +"�Ľ�̸Ƶ��������"+chinese_number(df)+"Ʊ��\n" NOR);
        write( HIW "�������"+me->name(1)+"ͶƱ�ر�" +victim->name(1)
                        +"�Ľ�̸Ƶ��������"+chinese_number(df)+"Ʊ��\n" NOR);
        victim->apply_condition("vote_clear", 10);
  } else 
  {
        shout( HIW "�������"+me->name(1)+"ͶƱ�ر�" +victim->name(1)+"("+capitalize(victim->query("id"))+")"
                        +"�Ľ�̸Ƶ����"+victim->name(1)+"�Ľ�̸Ƶ�����ر��ˣ�\n" NOR);
        write( HIW "�������"+me->name()+"ͶƱ�ر�" +victim->name()
                        +"�Ľ�̸Ƶ����"+victim->name(1)+"�Ľ�̸Ƶ�����ر��ˣ�\n" NOR);
                        
        victim->apply_condition("vote_clear", -10);
        victim->set("channel/chblk_on", 1);
  } 
  
  return 1;
}

