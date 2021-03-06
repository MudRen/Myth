//风波十二叉 fengbo-cha.c

/*
风波十二叉    dodge  0    parry  -5    damage  25
因其有特别之处，建议各项暂设为中等。
*/

//pickle, not changed yet, please try to be compatible. 

// 昔人已乘黄鹤去，此地空余黄鹤楼
// 黄鹤一去不复返，白云千载空悠悠
// 晴川沥沥汉阳树，芳草凄凄鹦鹉洲
// 日暮乡关何处去，烟波江上使人愁

// 江上往来人，但爱鲈鱼美
// 君看一叶舟，出没风波里

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N一招",
        "$N双手一震，发出一招",
        "$N一提气，使出一招",
        "$N一声龙吟长啸，使出",
        "$N使出",
        "$N趁$n防御之际，一招",
});

string* skill_tail =({
        "，手中$w夹带着尖锐的响声，劈头盖脸地就向$n刺了过去。",
        "，对$n劈头盖脸的刺了过去。",
        "，手中$w斜斜地刺向$n的$l",
        "，手中$w一阵横扫，直逼$n",
        "，直震的$n节节后退。",
        "，手中$w飘渺不定，$n顿时手忙脚乱！",
});

mapping *action = ({
        ([      "name":                 "「昔人已乘黄鹤去」",
                "action":
"$N似乎在寻找些什么，手中$w在身前试探了数叉。\n"
"叉尖所指之处，正是$n的$l，原来是"BLINK+HIY"「昔人已乘黄鹤去」"NOR,
                "dodge":                0,
		"parry":		0,
                "damage":               45,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n挥动$W，在身前画了个半圆，正好挡开$N的攻势。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「此地空余黄鹤楼」",
                "action":
"$N身形不动，手中$w用一招"BLINK+HIR"「此地空余黄鹤楼」"NOR"，\n"
"拍向$n的$l。这招似乎颇为窒滞生硬，但毫不拖泥带水，攻势甚是凌厉",
                "dodge":                0,
		"parry":		0,
                "damage":               45,
                "damage_type":  	"瘀伤",
		"parry_msg":
"$n丝毫不为所动，轻描淡写地挥叉一刺，逼得$N回手自防。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「黄鹤一去不复返」",
                "action":
"$N接连几个起落，作势欲走，$n忙疾追不迭。正在这时，\n"
"$N于空中突然回身，一式"BLINK+HIC"「黄鹤一去不复返」"NOR"直指$n的$l",
                "dodge":                -10,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"刺伤",
		"parry_msg":
"$n一抖手中$W，在$N兵器上一按，借势纵开数丈。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「白云千载空悠悠」",
                "action":
"$N一声清啸，但见漫天叉影，化作朵朵白云，扰得$n眼花缭乱\n"
"这招"BLINK+HIW"「白云千载空悠悠」"NOR"颇为传神，果然有一番前不见古人，后不见来者的气概",
                "dodge":                -10,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"瘀伤",
		"parry_msg":
"$n将$W舞得风雨不透，$N无奈之下只好换招。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「晴川沥沥汉阳树」",
                "action":
"$N手中$w一颤，用一招"BLINK+HIM"「晴川沥沥汉阳树」"NOR"，迅捷无比地在$n上下左右各刺一叉",
                "dodge":                0,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"刺伤",
		"parry_msg":
"$n以手中$W画了个圆弧，将周身破绽都封死了。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「芳草凄凄鹦鹉洲」",
                "action":
"$N施出一招"BLINK+HIG"「芳草凄凄鹦鹉洲」"NOR"，只见$w若有若无地一探，\n"
"看去势似乎刺向$n左侧数寸处，但不知怎的，转瞬间叉尖已到了$l",
                "dodge":                0,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n怯生生地举叉一挡，似乎力不从心。但等到二人兵刃相交时，\n"
"$n$W上忽然发出一股韧力，将$N挡了开去。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「日暮乡关何处去」",
                "action":
"$N朗笑一声，手中$w泛出重重暗影，好似一阵阵浓雾，推向$n。\n"
"$n看不透这招"BLINK+HIB"「日暮乡关何处去」"NOR"的来路，实在不知如何招架",
                "dodge":                0,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"刺伤",
		"parry_msg":
"$n不避不让，挺$W在身前空处连次数叉。这招看来平平无奇，却于平淡中将$N的攻势封死了。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「烟波江上使人愁」",
                "action":
"$n刚喘得一喘，却见$N身形一闪，已经踪影全无。$n还未来得及转身，\n"
"$N的$w已到背后了。这招"BLINK+YEL"「烟波江上使人愁」"NOR"果然轻快无比，令人防不胜防",
                "dodge":                -10,
		"parry":		-10,
                "damage":               45,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n眼见$N攻势凌厉，忙用一招「烟波江上使人愁」，连转数圈，将$N的力拨在一边。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「江上往来人」",
                "action":
"$N怒叱一声，手中$w齐快无比地在$n身前来来回回连划七划。\n"
"这招"BLINK+WHT"「江上往来人」"NOR"变幻无方，$n实在不知哪招是虚，哪招是实",
                "dodge":                5,
		"parry":		-15,
                "damage":               50,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n连挥手中$W，只听叮叮当当一阵密响，终于将$N挡了回去。\n",
		"parry_power":		15,
        ]),
        ([      "name":                 "「但爱鲈鱼美」",
                "action":
"$N手中$w缓缓画了个圆圈，用一招"BLINK+CYN"「但爱鲈鱼美」"NOR"慢慢向$n的$l套去",
                "dodge":                5,
		"parry":		-5,
                "damage":               55,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n似乎胸有成竹，挺叉连划数个圆圈。$N看不透$n的守势，果然不敢贸然进攻。\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "「君看一叶舟」",
                "action":
"$N身形一旋，冲天而起。手中$w借着下冲之势，一招"BLINK+MAG"「君看一叶舟」"NOR"直插$n的$l",
                "dodge":                10,
		"parry":		-10,
                "damage":               55,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n看准来势，以$W向$N的兵刃猛点。只听「当」的一声巨响，果然将$N的兵刃荡了开去。\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "「出没风波里」",
                "action":
"$N突然脸上青气一显，叉上嗡嗡之声大做，正当$n惊诧时，\n"
"$N狂风骤雨般连攻五叉。这招"BLINK+GRN"「出没风波里」"NOR"是整套叉法的精髓，\n"
"施将出来，不但变幻莫测，且声势惊人，$n顿时不知所措",
                "dodge":                -5,
		"parry":		-5,
                "damage":               60,
                "damage_type":  	"戳伤",
		"parry_msg":
"$n不顾自身，手中$W连连刺向$N。这围魏救赵之记果然奏效，将$N逼了回去。\n",
		"parry_power":		15,
        ]),
});


