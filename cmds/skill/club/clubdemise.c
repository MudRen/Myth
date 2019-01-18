//clubdemise.c
//Edited by wuyou@sk_sjsj 2003-4-8

#include <ansi.h>

inherit F_CLEAN_UP;

int main(string arg)
{
    string club_name;
    object ob ,me;
    me=this_player();

    if (!me->query("club_master"))
        return notify_fail("ֻ�а���쵼�˲ſ����ô�λ�����\n");

    if (!arg)
        return notify_fail("��Ҫ�����ɴ�Ȩ�ƽ���˭��\n");

    if (sscanf(arg, "%s", arg) == 1)
        ob = present(arg, environment(me));
    else 
        return notify_fail("ָ���ʽ��clubdemise <ĳ��> \n");

    if (!ob)
        return notify_fail("����û������ˡ�\n");

    if (ob == me)
        return notify_fail("��������������αش�λ�أ�\n");

    if (!userp(ob) && !wizardp(me))
        return notify_fail("�������������\n");

    if (ob->query("club") != me->query("club") && !wizardp(me))
        return notify_fail("��ֻ�Ա��������ʹ���������\n");

    if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���أ�\n");

    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("�Է���æ���أ�\n");
    
    club_name=me->query("club");
    me->delete("club_master");
    me->set("club_level", 9);
    ob->set("club_level", 10);
    ob->set("club_master", 1);

    message_vision("$N��"+club_name+"����ָ��Ȩ�ƽ���$n��\n",me,ob);
    message( "channel:club",CYN+"��"+club_name+"��"+me->query("name")+"("+capitalize(me->query("id"))+")��"+club_name+"ָ��Ȩ�ƽ���"+ob->query("name")+"("+capitalize(ob->query("id"))+")��\n"NOR, users() );

    ob->save();
    me->save();
    return 1;
}


int help(object me)
{
write(@HELP
ָ���ʽ : clubdemise <ĳ��> 

����ͷ�콫����Ȩ�ƽ�����һ���ˡ�
HELP
    );
    return 1;
}


