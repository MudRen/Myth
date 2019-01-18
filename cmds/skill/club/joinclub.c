//joinclub.c
//modified buy Wuyou@sk_sjsh 2003-4-9
 
#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string club, id;

        if(!arg) 
                return notify_fail("��Ҫ��˭��������ɣ�\n");

        ob = present(arg, environment(me));

        if(!ob) 
                return notify_fail("����û������ˡ�\n");

        if (ob == me)
                return notify_fail("�㲻�����Լ�������ɡ�\n");
     
        if (!userp(ob) && !wizardp(me))
                return notify_fail("ֻ�ܶ����������ɣ�\n");
         
        if(me->query("club"))  
                return notify_fail("���Ѿ�����ĳ�������ˡ�\n");
              
        if(!ob->query("club")) 
                return notify_fail("�Է��ƺ���û�вμӰ�ᡣ\n");
        
        id = ob->query("id");

        if(me->query_temp("joinclub") == id) 
                return notify_fail("���Ѿ��������, �Է����ڿ����С�\n");
        message_vision("$N��ʽ��$n����������Ҫ��\n",me,ob);
        tell_object(ob,"�����ͬ��Է�����, ���� capprove "+me->query("id")+" ָ��������\n");
        me->set_temp("joinclub",id);
        return 1;
}
                          
int help(object me)
{
        write(@HELP
ָ���ʽ : 
           joinclub <����id> 
           
���ָ���������Է��������ᡣ


HELP
    );
    return 1;
}

