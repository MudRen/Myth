// team command: form

#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object *t;

        if (! pointerp(t = me->query_team()) || ! me->is_team_leader())
                return notify_fail("�������һ����������������֯���Ρ�\n");

        if (! me->query_skill(arg, 1))
                return notify_fail("����������ûѧ����\n");

        return SKILL_D(arg)->form_array(me);
}

