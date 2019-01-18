
// scheme.c

#include <ansi.h>

inherit F_CLEAN_UP;

private void done_input(object me, string text);
private void user_quit(object me);
int  continue_scheme(object me);
int  cancel_schedule(object me);

int main(object me, string arg)
{
        object ob;
        object env;
        string schedule;

        if (wizardp(me) && 0)
                return 0;

        seteuid(getuid());

        if (! arg)
        {
                if (! stringp(schedule = me->query("schedule")))
                {
                        write("��Ŀǰ��û���ƶ��κμƻ���\n");
                        return 1;
                }

                write("��Ŀǰ�ƶ��ļƻ����£�\n" + schedule);
                return 1;
        }

        if (sscanf(arg, "show %s", arg) == 1)
        {
                if (! wizardp(me))
                        return notify_fail("����Ȩ�鿴�����ƶ��ļƻ���\n");

                if (! objectp(ob = find_player(arg)))
                        return notify_fail("û�������ҡ�\n");

                if (! stringp(schedule = ob->query("schedule")))
                {
                        write("������û���ƶ��ƻ���\n");
                        return 1;
                }

                write((ob == me ? "��" : (ob->name(1) + "(" + ob->query("id") + ")")) +
                      "�����ƶ��ļƻ����£�\n" + schedule);
                if (ob->query("doing") == "scheme")
                        write("�üƻ�Ŀǰ����ִ���С�\n");

                return 1;
        }

        if (arg == "clear")
        {
                if (me->query("doing") == "scheme")
                        return notify_fail("����������ִ�мƻ�������ͣ�������������\n");

                me->delete("schedule");
                write("Ok.\n");
                return 1;
        }

        if (arg == "edit")
        {
                if (me->query("doing") == "scheme")
                        return notify_fail("����������ִ�мƻ�������ͣ�������޸ġ�\n");

                write("�������㽫Ҫִ�еļƻ���\n");
                me->edit((: done_input, me :));
                return 1;
        }

        if (arg == "start")
        {
                if (! stringp(schedule = me->query("schedule")))
                        return notify_fail("��Ŀǰ��û���ƶ��ƻ���\n");

                if (me->query("doing"))
                        return notify_fail("����������æ�ڶ��������ܿ�չ�¼ƻ���\n");

                env = environment(me);
                if (! env)
                        return notify_fail("������ʲô�������ˡ�\n");

                if (env->is_chat_room())
                        return notify_fail("�㲻��������������ִ�мƻ���\n");

                if (! env->query("doing"))
                        return notify_fail("������ڹ涨�ķ������ִ�мƻ���\n");

                if (! env->query("sleep_room"))
                        return notify_fail("��������ܹ���Ϣ�ĵط�����ִ�мƻ���\n");

                if (! env->query("no_fight"))
                        return notify_fail("������ڰ�ȫ�ĵط�����ִ�мƻ���\n");

                if (me->query("combat_exp") < 50000)
                        return notify_fail("���ʵս����̫ǳ���������Ⱥúö���������˵�ɡ�\n");

                if (me->query("potential") - me->query("learned_points") < 100)
                        return notify_fail("���Ǳ��̫�٣����Կ�չ�ƻ���\n");

//                if (sizeof(filter_array(all_inventory(env), (: playerp :))) > 12)
//                        return notify_fail("�������ʵ��̫���ˣ������Ծ��Ŀ�չ�ƻ���\n");

                me->add("learned_points", 100);

                // ִ�мƻ�
                write("�㿪ʼִ�мƻ���\n");
                me->set("startroom", base_name(env));
                CLOSE_D->user_closed(me);
                me->set_short_desc(0);
                continue_scheme(me);
                return 1;
        }

        return notify_fail("�Ƿ������������\n");
}

// ��ʼִ�мƻ�
int continue_scheme(object me)
{
        string schedule;
        string *scs;

        if (! stringp(schedule = me->query("schedule")))
                return 0;

        scs = explode(schedule, "\n");
        scs = filter_array(scs, (: replace_string($1, " ", "\n") != "" :));
        if (sizeof(scs) < 1)
        {
                write("����һ�ݿռƻ�����ûʲô�����ġ�\n");
                return 0;
        }

        me->set("doing", "scheme");
        me->set_temp("scs", scs);
        me->set_temp("scs_step", 0);
        me->delete_temp("scs_repeat");
        me->set_override("unconcious", (: call_other, __FILE__, "cancel_schedule" :));
        me->set_override("die", (: call_other, __FILE__, "cancel_schedule" :));
        return 1;
}

