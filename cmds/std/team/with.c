// team command: with

#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob;

        if (! arg ||
            ! (ob = present(arg, environment(me))) ||
            ! living(ob) ||
            ! ob->is_character() ||
            ob == me)
                return notify_fail("�����˭��Ϊ��飿\n");

        if (! pointerp(me->query_team()) || me->is_team_leader())
        {
                if (sizeof(me->query_team()) >= 12)
                        return notify_fail("����������������ʵ����̫��"
                                           "�ˣ���Ҷ��չ˲������ˡ�\n");

                if (me == ob->query_temp("pending/team"))
                {
                        if (! pointerp(me->query_team()))
                        {
                                ob->add_team_member(me);
                                message_vision("$N��������$n�Ķ��顣\n", me, ob);
                        } else
                        {
                                me->add_team_member(ob);
                                message_vision("$N������$n������顣\n", me, ob);
                        }
                        ob->delete_temp("pending/team");
                        return 1;
                } else
                {
                        message_vision("$N����$n����$P�Ķ��顣\n", me, ob);
                        tell_object(ob, YEL "�����Ը����룬���� team with " +
                                    me->query("id") + "��\n" NOR);
                        me->set_temp("pending/team", ob);
                        return 1;
                }
        } else
                return notify_fail("ֻ�ж����������������˼��롣\n");
}

