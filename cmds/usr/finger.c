// finger.c
// modify by mudring

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object);
void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
    object *ob;

    if (!arg)
    {
        if (!wizardp(me))
            return help(me);     
        me->start_more( FINGER_D->finger_all() );
    } else
    if (arg == "-m")
    {
        if (!wizardp(me))
            return notify_fail("����Ȩʹ�� -m ������\n");
        ob = filter_array(users(), (: $1->name() != $1->name(1) :));
        me->start_more(FINGER_D->user_list(ob), 0);
    } else
    if (arg == "-z")
    {
        if (!wizardp(me))
            return notify_fail("����Ȩʹ�� -z ������\n");
        ob = filter_array(users(), (: metep($1) :));
        me->start_more(FINGER_D->user_list(ob), 0);
    } else
    if (arg == "-i")
    {
        if (!wizardp(me))
            return notify_fail("����Ȩʹ�� -i ������\n");
        ob = filter_array(users(), (: $1->query("env/invisibility") :));
        me->start_more(FINGER_D->user_list(ob), 0);
    } else
    if (arg == "-k")
    {
        if (!wizardp(me))
            return notify_fail("����Ȩʹ�� -k ������\n");
        ob = filter_array(users(), (: $1->query_condition("no_pk_time") :));
        me->start_more(FINGER_D->user_list(ob), 0);
    }
    else
    {
        arg = replace_string(arg, "#", " ");
        arg = replace_string(arg, ".", " ");

        if ((int)me->query("sen") < 15)
            return notify_fail("��ľ����޷����С�\n");
        if (!wizardp(me))
            me->receive_damage("sen", 15);
        write(FINGER_D->finger_user(arg));
    }

    return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ��
           finger [ʹ����Ӣ�Ĵ���]
           finger [ʹ����Ӣ�Ĵ���]@Mudname
 
 
���ָ�����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
�������ʦ������Բ����κβ������鿴��������
��ҵ����ϡ�
see also : who, mudlist
HELP
    );
    return 1;
}
