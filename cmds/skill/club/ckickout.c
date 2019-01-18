//ckickout.c
//Edited by wuyou@sk_sjsj 2003-4-8

#include <ansi.h>

inherit F_CLEAN_UP;

int main(string arg)
{
    string club_name;
    object ob ,me;
    me=this_player();

    if (!me->query("club_master") && !wizardp(me))
        return notify_fail("ֻ�а���쵼�˲ſ��Խ������߳����ɡ�\n");

    if (!arg)
        return notify_fail("��Ҫ��˭�߳����ɣ�\n");

    if (sscanf(arg, "%s", arg) == 1)
        ob = present(arg, environment(me));
    else 
        return notify_fail("ָ���ʽ��ckickout <ĳ��> \n");

    if (!ob)
        return notify_fail("����û������ˡ�\n");

    if (ob == me && !wizardp(me))
        return notify_fail("������Լ����뿪���ɣ�����leaveclub���\n");

    if (!userp(ob) && !wizardp(me))
        return notify_fail("�������������\n");

    if (ob->query("club") != me->query("club") && !wizardp(me))
        return notify_fail("��ֻ�Ա��������ʹ���������\n");

    if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���أ�\n");

    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("�Է���æ���أ�\n");
    
    club_name=me->query("club");

    ob->delete("club_level");
    ob->delete("club");
    if (ob->query("new_title")) 
        ob->delete("new_title"); 

    message_vision("$Nǿ��$n�˳���"+club_name+"��\n",me,ob);
    ob->save();

    return 1;
}


int help(object me)
{
write(@HELP
ָ���ʽ : ckickout <ĳ��> 

�������е�ĳ�˿�����
HELP
    );
    return 1;
}

