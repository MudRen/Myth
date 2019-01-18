//cast function: qiankun.c ����Ǭ����
//need to be activated by ��Ԫ���� to use this cast...weiqi, 
//weiqi, mon 1/98

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int success, ap, dp;
	object sleeveroom,sleeve;
	string sname;
	object env, *inv;
	int size,i;

	seteuid(getuid());

	if( me->query("spell_qiankun_on") != 1 )
		return notify_fail("�㻹��������Ǭ����\n");

//	if( !target ) target = offensive_target(me);

        if(!target) 
        {
          //see if I am fighting someone...this is useful for NPC...
          if(  (offensive_target(me)) ) target = offensive_target(me);
 	  else
         {
	  // then take stuff out.
	  sleeveroom=load_object("/d/wiz/sleeveroom");
	  if(!sleeveroom) return notify_fail("No sleeve space found.\n");

          sname=me->query("id")+"'s sleeve";
          if(!sleeve=present(sname,sleeveroom)) {
             message_vision(
	     "$N������ӭ��һ˦����������ʲôҲû�С�\n",me);
	     return 1;
          }

	  size=sizeof(inv=all_inventory(sleeve));
	  if(!size) {
             message_vision(
	     "$N������ӭ��һ˦����������ʲôҲû�С�\n",me);
	     return 1;
          }

	  msg="$N������ӭ��һ˦��";
	  for(i=0;i<size;i++) {
	    if(inv[i]->is_character())
	      msg+="$n��ͨһ��ˤ���ڵ��ϡ�\n";
            else
	      msg+="$n�̵�һ�����ڵ��ϡ�\n";

            env=environment(me);
            while(!(inv[i]->move(env))) env=environment(env);

	    message_vision(msg,me,inv[i]);
	    msg="";
	  }
          return 1;
	}
       }

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ��˭ʩչ����Ǭ����\n");

	if( (int)me->query("mana") < 400 )
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
		return notify_fail("������ͷ�Բ����ѣ�����ʹ�ó�����Ǭ����\n");

	if( random(me->query("max_mana")) < 50 ) {
		write("��ʧ���ˣ�\n");
		return 1;
	}

	msg =  HIR "$N�૵����˼������ͻȻ����һ�ӳ�$n���˹�ȥ��\n" NOR;
	message_vision(msg, me, target);
	
	target->kill_ob(me);
	me->kill_ob(target);


	success = 1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /10 ;
	ap += (int)me->query("daoxing");
	ap = 3*ap; 
	dp = target->query("daoxing");
	if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

	ap = (int)me->query("max_mana");
	dp = (int)target->query("max_mana");
	if( ap < random(dp) ) success = 0;
//here we compared max_mana.
//if the attacher has half of the max_mana of the target, 
//he has 50% chance to success.

	if(success == 1 )
	{
		me->add("mana", -400);
	
	        sleeveroom=load_object("/d/wiz/sleeveroom");
		if(!sleeveroom) return notify_fail("No sleeve space found.\n");

                sname=me->query("id")+"'s sleeve";
		if(!sleeve=present(sname,sleeveroom)) {
                  sleeve=new("/d/obj/fabao/sleeve");
		  if(!sleeve) return notify_fail("No sleeve found.\n");

		  sleeve->set_max_encumbrance(300000);
		  //this corresponding to about 4 people.
		  //should make this depends on the spells level of
		  //a player, so higher ppl can carry more.

		  sleeve->set_name(
		    me->query("name")+"��������",({sname,"sleeve"}));
                  sleeve->set("short",
		    me->query("name")+"��������");
		  if(!sleeve->move(sleeveroom)) 
		    return notify_fail("Failed to move sleeve.\n");
		}

		if(target->move(sleeve)) {
		  msg =  HIR "���ವ�һ��$n��װ�˽�ȥ��\n" NOR;
		  message_vision(msg, me, target);
                } else {
                  msg=HIR"���$nֻ��ҡ����һ�£��ֲ����ˡ�\n" NOR;
		  msg+="$n��$N��˵̫���ˡ�\n";
		  message_vision(msg, me, target);
		}
		
	}
	else 
	{
		msg =  HIR "�����$n����һ�ƣ������ס$N�Լ����Դ���\n" NOR;
		message_vision(msg, me, target);

		me->add("mana", -400);
	} 

	return 3+random(5);
}

