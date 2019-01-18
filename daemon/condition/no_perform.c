// no_perform.c

#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("no_perform", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "busy";
}

