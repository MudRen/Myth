//技能医术 by koker@sjsh 2001
/*三界神话V2.0版本*/
 
inherit SKILL;
int valid_enable(string usage)
{
        return usage=="literate";
}

#include <ansi.h>

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("level") < 5 )
    return notify_fail(""HIW"你的等级不够还不能学习医术."NOR"\n");

   if ((int)me->query_skill("medical", 1) + 1>800)//最高可以学到800级
    return notify_fail(""HIW"你已得医术的精髓了，不用在学了。"NOR"\n");

   if ((int)me->query_skill("medical", 1)*6 > ( (int)me->query("level")+4))
//从5-100等级每一级等级可以学4级医术技能。100以后每升一个等级可以学2级医术
    return notify_fail(""HIW"你的等级不够,不能继续学习医术这样技能了。"NOR"\n");

   return 1;
}




