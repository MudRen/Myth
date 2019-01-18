// bian.c
// by mon. 1/3/97

#include <ansi.h>

int do_bian(object me);

int main(object me, string arg)
{
      string id;
      object who,obj;
      int mana,spells,dmana;

      seteuid(getuid());

      if( me->is_fighting() )
        return notify_fail("������ս������Ͼ����\n");
      if( me->is_busy() || me->query_temp("pending/exercising"))
	return notify_fail("����æ���أ�û�������\n");
 
       if (arg=="silver" && arg=="gold") return notify_fail(" �㲻�ܱ����Ӻͻƽ�!\n");
       if (arg=="coin" && arg=="cash" && arg=="thousand-cash") return notify_fail(" �㲻�ܱ����Ӻͻƽ�!\n");
       if (arg=="gold") return notify_fail(" �㲻�ܱ����Ӻͻƽ�!\n");
       if (arg=="cash") return notify_fail(" �㲻�ܱ����Ӻͻƽ�!\n");
       if (arg=="thousand-cash") return notify_fail(" �㲻�ܱ����Ӻͻƽ�!\n");
       if (arg=="silver") return notify_fail(" �㲻�ܱ����Ӻͻƽ�!\n");


      if (!arg || arg=="me" || arg==me->query("id")) 
	who=me;
      else {
	if(!objectp(who=present(arg,environment(me)))) 
	   return notify_fail("������˭��\n");
      }
      if (who->query("no_bian")) return notify_fail("�����룡\n");

  if ( arg=="coin" ) 
             return notify_fail("�����ٳ���\n");
  if ( arg=="gold" ) 
             return notify_fail("�����ٳ���\n");
  if ( arg=="silver" ) 
             return notify_fail("�����ٳ���\n");
  if ( arg=="cash" ) 
             return notify_fail("�����ٳ���\n");
      if(who==me) {
	me->delete_temp("spellslevel");
	me->delete_temp("apply/name");
	me->delete_temp("apply/id");
	me->delete_temp("apply/short");
	me->delete_temp("apply/long");
	me->delete_temp("family");

	me->delete_temp("no_heal_up/bian");

        if(me->query_temp("d_mana")) {
	  me->delete_temp("d_mana");
	  while( environment(me)->is_character() )
	     me->move(environment(environment(me)));
	     //mon 9/25/97. to prevent being carried by another player
	     //after bianed back.
          message_vision(HIY "$N�����������һ�Σ���������\n"
	    NOR,me);
        } else {
	  return notify_fail("������˭��\n");
        }
      }
      else {
        spells=me->query_skill("spells");
	mana=me->query("mana");

	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
		< RANK_D->grade_dx(BLU "�������" NOR) )
		return notify_fail("�����ڻ����������̸���ϣ������ܱ䡣\n");

	if( RANK_D->grade_fali( RANK_D->describe_fali( (int)me->query("max_mana") ) ) 
		< RANK_D->grade_fali(HIB "�����û" NOR) )
		return notify_fail("��������ķ�����Ϊ�����������û��\n");

	if (spells<25)
	   return notify_fail("��ķ���������\n");

        if (mana<150)
	   return notify_fail("��Ŀǰ����������ӯ��\n");

        if (wizardp(who) && !wizardp(me))
	   return notify_fail("��ķ��������Ա����ʦ��\n");
   if (who->query("no_bian")) return notify_fail("�㲻�ܱ������Ķ�����\n");
	
	dmana=30+400/(spells-20); 
	
	message_vision(HIY "$N����ھ�������ԣ�ҡ��һ�䣬��ú�$nһģһ����\n" NOR,me,who);
        me->set_temp("spellslevel",spells);
	me->set_temp("apply/name",({who->name()}));
	me->set_temp("apply/id",who->parse_command_id_list());
	me->set_temp("apply/short", ({who->short()}));
	me->set_temp("apply/long", ({who->long()}));
	me->add("mana",-100);
     me->set("no_sell",1);
     who->set("no_sell",1);
	if((int)who->query_temp("d_mana")>0) {//who is "bian"ing at the moment.
	    me->set_temp("is_living", who->query_temp("is_living"));
	    me->set_temp("unit",who->query_temp("unit"));
            me->set_temp("is_character",who->query_temp("is_character"));
	    me->set_temp("gender",who->query_temp("gender"));
	    me->set_temp("age",who->query_temp("age"));
	    me->set_temp("race",who->query_temp("race"));
	    me->set_temp("family",who->query_temp("family"));
	} else {
            me->set_temp("is_living",living(who));
	    me->set_temp("unit",who->query("unit"));
            me->set_temp("is_character",who->is_character());
	    me->set_temp("gender",who->query("gender"));
	    me->set_temp("age",who->query("age"));
	    me->set_temp("race",who->query("race"));
	    me->set_temp("family",who->query("family"));
	}

	if (!me->query_temp("d_mana")) call_out("do_bian",5,me);
	me->set_temp("d_mana",dmana);
	
	me->set_temp("no_heal_up/bian",1);
     me->set("no_sell",1);
     who->set("no_sell",1);
      }

      return 1;
}

int do_bian(object me)
{  
    int dmana,mana,spells;

    if(!me) return 1;

    dmana=me->query_temp("d_mana");
    spells=me->query_temp("spellslevel");
   
//    tell_object(me,"Mana, d_mana, spells:"+me->query("mana")+
//     ","+dmana+","+spells+"\n");

    mana=me->query("mana");
    if ((mana-dmana)>50 && spells>0 && dmana>0) {
      me->add("mana",(-dmana));
      call_out("do_bian",5,me);
    }
    else {
      mana=mana-dmana;
      if (mana<20) mana=20;
      me->set("mana",mana);
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long");
      while( environment(me)->is_character() )
                   me->move(environment(environment(me)));
      if (dmana>0) 
        message_vision(HIY
        "ֻ��$N��ɫ�԰ף�һ�����֮�䣬�Ѿ�����ԭ�Ρ�\n" NOR,me);
      
      me->delete_temp("no_heal_up/bian");
    }

    return 1;
}

int help(object me)
{
	write(@HELP

ָ���ʽ �� bian [<����>|<NPC>|<me>]

�����������ָ������仯�����������ģ�����Ƿ��ܱ䣬��Ҫȡ����
��ķ����ͷ�����С��

�������ָ� observe��
HELP
	);
	return 1;
}



