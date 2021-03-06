//【凝心步法】 ningxin.c
inherit SKILL;

string *dodge_msg = ({
        "但是$n身形轻盈，从$N身边轻轻滑过。\n",
            "只见$n往后一退，隐入清风之中，$N这一招顿时没了目标。\n",
            "$n一转身，蒙蒙细雨突降，隔断了$N的攻势。\n",
            "$n左脚轻轻在地上一点，如小花随风般飘在半空，避开了$N的攻势。\n",
            "$n似乎有点躲闪不及，眼看就要中招。但是$N眼前百花齐降，不知怎的就扑空了。\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if (me->query("class") != "youning")
                return notify_fail("你非幽凝谷之人怎能练宁心步法？\n");
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能练习凝心步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
