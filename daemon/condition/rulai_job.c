// rulai task busy condition...

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration <= 1) {
//  9          write(HIW"ڤڤ��������������㣺��������ħʢ���ˣ���\n"NOR);
        return 0;
        }
        me->apply_condition("rulai_job", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}
