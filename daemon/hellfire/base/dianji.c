
#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

#include <magic_power.h>

string get_name(){return "电击术";}//法术名称
string get_help()                  //法术说明,以后直接help,方便修改
{
        return "这个法术可以施展电击术，每个角色攻击力不同,攻击是固定的。\n
此法术初期所用，需要一定的法力和魔法点１， 攻击效率由高至低排列如下：\n
魔法师 终结者 精灵族 暗黑地狱使者 剑侠 野蛮人。";
}

int do_cast(object me,object target)
{
        string helltype;
        int damage;
        
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        {
                tell_object(me,"你没在战斗中！\n");
                return 1;
        }
        
        if(me->query("mana")<300)
        {
                tell_object(me,"你的法力太少了，恐怕用不了这个法术!\n");
                return 1;
        }
        
        if(me->is_busy())
        {
                tell_object(me,"你正忙着呢!\n");
                return 1;
        }
        
        if(me->query("magic_pointed")<50)
        {
                tell_object(me,"你的魔法点太少了，恐怕用不了这个法术!\n");
                return 1;
        }
        
        helltype=me->query("hell_type");
        if(!helltype) helltype="野蛮人";
        if(!userp(me)) return 1;
        me->add("mana",-2* (120-magic_power[helltype]));
        me->add("magic_pointed",-(120-magic_power[helltype])/10);
        message_vision(HIC "$N手指似爪双手伸向$n，顿时手指发出电芒向$n击去！\n" NOR,me,target);
        damage=100-magic_power[helltype];
        if(random((100-magic_power[helltype])*6) > (50+target->query("level"))/2 )
        {
                target->receive_damage("kee", damage*5+random(damage),me);
                target->receive_wound("kee", damage*2+random(damage),me);

                COMBAT_D->report_status(target, 0);
                me->strat_busy(random(3)+1);

        }
        else
        {
                message_vision(CYN "$N的电芒檫过$n，$n顿时吃了一惊！\n" NOR,me,target);

        }
        me->start_busy(random(2)+1);
        target->kill_ob(me);
        return 1;
}

