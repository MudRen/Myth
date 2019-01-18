//heal.c


#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中疗伤？找死吗？\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") == (int)me->query("max_kee") )
                return notify_fail("你气血圆满，不需要疗伤。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        message_vision(HIW"$N盘膝而坐，微闭双目，双手食指相对。"HIB"不一会，只见一阵幽蓝之气从指间渗出。\n"NOR, me);

        me->receive_curing("kee", 50 + (int)me->query_skill("force")/5 );
        me->receive_curing("sen", 50 + (int)me->query_skill("force")/5 );
        me->add("force", -50);

        return 1;
}


