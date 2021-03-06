// jinshen.c 天魔金身

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        
	if( target != me ) 
                return notify_fail("你只能用天魔金身保护自己。\n");
//    加上门派判断by seng@2005-1-20
  if( me->query("family/family_name")!="三界山") 
    return notify_fail("天魔金身是三界山不传之密！\n");
        if( (int)me->query_skill("tianmogong", 1) < 40)
                return notify_fail("你的天魔功级别还不够，使用这一招会有困难！\n");
        if( (int)me->query_skill("huntianforce", 1) < 40)
                return notify_fail("你的混天宝鉴级别还不够，使用这一招会有困难！\n");
        if( (int)me->query("force") < 250 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经有金身保护了。\n");

        skill = me->query_skill("tianmogong",1);

        me->add("force", -250);
        me->receive_damage("kee", 10);

        message_vision(HIY"$N双目一睁，口中念念有词，浑身上下顿时被一片金光罩住，\n就如身穿天兵金甲，站在那里看起来威风凛凛。\n" NOR, me);

        me->add_temp("apply/armor", skill/2);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
       me->add_temp("apply/armor", - amount/2);
       me->delete_temp("powerup");
       tell_object(me, HIY"你的法力和内力渐渐减弱，金光渐渐消去了。\n"NOR);
}

