// shout.c
// modify by mudring

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    if (!wizardp(me))
    {
        if ((int)me->query_skill("force", 1) < 300)
            return notify_fail("��ĵ�������Ϊ����������޷���Х��\n");

        if (me->query("combat_exp") < 10000000) 
            return notify_fail("�����ѧ��Ϊ����������޷���Х��\n");

        if ((int)me->query("force") < 7000)
            return notify_fail("����������㣬�޷�������Х��\n");
if( me->query("id") == "byc" )
return notify_fail("�������п�Ϊ�����������ɻ\n");

        if (!arg)
            return notify_fail("����Ҫ���ʲô��\n");

        if (arg && strlen(arg) > 126)
            return notify_fail("ȥ���ɣ��㣡����flood��\n");

        shout(HIW + me->name() +  "������Х��" + arg + "\n" NOR);
        write(HIW "��������Х��"+ arg + "\n" NOR);
        me->add("force", -6000);
    } else
    {
        if (!arg)
            return notify_fail("����Ҫ���ʲô��\n");

        shout(HBYEL + me->name() +  "������Х��" + arg + "\n" NOR);
        write(HBYEL "��������Х��"+ arg + "\n" NOR);
    }

    return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
see also : tune
HELP
    );
    return 1;
}
