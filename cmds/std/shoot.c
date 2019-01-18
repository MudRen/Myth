// shoot.c  by bbs May 27, 1998
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "valid_kill.h";


inherit F_DBASE;

int main(object me, string arg)
{
	string item, targ;
	object ob, victim, ob2;
	int success, found, ap, dp, level, damage,damage_bonus, wound, lucky;
	mixed foo;
	string msg;

	if(environment(me)->query("no_fight") || 
           environment(me)->query("no_magic") )
              return notify_fail("��ȫ����������ǻ����𹫷ߵ��ޣ�\n");

    	if( this_player()->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( !arg || sscanf(arg, "%s on %s", item, targ)!=2 )
		return notify_fail("ָ���ʽ��shoot <ĳ��> on <ĳ��>\n");

	if(targ == me->query("id"))
		return notify_fail("����ɱӦ����suicide�ɣ�\n");
	if( !objectp(ob = present(item, me)))
		return notify_fail("������û�� "+item+"\n");

	if(ob->query("skill_type")!="sword" || ob->query("apply/skill_type")!="archery")
		return notify_fail(ob->query("name")+"���Ǽ���\n");
	

	success=0;
	if(ob2=me->query_temp("weapon")) {
		if(ob2->query("skill_type")=="blade" && ob2->query("apply/skill_type")=="archery") 
			success=1;
		else {
			if(ob2=me->query_temp("secondary_weapon")) {
				if(ob2->query("skill_type")=="blade" && ob2->query("apply/skill_type")=="archery") 
					success=1;
			}
		}
	}
	if(!success)
		return notify_fail("�������Ū�Ź���\n");
			
	if( !objectp(victim = present(targ, environment(me))) )
		return notify_fail("��������˭��\n");

	if( !living(victim)) 
                return notify_fail("ʲô�㶼��ɱ��\n");

	if(!valid_kill(me,victim,0)) return 0;

	success=0;
	found=0;
	lucky=0;
	damage=0;
	wound=0;
	ap=COMBAT_D->skill_power(me, "archery", SKILL_USAGE_ATTACK);
	dp=COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	dp/=2;			// �����ѷ� 
	if(random(ap+dp) > dp) {
		success=1;
		if(ap<dp) lucky=1;
	}
	msg="$N���ִӻ����ͳ�һ"+ob->query("base_unit")+ob->query("name")+"������"+ob2->query("name")+"�ϡ�\n";
	msg+="һ���֣�ֻ��һ���������$n�����ţ�";

	if(success) {
		msg+="$n���ȴû�㿪��\n";
		damage=ob->query("weapon_prop/damage");
		damage+=random(damage);
		damage_bonus=me->query_str();
		foo=ob->hit_ob(me, victim, damage);
		if(stringp(foo)) msg+=foo;
		else if(intp(foo)) damage_bonus+=foo;
		wound=random(damage-(int)victim->query_temp("apply/armor"));
		damage+=(damage_bonus+random(damage_bonus))/2;
		ap=me->query("force");
		dp=victim->query("force");
		while(random(dp)>ap) {
			damage-=damage/3;
			dp/=2;
		}
		if (wizardp(me) && me->query("env/combat")=="verbose")
			tell_object(me, sprintf(GRN "damage: %d, wound: %d\n" NOR, damage, wound));
		if(damage>0) {
			victim->receive_damage("kee", damage, me);
			if(wound >0) victim->receive_wound("kee", wound, me);
			msg+=COMBAT_D->damage_msg(damage,"�˺�");
		}
		if(random(me->query("sen")*100/me->query("max_sen") + me->query_int()*me->query_cps()) > 150) {
			if(lucky) {
				me->improve_skill("archery", 1);
				me->set("combat_exp",me->query("combat_exp")+1);
	                	if(me->query("potential")-me->query("learned_points")<100)
       	                 		me->set("potential",me->query("potential")+1);
			}
		}
	}
	else 
		msg+="���Ǳ�$n�㿪�ˡ�\n";

	if((int)ob->query_amount()==1) {
		if(stringp(ob->query("equipped"))) ob->unequip();
		tell_object(me, "���" + ob->query("name") + "�����ˣ�\n");
	}
	ob->add_amount(-1);

	message_vision(msg, me, victim);
	if(damage > 0) COMBAT_D->report_status(victim);

	if(living(victim)) {
		msg="$nŭ��$N�������ȵ���С�����Ӹҷ������\n";
		message_vision(msg, me, victim);
		if(userp(victim)) victim->fight_ob(me);
		else victim->kill_ob(me);
		me->kill_ob(victim);
	}

	me->start_busy(1+random(2));
	return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: shoot <something> on <someone>

��һָ�����������ĳ�������
HELP
   );
   return 1;
}
