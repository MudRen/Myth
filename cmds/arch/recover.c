
// recover.c
// �ָ�����
// by mudring
// ����������ʧ����.
// ֻ�ָܻ�һ��������ʧ���ظ�ʹ����Ч

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int i, j, k;
    object victim;
    string reason;

    if (!SECURITY_D->valid_grant(me, "(arch)"))
        return 0;

    if (!arg)
        return notify_fail("��Ҫ��ʲô��\n");

    if (sscanf(arg, "%s because %s", arg, reason) != 2)
        return notify_fail("recovers <id> because <xxx>��\n");

    seteuid(getuid());

    if (!objectp(victim = present(arg, environment(me))) || !userp(victim))
        return notify_fail("��ֻ�ָܻ�ʹ���ߵ���ʧ��\n");

    i = victim->query("death/combat_exp_loss");
    j = victim->query("death/dx_loss");
    k = victim->query("death/skill_loss");

    victim->add("combat_exp", i);
    victim->add("daoxing", j);

    while (k--)
    {
        victim->skill_death_recover();
    }

    if ((int)victim->query("potential") > (int)victim->query("learned_points"))
        victim->add("potential",
                    ((int)victim->query("potential") 
                     - (int)victim->query("learned_points") ) * 4 / 5);

    victim->set("death/combat_exp_loss", 0);
    victim->set("death/dx_loss", 0);
    victim->set("death/skill_loss", 0);
    victim->set("die_reason", "�Ѿ���" + me->query("name") + getuid(me) +"�ָ�");
    victim->save();

    message_vision(HIY "\n$N��ָ����һ�������¶�ʱ��ɫ��"
                   "��ս���һ���߲ʹ⻪������$n��\n\n" NOR,
                   me, victim);

    message_vision(HIM"ͻȻ����մ���һ�����: ���˾��������޸�������ݣ�\n"NOR,
                   me, victim);

    message_vision(HIR "\n$N˵����$n�������������ָ���ʧ�������Ѿ���¼�ڰ���\n\n" NOR,
                   me, victim);

    write(CYN"ʹ����"HIR + victim->name(1) + NOR CYN"�ϴ�������ʧ�ָ��ˡ�\n"NOR);
    tell_object(victim,
        CYN"��ʦ"HIR + me->name(1) + NOR CYN"�ָ������ϴε�������ʧ��\n"NOR);

    if (userp(victim) && !wizardp(victim))
        log_file("static/RECOVER", sprintf("%s Got recovered by %s because %s at %s.\n",
                 getuid(victim), getuid(me), reason, log_time()));

    seteuid(getuid(me));
    return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ��recover <ʹ��������> because <ԭ��>
HELP
        );
    return 1;
}

