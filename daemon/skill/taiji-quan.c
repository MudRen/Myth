//太极拳
//武当特殊拳法攻击
//by junhyun@SK

inherit SKILL;
#include <ansi.h>

mapping *action = ({
  ([
    "name":             "「起手式」",
    "action":
"$N起太极「起手式」，双手下垂，手背向外，接着两臂慢慢提起至胸前",
    "force":            50,
    "dodge":            -10,
    "parry":            -10,
    "damage_type":      "震伤",
  ]),
  ([
    "name":             "「揽雀尾」",
    "action":
"$N接着一招「揽雀尾」，双手划了个半圈，左阴右阳，按向$n的$l",
    "force":            100,
    "dodge":            10,
    "parry":            -10,
    "damage_type":      "内伤",
  ]),
  ([
    "name":             "「单鞭」",
    "action":
"$N面对$n，一招「单鞭」，左右两拳由下至上划弧，一前一后摆至平肩",
    "force":            70,
    "dodge":            10,
    "parry":            10,
    "damage_type":      "内伤",
  ]),
  ([
    "name":             "「提手上势」",
    "action":
"$N变招「提手上势」，两臂慢慢提起至胸前，左臂半环，右臂直伸，插向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),
  ([
    "name":             "「白鹤亮翅」",
    "action":
"$N单脚独立，左手虚按，右手使一招「白鹤亮翅」，变拳成抓向$n的$l插去",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),
  ([
    "name":             "「搂膝勾步」",
    "action":
"$N左腿微曲成虚步，一记「搂膝勾步」，左手向前、向下划弧按于$n$l旁",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([
    "name":             "「手挥琵琶」",
    "action":
"$N右臂半环，左手内旋，一招「手挥琶琶」，十指虚张，缓缓挥向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),  ([
    "name":             "「指裆锤」",
    "action":
"$N立半马步，左手内旋虚划，右手向下划弧握拳，一记「指裆锤」击向$n的裆部",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「双风灌耳」",
    "action":
"$N双手下划握拳，向后向前划弧成圈，一招「双风贯耳」，连消带打击向$n两太阳穴",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "内伤",
  ]),  ([

    "name":             "「白蛇吐信」",
    "action":
"$N左步成虚，左手向下虚按，右手成阳，使一招「白蛇吐信」，向$n的$l插去",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),  ([

    "name":             "「高探马」",
    "action":
"$N右脚虚立，左手画圈后抚，一招「高探马」，右手圆转向前，朝$n面门挥去",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「伏虎式」",
    "action":
"$N施出「伏虎式」，右手阳外划抱住$n，左手阴虚张五指，夹向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「肘底看锤」",
    "action":
"$N左手变掌横于胸前，右手握拳由肘下穿出，一招「肘底看锤」，锤向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「海底针」",
    "action":
"$N左脚前踏半步，右手虚张使一招「海底针」，五指由下向上戳向$n的裆部",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "抓伤",
  ]),  ([

    "name":             "「闪通臂」",
    "action":
"$N一招「闪通臂」，左脚一个弓箭步抢到$n身前，右手上举外撇，发出太极劲力震向$n",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "震伤",
  ]),  ([

    "name":             "「揽月势」",
    "action":
"$N右脚踏出，左右手握拳虚划，好似怀中抱月，这记「揽月势」一出，便将$n网在太极圈内",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "内伤",
  ]),  ([
    "name":             "「马步靠」",
    "action":
"$N立半马步，坐腿、松胯、旋腰、扣膝，力发于腰，一招「马步靠」，靠向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "震伤",
  ]),  ([
    "name":             "「金鸡独立」",
    "action":
"$N左腿收起，右脚独立，使一招「金鸡独立」，双拳划开，两个太极圈圈向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([
    "name":             "「玉女穿梭」",
    "action":
"$N进步虚踏，双手握拳划弧挥出，使一式「玉女穿梭」，顺着$n手臂直上，打向$n前胸",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「反身撇锤」",
    "action":
"$N左手划圈，右手经腹前经左肋向前撇出，使一招「反身撇锤」，向$n的$l锤去",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「转身蹬腿」",
    "action":
"$N左手虚按，左脚直立，右腿虚划一招「转身蹬腿」，向后旋出踢向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「栽锤」",
    "action":
"$N进步一招「栽锤」，左手划太极圈搂左膝，右手握拳向下划弧，锤向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「进步七星」",
    "action":
"$N脚踏七星方位，左虚右，双拳交叉成十字，一招「进步七星」，向$n的$l推去",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([
    "name":             "「倒撵猴」",
    "action":
"$N身体微转，左手略直，右臂微曲，阴阳相合，使一招「倒撵猴」，扛起$n向后直甩出去",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([
    "name":             "「转身摆莲」",
    "action":
"$N双手伸开，整个上身划出一个大圆弧，一招「转身摆莲」，将$n浑身上下笼罩在重重太极圈中",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([
    "name":             "「弯弓射虎」",
    "action":
"$N右手缓缓后收，左手握拳向前推出，拳意如箭，一招「弯弓射虎」，直奔$n$l而去",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「云手」",
    "action":
"$N使出一招「云手」，左手高，右手低，一个圆圈已将$n$l套住，太极柔劲随即发出",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「猢狲跃」",
    "action":
"$N轻跳一步「猢狲跃」，双手划太极圈拂开$n的攻击，借力打力抓起$n就往后掷出！",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「斜飞势」",
    "action":
"当下$N一招「斜飞势」，将$n力量引偏，双拳内划，合阴阳两股劲力一齐推向$n",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「抱虎归山」",
    "action":
"跟着$N换招「抱虎归山」，双拳划开，身体斜转，在$n身后一推，借力打力要将$n推出",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「野马分鬃」",
    "action":
"$N来个「野马分鬃」，转向$n身后，右前左后，两臂平伸在$n身上一靠，想将他震飞",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「如封似闭」",
    "action":
"$N左右手臂外旋变掌，两手交叉，继而左右分开，成半招「如封似闭」推向$n$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「十字手」",
    "action":
"$N上体微右转，屈膝坐胯，出招「十字手」，两只手臂微内旋，分别向体两侧划弧分掌",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([

    "name":             "「进步搬拦锤」",
    "action":
"$N右腿伸直，左手虚划，接着右臂外旋搬出一记「进步搬拦锤」击向$n的$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),  ([
    "name":             "「收势」",
    "action":
"$N两前臂内旋前伸，左右分开，臂微屈，腕与肩平，两手心向下徐徐落向$n$l",
    "force":            70,
    "dodge":            -10,
    "parry":            10,
    "damage_type":      "瘀伤",
  ]),


});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练太极拳必须空手。\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed"||usage=="parry"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
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
return CLASS_D("quest") + "/taiji-quan/" + func;
}

