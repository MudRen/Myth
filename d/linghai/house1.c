//by dewbaby
//house1
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIM"��԰"NOR); 
         set ("long", @LONG 
        
�߳����⣬̤����԰�������������ģ���ʲô��
���������ֻ���ƺ������������ֽ���Щ������
��˫��Ѱ��ʯ����ǰ��ȥ��ÿһ�������õ���
ˮ�������������ʱ��һ�����������㳯����ȥ��
LONG); 
        
         
       setup();
}
void init()
{
       add_action("do_push","push");
}

int do_push(string arg)
{
       object me = this_player();
 
       if (arg != "door" ) return 0;
       if ((int)me->query_skill("force",1) < 200)
       return notify_fail("����ڹ��ķ�������������ʯ�ź���ܻ�������Σ�գ�\n");
       if ((int)me->query_skill("dodge",1) < 200)
       return notify_fail("����Ṧ���������治֪��������ô���������!\n");
       message_vision("$N������ƿ��˱����ʯ�ţ�����������һ��!\n",me);
       me->move(__DIR__"masterroom");
       tell_room(environment (me), me->name() + "����԰�����˽�����\n",({me}));
       return 1;
}