// ��ֹ�ƻ�
int cancel_schedule(object me)
{
        me->delete_override("unconcious");
        me->delete_override("die");

        if (! me->query("schedule"))
                return 0;

        CLOSE_D->user_opened(me);

        if (! interactive(me))
                me->start_call_out((: call_other, __FILE__, "user_quit", me :), 0);

        return 0;
}

// ִ�мƻ���
void execute_schedule(object me)
{
        mapping my, my_temp;
        string *scs;
        int scs_step;
        string *scs_repeat;
        string cmd, cmd_case;
        int i;
        int count;
        int pay;

        if (! objectp(me) || previous_object() != me)
                return;

        if (me->is_busy() || ! living(me))
                return;

        my = me->query_entire_dbase();
        my_temp = me->query_entire_temp_dbase();

        if (time() - (int)my_temp["scheme_last_fail"] < 5)
                return;

        if (my["food"] < 100 || my["water"] < 100)
        {
                write("����ö����е���ˣ�����Ҫ�ҵ�ԵĶ����ˡ�\n");
                pay = 2000;
                if (me->query("family/family_name") == "���ϻ���")
                        pay = 100;
                else
                        pay = pay * 100 / (me->query_skill("higgling", 1) + 100);
                
                if (MONEY_D->player_pay(me, pay) != 1)
                {
                        write("�㷢���Լ�����Ǯ�����ˣ�����ֻ����ȥŪЩǮ�ˡ�\n");
                        cancel_schedule(me);
                        return;
                }
                write("���ͳ�һЩǮ������һλ������������׼����һЩʳ�\n");

                // ����ʳ���ˮ
                my["food"]  = me->max_food_capacity();
                my["water"] = me->max_water_capacity();
                me->start_busy(10 + random(10));
                return;
        }

        if (! arrayp(scs = my_temp["scs"]))
        {
                if (! continue_scheme(me))
                        cancel_schedule(me);
                return;
        }

        scs_step = my_temp["scs_step"];
        if (scs_step < 0 || scs_step >= sizeof(scs))
                scs_step = 0;

        // ȡ�� n ����
        cmd = scs[scs_step];
        if (sscanf(cmd, "%s:%s", cmd, cmd_case) != 2)
                cmd_case = "IGNORE";

        // ��ʾ׼��ִ�е�����
        tell_object(me, me->prompt() + HIY + cmd + NOR "\n");

        switch (cmd)
        {
        case "REPEAT":
                // ��ʼѭ��
                count = 1;
                for (i = scs_step + 1; i < sizeof(scs); i++)
                {
                        if (scs[i] == "LOOP")
                        {
                                if (--count < 1)
                                break;
                        }
                        if (scs[i] == "REPEAT")
                                count++;
                }

                if (count > 0)
                {
                        write("�ƻ��� repeat û���ҵ���֮ƥ��� loop ����޷�����ִ�С�\n");
                        cancel_schedule(me);
                        break;
                }

                if (! arrayp(my_temp["scs_repeat"]))
                        my_temp["scs_repeat"]  = ({ ({ scs_step, i }) });
                else
                if (sizeof(my_temp["scs_repeat"]) < 12)
                        my_temp["scs_repeat"] += ({ ({ scs_step, i }) });
                else
                {
                        write("ѭ��Ƕ�׵Ĳ��̫�࣬��ļƻ���ø��ӣ�ִ�в��ˡ�\n");
                        cancel_schedule(me);
                        break;
                }

                write("��ʼѭ��.\n");
                break;

        case "LOOP":
                // ѭ��ִ��
                if (! arrayp(scs_repeat = my_temp["scs_repeat"]) ||
                    sizeof(scs_repeat) < 1)
                {
                        write("û���ҵ��ƻ�����֮ƥ��� repeat ���\n");
                        cancel_schedule(me);
                        return;
                }

                scs_step = scs_repeat[sizeof(scs_repeat) - 1][0];
                write("Loop.\n");
                break;

        case "BREAK":
                // ������ѭ��
                if (! arrayp(scs_repeat = my_temp["scs_repeat"]) ||
                    sizeof(scs_repeat) < 1)
                {
                        write("û���ҵ��ƻ�����֮ƥ��� repeat-loop ���\n");
                        cancel_schedule(me);
                        return;
                }

                scs_step = scs_repeat[sizeof(scs_repeat) - 1][1];
                my_temp["scs_repeat"] = scs_repeat[0..<2];
                write("Ok.\n");
                break;

        default:
                // ִ�е� n ���������������һ���Ƿ�ִ�еڶ�����
                if (! me->force_me(cmd))
                {
                        // ִ��ʧ��ʱ������
                        if (cmd_case != "IGNORE")
                                tell_object(me, me->prompt() + HIY + cmd_case + NOR "\n");

                        switch (cmd_case)
                        {
                        case "RETRY":
                                my_temp["scheme_last_fail"] = time();
                                return;

                        case "CONTINUE":
                                // ѭ��ִ��
                                if (! arrayp(scs_repeat = my_temp["scs_repeat"]) ||
                                    sizeof(scs_repeat) < 1)
                                {
                                        write("û���ҵ��ƻ�����֮ƥ��� repeat ���\n");
                                        cancel_schedule(me);
                                        break;
                                }

                                scs_step = scs_repeat[sizeof(scs_repeat) - 1][0];
                                write("Loop.\n");
                                break;

                        case "BREAK":
                                // ������ѭ��
                                if (! arrayp(scs_repeat = my_temp["scs_repeat"]) ||
                                    sizeof(scs_repeat) < 1)
                                {
                                        write("û���ҵ��ƻ�����֮ƥ��� repeat-loop ���\n");
                                        cancel_schedule(me);
                                        break;
                                }

                                scs_step = scs_repeat[sizeof(scs_repeat) - 1][1];
                                my_temp["scs_repeat"] = scs_repeat[0..<2];
                                write("Ok.\n");
                                break;

                        case "IGNORE":
                                // ִ���������ʧ�����
                                break;

                        default:
                                me->force_me(cmd_case);
                                break;
                        }
                        // ����ʧ��ʱִ�� cmd_case ��ϡ�
                }
                // ִ������������
        }

        if (++scs_step >= sizeof(scs))
        {
                write("�ƻ�ִ����ϡ�\n");
                cancel_schedule(me);
                return;
        }

        my_temp["scs_step"] = scs_step;
}

