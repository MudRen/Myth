//空无剑
//by dewbaby 12.2002

//若即若离 空谷幽灵 无所不有
//离别何期 无意生死 此情待忆

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N腾空跃起，回首一招"BLINK" "WHT"「若即若离」"NOR"，手中$w连连点向$n的$l",
        "force"  : -30,
        "damage" : 30,
        "damage_type" : "刺伤"
]),
 ([      "action" : "$N左脚轻轻点地，仰头轻笑，一招"BLINK" "HIB"「空谷幽灵」"NOR"如旋风般逼向$n，$w将$n团团罩住，动弹不得！",
        "force"  : -30,
        "parry"  :  5,
        "damage" : 25,
        "damage_type" : "内伤"
]),
 ([      "action" : "$N一招"BLINK" "HIY"「无所不有」"NOR"看似破绽百出，实则陷阱重重。$w自左到右连画两个大弧，向$n劈砍下去",
        "force"  : -30,
        "parry"  : 5,
        "dodge"  : 5,
        "damage" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N行走如风，手中$w使出"BLINK" "HIR"「离别何期」"NOR"，将$n逼得连连后退。",
        "force"  : -30,
        "parry"  : 10,      
        "damage" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w上绿光闪闪，$n一下子看得愣住了，却被一招"BLINK" "HIG"「无意生死」"NOR"刺重$l",
        "force"  : -30,
        "parry"  :  10,
        "dodge"  : -10,
        "damage" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N将$w高举胸前，一个回身，$w化为一团烈火卷向$n。这正是一招"BLINK" "HIR"「此情待忆」"NOR"!",
        "force"  : -30,
        "parry"  :  10,
        "dodge"  : -10,
        "damage" :  40,
        "damage_type" : "内伤"
]),
});


int valid_enable(string usage) { return (usage == "sword"); }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("fenxin-spells", 1) < 60)
                return notify_fail("你的焚心术还没到家。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
     return action[random(sizeof(action))]; 
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力无法练空无剑。\n");
        if ((int)me->query("str") <= 20)
        write(WHT"你需要加强锻炼呀，身体是革命的本钱！\n"NOR,me);
        me->receive_damage("kee", 20);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("linghai") + "/kongwujian/" + action;
}





