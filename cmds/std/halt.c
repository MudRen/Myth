// halt.c

#define SCHEME_CMD      "/cmds/usr/scheme"

int main(object me, string arg)
{
        object ob;

        if( arg && wizardp(me) ) {
                ob = present(arg, environment(me));
                if( !ob ) return notify_fail("û��������\n");
                if( !ob->is_fighting() ) return notify_fail(ob->name()+"���ڲ�æ��\n");
                ob->remove_all_enemy();
                message_vision("\n$N����ʦ������ֹͣ��$n��ս����\n", me, ob);
                return 1;
        }

        if (me->query("doing") == "scheme")
        {
                // ִ�мƻ��У���ֹ
                write("�������ֹ�ƻ���\n");
                SCHEME_CMD->cancel_schedule(me);
                if (! me->is_busy())
                        return 1;
        }

        if (me->is_busy() && ! intp(me->query_busy()))
        {
                me->interrupt_me(me);
                return 1;
        } else
        if (me->is_fighting())
        {
                me->remove_all_enemy(0);
                message_vision("$N�������һԾ������սȦ�����ˡ�\n", me); 
                if (objectp(ob = me->query_competitor()) &&
                    ! ob->is_fighting(me))
                {
                        ob->win();
                        me->lost();
                }
                return 1;
        }
        else
        if (me->is_busy())
                return notify_fail("������ͣ��������\n");
        else
                return notify_fail("�����ڲ�æ��\n");

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : halt

��ֹ��Ŀǰ�����������飬������������ɻ�����ĳЩ���������
��ͱ������ڶ��֣����������������ͣ�֣���Ȼǰ���ǶԷ�����
��ɱ���㣬����ʹ����������û��Ч����

��������ں��˱�����ǽ�����ս���Ҳ����Ǽ�������ʽ�������
���Ϊ���䴦��

�������ָ��: accept, fight, hit, scheme

HELP );
        return 1;
}