private void done_input(object me, string text)
{
        string *strs;

        if (! stringp(text))
        {
                tell_object(me, "��û�������κ��µļƻ���\n");
                return;
        }

        if (strlen(text) > 400)
        {
                tell_object(me, "����ݼƻ�̫���ˣ�����������һ����һЩ�ġ�\n");
                return;
        }

        strs = explode(text, "\n");
        strs = filter_array(strs, (: replace_string($1, " ", "") != "" :));
        text = implode(strs, "\n") + "\n";

        me->set("schedule", text);
        tell_object(me, "��������һ���µļƻ���\n");
}

void user_quit(object me)
{
        if (! is_root(previous_object()) &&
            previous_object() != me)
                return;

        if (! objectp(me))
                return;

        me->force_me("quit");

        if (objectp(me) && ! interactive(me))
                me->start_call_out((: call_other, __FILE__, "user_quit", me :), 5);
}

int help (object me)
{
        write(@HELP
ָ���ʽ : scheme [<edit> | <start> | <clear> | <show> <���>]
 
�趨��ʼ��ļƻ����������Ҫ��ʱ��Ķ��������ϰ���ܣ�����
ʹ�üƻ�����ɣ�������μ� help schedule��

edit  : �趨�ƻ�
start : ��ʼִ�мƻ�
clear : ���Ŀǰ�ļƻ�
show  : ��ʾĳ����ҵļƻ���ֻ����ʦ����ʹ��������

ִ�мƻ��ڼ����ʹ�� halt ������ֹ�����ڽ��еļƻ���

see also: halt, breakup, purchase
HELP );
        return 1;
}

