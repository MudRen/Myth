// liushenjue.c 【六神诀】

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$N一招"HIC"「雷神疾」"NOR"，右手快若奔雷、急如飞电般掐上了$n的$l",
		"dodge":		10,
		"parry":		10,
		"force":		160,
		"damage_type":	"刺伤",
                        "weapon":		"右手食指",
	]),
	([	"action": 		"$N双手一翻，出"YEL"「罗汉卸」"NOR"，双手强韧有力、四两拨千斤，尽卸$N攻势",
		"dodge":		5,
		"parry":		-15,
		"force":		180,
		"damage_type":	"内伤",
                        "weapon":		"右手",
	]),
	([	"action":		"只见$N一转身，雄浑霸道、劲力如锥疾钻$n的$l，足已解肌裂肉，却正是一招"HIY"「金刚解」"NOR"",
		"dodge":		5,
		"parry":		10,
		"force":		100,
		"damage_type":	"刺伤",
                        "weapon":		"左手食指",
	]),
	([	"action":		"$N双掌一错，这一招"HIM"「观音乱」"NOR"迅速纷乱的旋涡招式瞬间轰出千百击，教$n防不胜防",
		"dodge":		20,
		"parry":		20,
		"force":		140,
		"damage_type":	"内伤",
                        "weapon":		"左手", 
	]),
            ([	"action":		"$N一招"RED"「观音灭」"NOR"，带着凛冽灼热的火焰气劲，拍向$n的$l",
		"dodge":		30,
		"parry":		10,
		"force":		70,
		"damage_type":	"内伤",
                        "weapon":		"左手",
	]),
            ([	"action":		"忽听$N一声怒吼，无穷内力凝成惊天威力，一式"HIG"「如来破」"NOR"，砍向$n的$l",
		"dodge":		10,
		"parry":		-10,
		"force":		220,
		"damage_type":	"砍伤",
                        "weapon":		"右手",
	]),
	    ([  "action": 		HIR"$N双掌合十，闭目凝神，催谷内力，一招之间融合了“六神诀”众招威力，一次过击向$n"NOR,
                "dodge":                -50,
                "parry":                -50,
                "force":                500,
                "damage_type":  "内伤",
	 ]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练六神诀必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("liushenjue_per");
        if( !me->query_temp("liushenjue_per") ) {
        return action[random(6)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习六神诀。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
//        write("你按着所学练了一遍六神诀。\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("sanjie") + "/liushenjue/" + func;
}

int stage(int level)
{
	if( level <20 ) return 1;
	else if ( level < 60 ) return 2;
	else if ( level < 100 ) return 3;
	else if ( level < 140 ) return 4;
	else if ( level < 180 ) return 5;
	else if ( level < 220 ) return 6;
	else return 7;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return HIC "雷神疾　" NOR;
	else if ( stage(level) < 2 )
		return YEL "罗汉卸　" NOR;
	else if ( stage(level) < 3 )
		return HIY "金刚解　" NOR;
	else if ( stage(level) < 4 )
		return HIM "观音乱　" NOR;
	else if ( stage(level) < 5 )
		return RED "观音灭　" NOR;
	else if ( stage(level) < 6 )
		return HIG "如来破　" NOR;
	else 
		return HIW "六神合一" NOR;
}
