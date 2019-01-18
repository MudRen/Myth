// edemote.c
// updated by doing
// modified by mudring@sjsh...

inherit F_CLEAN_UP;

int in_use;

int main(object me, string arg)
{
        mapping emote;
        int i;

        if (! SECURITY_D->valid_grant(me, "(immortal)"))
                return 0;

        seteuid(getuid());

        if (! arg) return notify_fail("��Ҫ�༭ʲô emote��\n");

        if (sscanf(arg, "-d %s", arg))
        {
                write("ɾ�� emote��" + arg + "\n");
                EMOTE_D->delete_emote(arg);
                log_file("cmds/edemote",
                sprintf("%s(%s) delete emote %s on %s.\n", 
                me->name(1), geteuid(me), arg, ctime(time()) ) );
                return 1;
        }

        if (sscanf(arg, "-p %s", arg))
        {
                        if (! mapp(emote = EMOTE_D->query_emote(arg)) ||
                    ! sizeof(emote))
                {
                        write("û��������鶯�ʡ�\n");
                        return 1;
                }

                write(sprintf("�ϴ��޸ģ�%s(%s)\n", emote["updated"], ctime(emote["time"])));
                write(sprintf("������������������������������������������\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
                      emote["myself"], emote["others"], emote["myself_self"],
                      emote["others_self"], emote["myself_target"], emote["target"],
                      emote["others_target"]));
                return 1;
        }

        if (arg == "-p") return notify_fail("���鶯�ʱ�������ĸ�����֡���㹹�ɡ�\n");
        write(sprintf("arg = %s\n", arg));
        for (i = 0; i < strlen(arg); i++)
                if (arg[i] <= 32 || arg[i] > 'z')
                        return notify_fail("���鶯�ʱ�������ĸ�����֡���㹹�ɡ�\n");

        log_file("cmds/edemote", sprintf("%s(%s) modify emote %s on %s.\n", 
                 me->name(1), geteuid(me), arg, ctime(time()) ) );
        emote = EMOTE_D->query_emote(arg);
        if (! mapp(emote)) emote = ([ ]);

        emote["updated"] = geteuid(me);

        write("�༭ emote��" + arg + "\n");
        write("ѶϢ�����кü��У��� . ��ʾ������\n"
              "���� x ��ʾ���в���ͬһ�����Ƶı���������\n");
        write("ѶϢ�п�ʹ�õĲ��������¼��֣�\n");
        write("  $N  �Լ������֡�\n");
        write("  $n  ʹ�ö�������֡�\n");
        write("  $P  �Լ����˳ƴ����ʣ����㡢�㡢����������������\n");
        write("  $p  ʹ�ö�����˳ƴ����ʣ����㡢�㡢����������������\n");
        write("  $S  ���Լ��ĳƺ���\n");
        write("  $s  ���Լ��Ĵ�³�ƺ���\n");
        write("  $C  ���Լ����سơ�\n");
        write("  $c  �Ա��˵��سơ�\n");
        write("  $R  �Ա��˵���ơ�\n");
        write("  $r  �Ա��˵Ĵ�³�ƺ���\n");
        write("������������������������������������������������������������������������\n");
        write("��ָ������ʹ����� emote ʱ�����Լ�������ѶϢ��\n->");
        input_to("get_msg_myself", emote, arg);
        return 1;
}


int get_msg_myself(string msg, mapping emote, string pattern, int n)
{
        msg = replace_string(msg, "\\n", "\n");
        if (msg == "." || msg == "x")
        {
                if (msg == "x")
                        map_delete(emote, "myself");
                else
                if (! n) write("���Ը���������\n");
                write("��ָ������ʹ����� emote ʱ�������˿�����ѶϢ��\n->");
                input_to("get_msg_others", emote, pattern);
                return 1;
        }

        if (! n) map_delete(emote, "myself");
        if (! undefinedp(emote["myself"]))
                emote["myself"] += msg + "\n";
        else emote["myself"] = msg + "\n";
        write("->");
        input_to("get_msg_myself", emote, pattern, n + 1);
        return 1;
}

int get_msg_others(string msg, mapping emote, string pattern, int n)
{
        msg = replace_string(msg, "\\n", "\n");
        if (msg == "." || msg == "x")
        {
                if (msg == "x")
                        map_delete(emote, "others");
                else
                if (! n) write("���Ը���������\n");
                write("���Լ�ʹ����� emote ʱ���Լ�������ѶϢ��\n->");
                input_to("get_msg_myself_self", emote, pattern);
                return 1;
        }

        if (! n) map_delete(emote, "others");
        if (! undefinedp(emote["others"]))
                emote["others"] += msg + "\n";
        else emote["others"] = msg + "\n";
        write("->");
        input_to("get_msg_others", emote, pattern, n + 1);
        return 1;
}

