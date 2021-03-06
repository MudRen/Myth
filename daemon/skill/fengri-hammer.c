// 神话世界·西游记·版本４．５０
/* by cigar 2002.01 */
 
//【封日锤】??

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N沉稳脚步的一招",
        "$N双手一震，发出一招",
        "$N一提气，使出一招",
        "$N一声长啸，使出",
        "$N大呼一声使出",
        "$N趁$n防御之际，一招",
});

string* skill_tail =({
        "，手中$w夹带着烈日般的热度，劈头盖脸地就向$n烧了下来。",
        "，对$n劈头盖脸的砸了下来。",
        "，手中$w斜斜借助烈日炎光砸向$n的$l",
        "，手中$w一阵横扫，靠炎日的威力直逼$n",
        "，直震的$n节节后退。",
        "，手中$w飘渺不定，闪闪发光，$n顿时手忙脚乱！",
});
mapping *action = ({
  ([   "action":   "$N手中$w一转，卷着一股强劲的"+BLINK""+HIR"[炎炎烈日]"NOR"之火烧向$n的$l，
这一下又稳又猛又烈，势大力狠，眼见就到了$n身前",
     "dodge":   10,
     "parry":   -10,
     "damage":   50,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N双手一紧，手中$w夹带着"+BLINK""+HIR"[封日]"NOR"般的威力，劈头盖脸地就向$n砸了过去",
     "dodge":   15,
     "parry":   -15,
     "damage":   40,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N将$w高举过肩，蓄紧力发，对准$n的$l发出"+BLINK""+HIY"[烈日之光]"NOR"",
     "dodge":   20,
     "parry":   -20,
     "damage":   35,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N身走轻灵，手中$w忽上忽下，甩出"+BLINK""+HIY"[熊熊火焰]"NOR"令人捉摸不清去路，
就在$n一恍惚间，“唰”地砸向$n的$l",
     "dodge":   0,
     "parry":   -10,
     "damage":   25,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N趁与$n错身之时，倒转$w，锤柄砸向$n，
这一下如"+BLINK""+HIR"[烈火]"NOR"，悄无声息的射上了$n的$l",
     "dodge":   10,
     "parry":   -10,
     "damage":   25,
     "damage_type":   "戳伤",
   ]),
   ([   "action":   "$N手持$w对着"+BLINK""+HIR"[炎日]"NOR"画了一个无形大圈，卷的周围沙土尘扬，
趁$n不能辨物之时，手中$w斜斜地封向$n的$l",
     "dodge":   20,
     "parry":   -25,
     "damage":   40,
     "damage_type":   "砸伤",
   ]),
(["action" : "$N一声长啸，大锤直封$n，此招看似简单、看似无力，但是力道无穷浑厚，
相传源自盘古开天时所用的"+BLINK""+HIW"[破烈日]"NOR"无极招数。",
    "dodge" : 20,
    "damage" : 200,
    "lvl" : 120,
    "skill_name" : "烈日冰封",
    "damage_type" : "砸伤"
]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练封日锤。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一柄锤才能练封日锤。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_fengri-hammer");
if( !me->query_temp("HTH_perform")) {
if(me->query("skill_fengri-hammer")==0)
return action[random(6)];
if(random(2)) return action[random(6)];
return m_actions[random(sizeof(m_actions))];

} else {
return action[6];
}

      return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 50 )
                return
notify_fail("你的内力或气不够，没有办法练习封日锤。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍封日锤。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
return CLASS_D("youning") + "/fengri-hammer/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("fengri-hammer",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对封日锤的领悟加深了，你的浑天锤进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对封日锤领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_fengri-hammer");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+me->query_skill("unarmed",1)/5;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"砸伤"]);

   if(!arg||arg==" ")arg="封日锤绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_fengri-hammer",m_actions);
}
