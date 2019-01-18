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
                return notify_fail("��Ҫ�ش�˭ʲô�£�\n");

          if(me->is_busy())
                return notify_fail("����æ����!\n");
        if( !objectp(ob = present(dest, environment(me))) )
                return notify_fail("����û������ˡ�\n");

        if( !ob->is_character() ) {
                message_vision("$N����$n�����������\n", me, ob);
                return 1;
        }

        if( !ob->query("can_speak") ) {
                message_vision("$N��$n�ش�" + topic
                        + "���Ĵ𰸣�����$n��Ȼ������$N�Ļ���\n", me, ob);
                return 1;
        }
       if( !living(ob) ) {
                message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n",
                        me, ob);
                return 1;
        }
      
                message_vision("$N��$n�����𰸡�" + topic + "���Ƿ���ȷ��\n", me, ob);

        if( userp(ob) ) return 1;
     
                        if(!ob->query("question"))
                                {
                                        tell_object(me, CYN + ob->name()+"Ŀǰ�ɻ�û�����!����askָ��"+ NOR);
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
                                message_vision( CYN + ob->name()+"�Ѿ�����ɻ���!"+ NOR,me);
                                 return 1;
                         }
                         return 1;
                                 
        
                        
                                                
        
 

}

int help(object me)
{
   write( @HELP
ָ���ʽ: huida <someone> is <answer>

���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
HELP
   );
   return 1;
}

