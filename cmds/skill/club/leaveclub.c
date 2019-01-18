//leaveclub.c
//Edited by wuyou@sk_sjsj 2003-4-8

#include <ansi.h>

inherit F_CLEAN_UP;

int main(string arg)
{
    string club_name;
    object me;
    me=this_player();

    if (!me->query("club"))
        return notify_fail("�㻹û���������ô�˰\n");

    if (me->query("club_master",1)==1)
        return notify_fail("������Ƚ����ɴ�Ȩת�Ƹ����˲����뿪��ᡣ\n");
  
    if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���أ�\n");
    
    club_name=me->query("club");

    me->delete("club");
    if (me->query("new_title"))
        me->delete("new_title"); 
    me->delete("newtitle");
    if (me->query("club_master,1")==1) 
        me->delete("club_master");

    message_vision("$N�����˳���"+club_name+"��\n",me);

    me->save();
    return 1;
}


int help(object me)
{
write(@HELP
ָ���ʽ : leaveclub  

�����뿪һ�����ɡ�
HELP
    );
    return 1;
}


