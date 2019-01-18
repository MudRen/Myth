//capprove.c
//modified buy Wuyou@sk_sjsh 2003-4-9
 
#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string club_name;
        me=this_player();
     
        if (!me->query("club_master") && !wizardp(me))
                return notify_fail("ֻ�а���쵼�˲ſ��Խ��ܳ�Ա��\n");

        if(!arg) 
                return notify_fail("��Ҫ����˭��\n");

        ob = present(arg, environment(me));

        if(!ob) 
                return notify_fail("����û������ˡ�\n");

        if (ob == me)
                return notify_fail("�㲻�ܽ����Լ�����ɡ�\n");
     
        if (!userp(ob) && !wizardp(me))
                return notify_fail("��ֻ�ܽ���������ᣡ\n");
                       
        if(ob->query("club")) 
                return notify_fail("�Է��ƺ��Ѿ�������ĳ����ᡣ\n");
        
        if(ob->query_temp("joinclub") != me->query("id") )
                return notify_fail("�Է���û������������ᡣ\n");
   
        club_name=me->query("club");

        message_vision("$N�������ؿ��ǣ�ͬ����$n���������¡�ص�ӭ��$n��Ϊ"+club_name+"��һ���ӡ�\n",me,ob);

        ob->delete_temp("joinclub");
        ob->set("club", club_name);
        ob->set("club_level", 0);
        ob->save();

        return 1;
}
                          
int help(object me)
{
        write(@HELP
ָ���ʽ : 
           capprove <id> 
           
���ָ������ð������������ᡣ


HELP
    );
    return 1;
}

