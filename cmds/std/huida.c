// answer.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string dest, topic, msg;
        object ob;
        mapping inquiry;

        seteuid(getuid());

        if( !arg || sscanf(arg, "%s is %s", dest, topic)!=2 )
                return notify_fail("你要回答谁什么事？\n");

          if(me->is_busy())
                return notify_fail("你正忙着呢!\n");
        if( !objectp(ob = present(dest, environment(me))) )
                return notify_fail("这里没有这个人。\n");

        if( !ob->is_character() ) {
                message_vision("$N对着$n自言自语．．．\n", me, ob);
                return 1;
        }

        if( !ob->query("can_speak") ) {
                message_vision("$N向$n回答『" + topic
                        + "』的答案，但是$n显然听不懂$N的话。\n", me, ob);
                return 1;
        }
       if( !living(ob) ) {
                message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
                        me, ob);
                return 1;
        }
      
                message_vision("$N向$n打听答案『" + topic + "』是否正确。\n", me, ob);

        if( userp(ob) ) return 1;
     
                        if(!ob->query("question"))
                                {
                                        tell_object(me, CYN + ob->name()+"目前疑惑还没解除了!请用ask指令"+ NOR);
                                        return 1;
                                }
                        if(ob->query("question")=="on")
                                {
                                        msg=QUIZ_D->comfirm_answers(ob,me,topic);
                                       message_vision( CYN + msg+ NOR,me);
                                       return 1;
                                 }
                         if(ob->query("question")=="done")
                         {
                                message_vision( CYN + ob->name()+"已经解除疑惑了!"+ NOR,me);
                                 return 1;
                         }
                         return 1;
                                 
        
                        
                                                
        
 

}

int help(object me)
{
   write( @HELP
指令格式: huida <someone> is <answer>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}

