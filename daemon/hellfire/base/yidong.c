#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

#include <magic_power.h>

string get_name(){return "移动术";}//法术名字
string get_help()                  //法术说明以后直接help,方便修改
{
        return "这个法术可以让你在房间内随机移动方位,需要一定的法力１";
}

int do_cast(object me,object target)
{
        string helltype;
        
        if(me->is_fight())
        {
                tell_object(me,"你在战斗中，忙着呢！\n");
                return 1;
        }
        
        if(me->query("mana")<300)
        {
                tell_object(me,"你的法力太少了，恐怕用不了这个法术!\n");
                return 1;
        }
        
        helltype=me->query("hell_type");
        if(!helltype) helltype="野蛮人";
        if(!userp(me)) return 1;
        me->add("mana",-2* magic_power[helltype]);
        me->set_temp("position/yy",18+random(5));
        me->set_temp("position/xx",18+random(5));
        me->command("fangwei");
        return 1;
}

