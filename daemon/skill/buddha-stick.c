//南海普陀 释厄棍法 buddha-stick
//by junhyun@sk_sjsh
//2002.5.11

inherit SKILL;
#include <ansi.h>;
string* skill_head =({
        "$N口宣佛号，使出一招",
        "$N力由心发，平平一招",
        "$N身形一转，悠然一招",
        "$N不退反近，突然一招",
        "$N以棍做剑，单手一招",
        "$N脚踩连环，一连数招",

});

string* skill_tail =({
        "，手中$w破空之声大作，朝着$n砸将下来。",
        "，砸向$n，隐隐约约能听到风雷阵阵",
        "，越到$n身侧，手中$w如暴雨般点向$n",
        "，硬生生从$n身侧滑过，手中$w扫向$n的$l",
        "，棍棍不离$n周身大穴，打得$n手忙脚乱",
        "，手中$w幻做无数影子，从半空中击向$n",
});

mapping *action = ({
        ([      "name":                 "我佛慈悲",
                "action":
"$N口宣佛号，使出一招"+BLINK""+HIY"「我佛慈悲」"NOR+"，手中$w破空之声大作，朝着$n砸将下来",
                "dodge":                5,
     "parry":   -10,
                "damage":               65,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "金刚伏魔",
                "action":
"$N力由心发，平平一招"+BLINK""+HIY"「金刚伏魔」"NOR+"，砸向$n，隐隐约约能听到风雷阵阵",

                "dodge":                0,
     "parry":     0,
                "damage":               55,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "暴风骤雨",
                "action":
"$N身形一转，悠然一招"+BLINK""+HIY"「暴风骤雨」"NOR+"，越到$n身侧，手中$w如暴雨般点向$n",
                "dodge":                10,
     "parry":   -20,
                "damage":               75,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "舍身饲虎",
                "action":
"$N不退反近，突然一招"+BLINK""+HIW"「舍身饲虎」"NOR+"！硬生生从$n身侧滑过，手中$w扫向$n的$l",
                "dodge":               10,
     "parry":   -15,
                "damage":               35,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "回头是岸",
                "action":
"$N以棍做剑，单手一招"+BLINK""+HIB"「回头是岸」"NOR+"，棍棍不离$n周身大穴，打得$n手忙脚乱",
                "dodge":                -5,
     "parry":     -5,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),   
        ([      "name":                 "慈航普渡",
                "action":
"$N脚踩连环，一连数招"+BLINK""+HIB"「慈航普渡」"NOR+"，手中$w幻做无数影子，从半空中击向$n",
                "dodge":                5,
     "parry":   -10,
                "damage":               50,
                "damage_type":  "砸伤"
        ]),   

});


int valid_learn(object me)
{
        object ob;
     if( (string)me->query_skill_mapped("force")!= "lotusforce")
     return notify_fail("释厄棍法必须南海普陀的莲花心法才能练。\n");
        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法练释厄棍法，
多练些内力再来吧。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("你必须先找一根棍子才能练棍法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
   int i;
   mapping* m_actions;
   i=me->query_temp("QJB_perform");
   if( !me->query_temp("QJB_perform")) {
     if(me->query("skill_buddha-stick")==0) 
          return action[random(6)]; 
          if( random(4) == 1 ) 
          return m_actions[random(sizeof(m_actions))]; 
          else 
              
             return action[random(6)]; 
   }else {
     return action[i];
   }
}


int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习释厄棍法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
//        write("你默念佛号，练习了一遍释厄棍法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/buddha-stick/" + func;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("buddha-stick",1);       
   
   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对释厄棍法的领悟加深了，你的释厄棍法进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对释厄棍法领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_buddha-stick");
   if(!pointerp(m_actions))m_actions=({});
   
   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"砸伤"]);

   if(!arg||arg==" ")arg="释厄棍法绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIM"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_buddha-stick",m_actions);
}




