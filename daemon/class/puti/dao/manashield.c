#include <ansi.h>

string get_name(string str)
{
        str="法力盾";
        return str;
}

string get_help(string str)                
{
        str="指令：ｃａｓｔ　ｍａｎａｓｈｉｅｌｄ\n"
        +"条件：道家仙法100级，最大法力1000"
        +"增加自己的防御力！";
        return str;
}

int cast(object me, string spl,object target)
{
        int skill,flag;

        if( me->query_temp("apply/manashieldflag") )
                return notify_fail("你你现在正处于法力盾状态。\n");
                
        if (!PFM_D->valid_family(me, "方寸山三星洞"))
                return notify_fail("你是哪儿偷学来的武功，也想用「法力盾」?\n");

        if( (int)me->query("mana") < 300 )
                return notify_fail("你的法力不够使用法力盾，一次要耗300法力！\n");
                
        if( (int)me->query("max_mana") < 1000 )
                return notify_fail("你的法力修为不够使用法力盾!\n");
        
        
        skill = me->query_skill("dao",1);
        if(skill<100)
                return notify_fail("你的道家仙法修为还不够！\n");

        me->add("mana", - 300);

        message_vision(
                HIM "$N闭著眼睛默默念了几句咒语，只见你双手一挥，一个闪亮的半透明盾牌出现在$N的面前！\n" NOR, me);

        me->set_temp("apply/manashieldflag", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (skill/2)+30);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me)
{
        me->delete_temp("apply/manashieldflag");
        tell_object(me,HIM "你面前的法力盾渐渐消失了！\n" NOR);
}