int valid_learn(object me)
{
        object ob;

	if (me->query("class") != "dragon")
		return notify_fail("你非龙族，怎能习惯这水中出没的叉法？\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，无法领会风波十二叉的精妙之处。\n");

	if (me->query_skill("dragonforce", 1) < me->query_skill("fengbo-cha", 1)/2)
		return notify_fail("你的龙神心法修为太低。\n");

        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "fork" )
                return notify_fail("你必须先找一柄叉来才能学叉法。\n");
        return 1;
}

int practice_skill(object me)
{
    if (me->query("class") != "dragon")
	return notify_fail("你非龙族，怎能习惯这水中出没的叉法？\n");
    if(me->query_skill_mapped("force") !="dragonforce")
	return notify_fail("风波十二叉必须配合龙神心法才能发挥威力。\n");
    if(me->query("kee") < 50) return notify_fail("你的体力太弱，先休息一会儿吧。\n");
    if(me->query("sen") < 50) return notify_fail("你的神智不清，就算练了也什么都学不到的。\n");
    if(me->query("force") < 20) return notify_fail("你的内力不足，无法照路数舞叉。\n");

    me->add("kee", -30);
    me->add("force", -3);
    return 1;
}

int valid_enable(string usage)
{
        return usage=="fork"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_fengbo-cha");
if( !me->query_temp("HTH_perform")) 
{
if(me->query("skill_fengbo-cha")==0)
return action[random(6)];
if(random(2)) return action[random(6)];
return m_actions[random(sizeof(m_actions))];
}
else{return action[6];}
    return action[random(sizeof(action))];
}

int valid_effect(object me, object weapon, string name, int skill){}

string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}

string perform_action_file(string func)
{
	return CLASS_D("dragon") + "/fengbo-cha/" + func;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("fengbo-cha",1);
   if(m_skill>200&&m_skill%10==0)
   {
   tell_object(me,HIW"你对风波十二叉的领悟加深了，你的风波十二叉进入了一个新的境界！\n"NOR);
   if(random(me->query("kar"))<20)
   {
   tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
   return;
   }
   if(random(me->query("int"))<20)
   {
   tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
   return;
   }
   tell_object(me,HIW"你突然福至心灵，对风波十二叉领悟出了一招新的用法！\n"NOR);
   tell_object(me,"请为这招取一个名字：");
   input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_fengbo-cha");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+me->query_skill("unarmed",1)/5;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"戳伤"]);

   if(!arg||arg==" ")arg="风波十二叉绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIR"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_fengbo-cha",m_actions);
}