int get_msg_myself_self(string msg, mapping emote, string pattern, int n)
{
        msg = replace_string(msg, "\\n", "\n");
        if (msg == "." || msg == "x")
        {
                if (msg == "x")
                        map_delete(emote, "myself_self");
                else
                if (! n) write("���Ը���������\n");
                write("���Լ�ʹ����� emote ʱ�������˿�����ѶϢ��\n->");
                input_to("get_msg_others_self", emote, pattern);
                return 1;
        }

        if (! n) map_delete(emote, "myself_self");
        if (! undefinedp(emote["myself_self"]))
                emote["myself_self"] += msg + "\n";
        else emote["myself_self"] = msg + "\n";
        write("->");
        input_to("get_msg_myself_self", emote, pattern, n + 1);
        return 1;
}

int get_msg_others_self(string msg, mapping emote, string pattern, int n)
{
        msg = replace_string(msg, "\\n", "\n");
        if (msg == "." || msg == "x")
        {
                if (msg == "x")
                        map_delete(emote, "others_self");
                else
                if (! n) write("���Ը���������\n");
                write("�Ա���ʹ����� emote ʱ���Լ�������ѶϢ��\n->");
                input_to("get_msg_myself_target", emote, pattern);
                return 1;
        }

        if (! n) map_delete(emote, "others_self");
        if (! undefinedp(emote["others_self"]))
                emote["others_self"] += msg + "\n";
        else emote["others_self"] = msg + "\n";
        write("->");
        input_to("get_msg_others_self", emote, pattern, n + 1);
        return 1;
}

int get_msg_myself_target(string msg, mapping emote, string pattern, int n)
{
        msg = replace_string(msg, "\\n", "\n");
        if (msg == "." || msg == "x")
        {
                if (msg == "x")
                        map_delete(emote, "myself_target");
                else
                if (! n) write("���Ը���������\n");
                write("�Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ��\n->");
                input_to("get_msg_target", emote, pattern);
                return 1;
        }

        if (! n) map_delete(emote, "myself_target");
        if (! undefinedp(emote["myself_target"]))
                emote["myself_target"] += msg + "\n";
        else emote["myself_target"] = msg + "\n";
        write("->");
        input_to("get_msg_myself_target", emote, pattern, n + 1);
        return 1;
}

int get_msg_target(string msg, mapping emote, string pattern, int n)
{
        msg = replace_string(msg, "\\n", "\n");
        if (msg == "." || msg == "x")
        {
                if (msg == "x")
                        map_delete(emote, "target");
                else
                if (! n) write("���Ը���������\n");
                write("�Ա���ʹ����� emote ʱ�������Լ���ʹ�ö����⣬�����˿�����ѶϢ��\n->");
                input_to("get_msg_others_target", emote, pattern);
                return 1;
        }

        if (! n) map_delete(emote, "target");
        if (! undefinedp(emote["target"]))
                emote["target"] += msg + "\n";
        else emote["target"] = msg + "\n";
        write("->");
        input_to("get_msg_target", emote, pattern, n + 1);
        return 1;
}

int get_msg_others_target(string msg, mapping emote, string pattern, int n)
{
        msg = replace_string(msg, "\\n", "\n");
        if (msg == "." || msg == "x")
        {
                if (msg == "x")
                        map_delete(emote, "others_target");
                else
                if (! n) write("���Ը���������\n");
                emote["time"] = time();
                EMOTE_D->set_emote(pattern, emote);
                write("Emote �༭������\n");
                return 1;
        }

        if (! n) map_delete(emote, "others_target");
        if (! undefinedp(emote["others_target"]))
                emote["others_target"] += msg + "\n";
        else emote["others_target"] = msg + "\n";
        write("->");
        input_to("get_msg_others_target", emote, pattern, n + 1);
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : edemote [-d|-p] <emote>

���ָ������޸ģ�ɾ�� emote ���г������ݡ� ���� -d ������ɾ
��ָ���� emote��-p ��������г�ָ�� emote ������. �г���˳��
��༭ emote ʱ��ͬ.
 
���� emote ѶϢʱ��������Ŀ��û��Ŀ�꣬ ָ��Ŀ����Ƕ��Լ���
�������޸�ĳ��ѶϢ����ֱ���ڿհ������� '.' ����.
 
һ�� emote ѶϢ�����кܶ���, �ڿհ������� '.' ��ʾ���������
�� emote.
 
�༭ emote ʱ���������µķ�������ʾ:
 
$N : �Լ�������.
$n : Ŀ�������.
$P : �Լ����˳ƴ�����.
$p : Ŀ����˳ƴ�����.
$S : ���Լ��ĳƺ���
$s : ���Լ��Ĵ�³�ƺ���
$C : ���Լ����سơ�
$c : �Ա��˵��سơ�
$R : �Ա��˵���ơ�
$r : �Ա��˵Ĵ�³�ƺ���

���ڱ��鶯�ʻ��ڰ汾ͬ��ʱ���£����ֻ�а汾����վ����ܹ�ʹ
��������

see also��edemote��rnemote
HELP );
    return 1;
}

