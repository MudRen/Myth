// team command: dismiss

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object *t;

        if (! pointerp(t = me->query_team()))
                return notify_fail("�����ڲ�û�вμ��κζ��顣\n");

        if (me->is_team_leader())
        {
                message("team", me->name(1) + "�������ɢ�ˡ�\n", t, me);
                write("�㽫�����ɢ�ˡ�\n");
        } else
        {
                message("team", me->name(1) + "����������顣\n", t, me);
                write("����������Ķ��顣\n");
        }

        me->dismiss_team();
        return 1;
}

