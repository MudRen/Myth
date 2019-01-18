// wizskill.c
// by mudring

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
    string objname, family;
    object obj;
    int level;
    object weapon;

    if (!SECURITY_D->valid_grant(me, "(wizard)")) 
         return 0; 

    seteuid(getuid());

    if (!arg)
        return notify_fail("ָ���ʽ��wizskill <���> <����> <����>\n");

    if (sscanf(arg, "%s %d %s", objname, level, family) != 3)
        return notify_fail("ָ���ʽ��wizskill <���> <����> <����>\n");

    obj = present(objname, environment(me));
    if (!obj) obj = find_player(objname);
    if (!obj) obj = find_living(objname);
    if (!obj) return notify_fail("û������ˣ�\n");

    if (!userp(obj))
        return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");

    if (userp(obj) && !wizardp(obj))
        return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");

    if ((obj != me) && !is_root(me))
        return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");

    if (!STATU_D->valid_family(family))
        return notify_fail("���ȼ�����û��������ɡ�\n");

    STATU_D->set_npc_skill(obj, level, family);
    weapon = STATU_D->family_weapon(family);
    weapon->move(obj);
    weapon->wield();
    write(WHT "wizskill " + getuid(obj) + " " + level +" " + family + " ok!\n"NOR);
    if (me == obj)
        message_vision(HIY "$N" HIY "���������дʣ������������"
            "���˰��첻�����Ʒ��塣\n" NOR, me);
    else
        message_vision(HIY "$N" HIY "���������дʣ������������"
            "���˰��첻�����Ʒ��塣\n" NOR, me, obj);

    seteuid(getuid(me));
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wizskill <���> <����> <����>

HELP
    );
    return 1;
}

