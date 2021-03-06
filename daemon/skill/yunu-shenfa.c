#include <ansi.h>;

inherit SKILL;

string *dodge_msg = ({
  HIW"$n一招"HIC"「洛神凌波」"HIW"，长袖舞动，掩住身形去处，轻飘飘腾身丈外，躲过了$N这一招。\n"NOR,

  HIR"$n嫣然一笑，风姿绝代，$N惊为天人，手下不由一顿，$n已借这"HIM"「一笑倾国」"HIR"之势，避开了$N的凌厉攻势。\n"NOR,

  HIG"$n使出"HIR"「贵妃醉酒」"HIG"，满面红晕，脚步踉跄中已饶至$N的身后。\n"NOR,

  HIC"$n左足点地，眼看$N杀招堪堪袭来，左膝一弯，右腿踢出，正是一招"HIR"「红拂夜奔」"HIC"，身躯已借势平移，闪过一旁。\n"NOR,

  HIY"$n一式"HIG"「绿珠坠楼」"HIG"，身体贴地滑行，真叫人匪夷所思，令$N的攻击已然扑空。\n"NOR,

});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
        if( (string)me->query("gender") != "女性" )
                return notify_fail("玉女身法只有女性才能练。\n");
        if( (int)me->query("spi") < 10 )
                return notify_fail("你的灵性不够，没有办法玉女身法舞。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("sen") < 30 )
                return notify_fail("你的精神太差了，不能练玉女身法舞。\n");
        me->receive_damage("sen", 30);
        return 1;
}


