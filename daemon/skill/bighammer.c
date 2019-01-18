//�����ƴ���??

/*
  dodge  5    parry  0    damage  35
�����޴�����ƽƽ
*/
#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
	([	"action":	"$N��������$wһ��[���ޱ�]��������",
 "dodge":        -10,
 "parry":        0,
		"damage":	30,
		"damage_type":	"����",
	]),
	([	"action":	"$Nһ���������$wһ��[�Ӷ�ʨ��]����һ�����ֱϮ$1",
		"dodge":	15,
"parry":        5,
"damage":       40,
		"damage_type":	"����",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
	([	"action":	"$N��$w�߾ٹ��磬��׼$n��$l����һ��",
		"dodge":	20,
		"parry":	-10,
		"damage":	35,
		"damage_type":	"����",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
	([	"action":	"$N����һת��$w����$n��$1��ʹ����һ��[���ֳ�ת]��",
		"dodge":	-15,
		"parry":	5,
		"damage":	25,
		"damage_type":	"����",
	]),
	([	"action":	"$Nһ��[��ͷ����]$wֻ��$n����",
		"dodge":	10,
		"parry":	10,
		"damage":	40,
		"damage_type":	"����",
	]),
	([	"action":	"$N���з�ţ�$w��һ������ĽǶ�һѸ�ײ����ڶ�֮��ֱײ$n",
		"dodge":	-5,
		"parry":	-10,
		"damage":	40,
		"damage_type":	"����",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
});


void bash_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp;

        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "$Nֻ��������" + ob->name() + "�ѳֲ��������ַɳ���\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$Nֻ��������" + ob->name() + "һ����Щ���֣�\n",
                                victim);
                } else if( wap > wdp / 2 ) {
                        message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name()
                                + "�Ѿ���Ϊ���أ�\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "�ϵ���" + ob->query("name"));
                        //ob->set("value", (int)ob->query("value") / 20);
                        ob->set("value", 0);
                        //so can't sell broken weapon.
                        //otherwise may have problem in pawn shop
                        //when the broken weapon disappeared.
                        ob->set("weapon_prop", 0);
                        ob->set("armor_prop", 0);
                        call_out("remove_broken_weapon",random(300)+60,ob);
                        victim->reset_action();
                } else {
                        message_vision("$N��" + weapon->name() + "��$n��" + ob->name()
                                + "�����ð�����Ļ��ǡ�\n", me, victim);
                }
        }
}


void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "һ��΢�紵����"+ob->name()+"��ΪƬƬ��������ʧ�����ˡ�\n");
    destruct(ob);
  }
}




int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취�����ƴ���\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("���������һ���󴸲��������ƴ���\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 50 )
                return
notify_fail("�����������������û�а취��ϰ���ƴ���\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ����ƴ���\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/bighammer/" + func;
}
