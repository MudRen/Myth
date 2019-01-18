// practice.c
// modify by mudring

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string skillname;
    int skill, skill_basic, cnt = 1;
    object where = environment(me);

    seteuid(getuid());

    if (where->query("no_fight") ||
        where->query("no_magic"))
        return notify_fail("���ﲻ�������ĵط���\n");

    if (me->is_busy())
        return notify_fail("�����ں�æ��������ϰ��\n");

    if (me->is_fighting())
        return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

    if (!arg) return (__DIR__"enable")->main(me, arg);

    sscanf(arg, "%s %d", arg, cnt);
    if (!stringp(skillname = me->query_skill_mapped(arg)))
        return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

    skill_basic = me->query_skill(arg, 1);
    skill = me->query_skill(skillname, 1);

    if (skill < 1)
        return notify_fail("�����û��ѧ�᡹����ܰɣ������ȥ��̱��ˡ�\n");
    if (skill_basic < 1)
        return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");

    if (skill*skill*skill/10 > (int)me->query("combat_exp"))
        return notify_fail("�����ѧ��Ϊ��û��������磬�����ٶ�Ҳû�á�\n");

    notify_fail("�����ڲ�����ϰ����ܡ�\n");
    if (!SKILL_D(skillname)->valid_learn(me)) return 0;

    if(MISC_D->random_capture(me,20000,0)) return 1;

    notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");

    if (skill_basic <= skill && random(100) == 0)
        write("���" + to_chinese(skillname) + 
              "��������ˣ���������ʦ�������̰ɣ�\n");

    if (SKILL_D(skillname)->practice_skill(me))
    {
        write (HIY"��" + ((cnt == 1)?"����":"����") + "��ϰ" + to_chinese(skillname) 
            + "�����" + ((cnt == 1)?"����":"һЩ") + "�Ľ�����\n"NOR);
        me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill? 0: 1);
        while (--cnt)
        {
            if (SKILL_D(skillname)->practice_skill(me)) 
            me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill? 0: 1);
            else return 0;
        }
        return 1;
    }
    else return 0;
}

int help(object me)
{
        write(@TEXT
ָ���ʽ��practice <��������> <����>

���ָ��������ϰĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�

��������Ļ��������㹻�ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
TEXT
        );
        return 1;
}
