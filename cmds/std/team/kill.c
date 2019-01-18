//
// team command: kill

#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object env;
        object obj;
        object tob;
        object *t;

        // team kill ����ʹ�õı�־
        int kill_flag;
        int want_kill_flag;

        t = me->query_team();
        if (! arrayp(t))
                return notify_fail("���������������"
                                   "û�б��ˣ�����־�ֱ����KILL����ɡ�\n");

        if (! me->is_team_leader())
                return notify_fail("ֻ�ж���������������������ˡ�\n");

        if (! arg)
                return notify_fail("����������鹥��˭��\n");

        env = environment(me);
        t = filter_array(t, (: objectp($1) && living($1) &&
                               environment($1) == $(env) :));
        if (! sizeof(t))
                return notify_fail("���������������"
                                   "û�����ܹ�����ĺ�����ǿ��Լ��ɡ�\n");

        if (env->query("no_fight"))
                return notify_fail("���ﲻ��ս����\n");

        if (! objectp(obj = present(arg, env)))
                return notify_fail("���빥��˭��\n");

        if (! obj->is_character() || obj->is_corpse())
                return notify_fail("������ˣ��ǲ��ǻ��ˣ�\n");

        if (obj == me)
                return notify_fail("ʲô����Ҫ��ɱҲ��Ҫ������ô���˰���\n");

        if (member_array(obj, me->query_team()) != -1)
                return notify_fail("���빥�������е��ˣ�����û�˻�����Ļ���\n");

        if (obj->query("can_speak"))
        {
                if (random(3) > 1)
                        message_vision("\n$N����������������ϰ����Ը�" + obj->name() +
                                       "�����˲��ؽ���ʲô�������壡��\n\n",
                                       me, obj);
                else
                        message_vision("\n$N����ɤ�Ӻ���������Ҳ���"
                                       "���ϰ���һ�����" + obj->name() +
                                       "��" + RANK_D->query_rude(obj) +
                                       "����\n\n", me, obj);
        } else
                message_vision("\n$Nһ���֣��ȵ�������������������\n\n",
                               me, obj);

        switch (obj->accept_kill(me))
        {
        case 0:
                return (! objectp(obj));
        case -1:
                if (objectp(obj) &&
                    ! me->is_killing(obj->query("id")))
                {
                        // ��Ϊĳ��ԭ��ս��û�з���
                        return 1;
                }
        default:
        }

        // ս���Ѿ����������������е��˲���ս��
        message("vision", HIR "��ʹ��һ�����" + me->name(1) +
                          HIR "������ȥ��Χ��" + obj->name() +
                          "����һ���ҿ���\n" NOR, t, ({ me }));

        // �ж��Ƿ�������������ɱ���Է�
        if (userp(me) && userp(obj))
        {
                // �Է���ɱ�����˺����Ƕ����еĳ�Ա
                string *obj_wants;
                object *all_team;

                // ����ȡ�������Ա - ��Ϊ�������ε��ĳ�Ա
                // û�а����� t �����С�
                all_team = me->query_team();
                all_team -= ({ 0 });
                obj_wants = obj->query_want() - ({ 0 });
                if (sizeof(obj_wants - t->query("id")) != sizeof(obj_wants))
                {
                        // �Է���ɱ�����Ƕ����е�ĳһЩ�ˣ�
                        // �����Ϊ�ǶԷ���ɱ�����ǣ�����
                        // ��֮
                        want_kill_flag = 0;
                } else
                {
                        me->want_kill(obj);
                        want_kill_flag = 1;
                }
        }

        // �ж϶Է��Ƿ��ɱ����
        if (living(obj) && ! userp(obj))
        {
                // �Է���ɱ������
                obj->kill_ob(me);
                kill_flag = 1;
        } else
        {
                // �Է�����ɱ�����ǣ�ֻ�ǹ�������
                obj->fight_ob(me);
                kill_flag = 0;
        }

        // �������������е���
        foreach (tob in t)
        {
                // ɱ�˷���Ͷӳ�����һ�£�����Է�
                // �������������е�ĳһ���ˣ�������
                // �ǶԷ�����
                if (want_kill_flag)
                        tob->want_kill(obj);

                tob->kill_ob(obj);

                // ���ö��ֵĹ���״̬�Ͷӳ�����һ��
                if (kill_flag)
                        obj->kill_ob(tob);
                else
                        obj->fight_ob(tob);
        }

        return 1;
}

