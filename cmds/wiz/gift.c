// gift.c
// mudring@sjsh
 
#include <ansi.h>

inherit F_CLEAN_UP;

string display_attr(string gift, int value,int effective);
string type;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    mapping my;
    string ob_id, flag;
    string str1, str2, str3, str4, str5;
    int i;
    object ob;
        if (! SECURITY_D->valid_grant(me, "(wizard)")) return 0;
 
    seteuid(getuid(me));

    if (!arg) ob=me;
    if (!ob) ob = present(arg, environment(me));
    if (!ob) ob = find_player(arg);
    if (!ob) ob = find_living(arg);
    if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
    my = ob->query_entire_dbase();
str1 = "  ��������  "+ob->name()+"  ���Ա�  "+ob->query("gender")+"  ���ɣġ�  "+ob->query("id");
str2 = "  ����ò��  "+ob->query("per")+"  ����ʶ��  "+ob->query("cor")+"  ��������  "+ob->query("cps")+"  ����Ե��  "+ob->query("kar");
str3 = "  �����  "+ob->query("str")+"  ����ǡ�  "+ob->query("con")+"  �����ԡ�  "+ob->query("int")+"  �����ԡ�  "+ob->query("spi");
str4 = "  ���Уˡ�  "+ob->query("PKS")+"  ���Σˡ�  "+ob->query("MKS")+"  ����·��  "+ob->query("ziyouchoose");
str5 = "  ����Ǯ��  "+(ob->query("donation")/1000000)+"  �����١�  "+ob->query("life/life_time")+"  ��������  "+ob->query("rsg_eaten");
tell_object(me, WHT"��Ҫ�����Ϣ����:\n"+str1+"\n"+str2+"\n"+str3+"\n"+str4+str5+"\n"NOR);

    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ��gift [-o] <��������>
 
���ָ�������ʾ���ָ�����󣨺�������츳��

-o (original) ��ʾ����츳������literate�ȵ�Ч������
see also : score
HELP
    );
    return 1;
}

