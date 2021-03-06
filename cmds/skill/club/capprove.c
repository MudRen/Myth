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
                return notify_fail("只有帮会领导人才可以接受成员？\n");

        if(!arg) 
                return notify_fail("你要接受谁入帮？\n");

        ob = present(arg, environment(me));

        if(!ob) 
                return notify_fail("这里没有这个人。\n");

        if (ob == me)
                return notify_fail("你不能接受自己入帮派。\n");
     
        if (!userp(ob) && !wizardp(me))
                return notify_fail("你只能接受玩家入帮会！\n");
                       
        if(ob->query("club")) 
                return notify_fail("对方似乎已经加入了某个帮会。\n");
        
        if(ob->query_temp("joinclub") != me->query("id") )
                return notify_fail("对方并没有向你申请入会。\n");
   
        club_name=me->query("club");

        message_vision("$N经过慎重考虑，同意了$n的入会请求，隆重的迎接$n成为"+club_name+"的一份子。\n",me,ob);

        ob->delete_temp("joinclub");
        ob->set("club", club_name);
        ob->set("club_level", 0);
        ob->save();

        return 1;
}
                          
int help(object me)
{
        write(@HELP
指令格式 : 
           capprove <id> 
           
这个指令可以让帮主接收你入帮会。


HELP
    );
    return 1;
}

