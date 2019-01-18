// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;

        if( !arg ) return notify_fail("ָ���ʽ��follow <ĳ��>|none��\n");

        if( arg=="none")
                if( me->query_leader() ) {
                        me->set_leader(0);
                        message_vision("$N�����Լ������ж���\n", me);
                        return 1;
                } else {
                        write("�����ڲ�û�и����κ��ˡ�\n");
                        return 1;
                }

        if( !objectp(ob = present(arg, environment(me))) )
                return notify_fail("����û�� " + arg + "��\n");

        if( !ob->is_character() )
                return notify_fail("ʲô������...." + ob->name() + "��\n");

        if( ob==me )
                return notify_fail("�����Լ���\n");

        if (ob == me->query_leader())
         return notify_fail("���Ѿ��������ˡ�\n");
        if (ob->query_leader()== me)
         return notify_fail("�����������ء�\n");
        me->set_leader(ob);
//          message_vision("$N������ʼ����$nһ���ж���\n", me, ob);
        tell_object(me, "�������ʼ����" + ob->name() +"һ���ж���\n");
        if (ob->visible(me)) 
                tell_object(ob, me->name() + "������ʼ������һ���ж���\n");


        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : follow [<����>|none]
 
���ָ�������ܸ���ĳ�˻����
������� follow none ��ֹͣ���档
 
HELP
);
        return 1;
}

