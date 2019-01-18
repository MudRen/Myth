// vi.c
// modify by mudring

#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;
inherit "/feature/vi";

int main(object me, string file)
{
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        if (! file)
                return notify_fail("ָ���ʽ��edit <����>\n");

        if (in_edit(me))
                return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");

        seteuid(geteuid(me));
        file = resolve_path(me->query("cwd"), file);

        if (!(int)SECURITY_D->valid_write(file,me,"write"))
                return notify_fail("��û���㹻�Ķ�дȨ����\n");

        foreach (object user in users())
        if (file == "/"+in_edit(user) )
                return notify_fail("�����ͻ��"+user->name(1)+"("+capitalize(user->query("id"))+")"+"���ڱ༭���ļ�("+file+")��\n");

        MONITOR_D->report_adm_object_msg(me,HIR" edit " + file + "!"NOR); 
        log_file("cmds/edit/"+geteuid(me), sprintf("Vi %s at %s from %s.\n",
                                        file, log_time(),
                                        query_ip_number(me)));

        printf("�༭�ļ���%s\n",file);
        me->set("cwf", file);
        SECURITY_D->backup_file(file);
        start_edit(file);

        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : edit <����>, edit here

���ô�һָ���ֱ�������ϱ༭������
�� LPMud ȫөĻ�༭�� ��1.3 �� 3/25/1998  by л����(Kenny Hsieh), ��Ȩ����.

a            ���α��������               d  Ctrl-D    ɾ������
f  Ctrl-Z    ���»���                     g  Ctrl-G    �����ض���ȥ
h  Ctrl-J    �α�������һ��               i            ���α�ǰ�����
j  Ctrl-K    �α�������һ��               k  Ctrl-O    �α�������һ��
l  Ctrl-L    �α�������һ��               m            �����¹��ܼ�
n  Ctrl-N    ��Ѱ/�滻�¸������ִ�        o            ���α���¼�һ����
q  Ctrl-Q    �뿪�༭��                   r  Ctrl-R    �ִ��滻
s  Ctrl-S    �ִ���Ѱ                     u            ȡ��ĳ���ܼ�����
w  Ctrl-W    ���浵��                     x  Ctrl-X    ɾ���α��ϵ���
A  Ctrl-A    ���α��Ƶ�����               B  Ctrl-B    ���Ͼ�һҳ��22 �У�
E  Ctrl-E    ���α��Ƶ���β               F  Ctrl-F    ���¾�һҳ��22 �У�
J  Ctrl-P    ���������ֽӵ���������       O            ���α��Ϸ���һ����
U  Ctrl-U    ���α��Ƶ���ͷ               V  Ctrl-V    ���α��Ƶ���β
.            �ظ��ϸ�ָ��                 ?  Ctrl-Y    �������棨�˻��棩
~  Ctrl-T    ���α�ǰ�����һ����!����Ԫ

�Ϸ��Ķ�����ǿ�ӡ��ĸ�� ESC��F1��F12��BACKSPACE��TAB��ENTER��INSERT��DELETE��
HOME��END��PAGEUP��PAGEDOWN��UP��DOWN��LEFT��RIGHT��Ctrl-A��Ctrl-Z��

��ӭ�����˱༭�������뱣����Ȩ���棬���κ�����ͽ����������ң�
kenny@cindy.cis.nctu.edu.tw��
���ʹ��Netterm�༭�ļ���
HELP
    );
    return 1;
}

