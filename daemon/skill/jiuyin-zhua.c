//九阴白骨爪
//轩辕古墓特殊拳脚
//by ivy 2002.2.9

//  森然见白骨 明月当空照 素手裂红裳 阴气动四方 
//  相思深入骨 铁指破残阳 九阴搜魂手 爪现鬼神亡

inherit SKILL;
#include <ansi.h>

mapping *action = ({
  ([
    "name":             "「森然见白骨」",
    "action":
"$N使一招「"+BLINK""+HIW"森然见白骨"NOR"」，五指如钩，插向$n的$l",
    "force":            50,
    "dodge":            -10,
    "parry":            -10,
    "damage_type":      "抓伤",
  ]),
  ([
    "name":             "「素手裂红裳」",
    "action":
"$N出手如风，十指微微抖动，一招「"+BLINK""+HIR"素手裂红裳"NOR"」抓向$n的$l",
    "force":            100,
    "dodge":            10,
    "parry":            -10,
    "damage_type":      "抓伤",
  ]),
  ([
    "name":             "「明月当空照」",
    "action":
"$N左手一立，右手急出，一招「"+BLINK""+HIC"明月当空照"NOR"」，猛地抓向$n的头部",
    "force":            70,
    "dodge":            10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),
  ([
    "name":             "「阴气动四方」",
    "action":
"$N使一招「"+BLINK""+HIB"阴气动四方"NOR"」，激起漫天的劲风，撞向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),
  ([
    "name":             "「相思深入骨」",
    "action":
"$N一招「"+BLINK""+HIW"相思深入骨"NOR"」，十指如戟，插向$n的顶门",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),
  ([
    "name":             "「铁指破残阳」",
    "action":
"$N双手忽隐忽现，一招「"+BLINK""+HIR"铁指破残阳"NOR"」，鬼魅般抓向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),  ([
    "name":             "「九阴搜魂手」",
    "action":
"$N使一招「"+BLINK""+HIW"九阴搜魂手"NOR"」，十指忽伸忽缩，袭向$n全身各处大穴",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),  ([
    "name":             "「爪现鬼神亡」",
    "action":
"$N左手指天，右手指地，荡起阵阵阴风，一招「"+BLINK""+HIC"爪现鬼神亡"NOR"」击向$n的顶门",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),


});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练九阴白骨爪必须空手。\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed"||usage=="parry"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if (me->query("class") != "yaomo")
                return notify_fail("嘿嘿，一身正气如何堕入魔道？\n");
        if( (int)me->query("sen") < 40)
                return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
        if( (int)me->query("kee") < 40 )
                return notify_fail("你现在手足酸软，休息一下再练吧。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够了。\n");

        me->receive_damage("kee", 30);
        me->add("force", -10);

        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("gumu") + "/jiuyin-zhua/" + func;
}

