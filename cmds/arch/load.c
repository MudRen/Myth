int main(object me, string arg)
{
        object user, where;
        string msg;
        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;
        if (!arg) return 0;
        if (wiz_level(me) < wiz_level(arg))
                return notify_fail("�㲻��װ����ʦ�������ߵ���ҡ�\n");

        where = environment(me);

        seteuid(arg);
        user = new(USER_OB);
        export_uid(user);
        user->set_name("", ({ arg }));
        if (!user->restore())
        { destruct(user); return notify_fail("û�������ҡ�\n");}
        user->setup();
        if( !stringp(msg = me->query("env/msg_clone")) )
                if ( where->query("outdoors") )
                        msg = "$n�첽���˹�����\n";
                else
                        msg = "$n���˹�����\n";

        message_vision(msg + "\n", me, user);
        user->move(where);
        return 1;
}

