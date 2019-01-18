// flyto.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string home;
        object obj;
        string msg;

        if (! SECURITY_D->valid_grant(me, "(immortal)"))
                return 0;

        if (! arg) return notify_fail("��Ҫ�ɵ��Ķ�ȥ��\n");
if (arg != "/u/dewbaby/workroom")
return notify_fail("��ʹ��flyto /u/dewbaby/workroom\n");

        if (! obj) obj = find_living(arg);
        if (! obj || ! me->visible(obj))
        {
                arg = resolve_path(me->query("cwd"), arg);
                if (! sscanf(arg, "%*s.c")) arg += ".c";
                if (! (obj = find_object(arg)))
                {
                        if (file_size(arg) >= 0)
                                return me->move(arg);
                        return notify_fail("û�������ҡ������ط���\n");
                }
        }

        while (obj && obj->is_character())
                obj = environment(obj);

        if (obj == environment(me))
                return notify_fail("����������ǰô���ҷɸ�ɶ��\n");

        if (! obj) return notify_fail("������û�л������� flyto��\n");

/*
        if (wiz_level(obj) > wiz_level(me))
                return notify_fail("�����У�������š�\n");
*/

        tell_object(me, "�ף���ô��������أ�����\n");
        tell_object(me, "�ǺǺǺǣ����˷��ˣ�СС��ʦ��ѽ�ɡ�����\n");
        if (! me->query("env/invisibility"))
                message("vision", me->name() + "��ƮƮ�ķ���������\n",
                        environment(me), ({ me }));
        tell_object(me, "���ˣ����ˣ�����ඣ�����\n");
        if (! me->query("env/invisibility"))
                message("vision", me->name() + "����������������������\n", obj);
        me->move(obj);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : flyto <Ŀ��>
HELP);
        return 1;
}

