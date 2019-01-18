//cave3

#include <ansi.h> 
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIM"��¶�"NOR);
        set("long", @LONG
���˰��죬�㷢���Լ��ƺ���������ͤ���档�����������
ֻ�������������������ڿ���������Ʈ����
LONG);
 
        
        setup();
 
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_jump", "jump");
}
int do_climb(string arg)
{
       object me = this_player();

       if (arg != "up" ) return 0;
           if (!living(me)) return 0; 
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 40) 
     return notify_fail("�����ϵĶ���̫�࣬����������ȥ�ɣ���\n");
       if((int)me->query_skill("dodge",1) < 80 )  
       return notify_fail("����Ŀǰ���Ṧ��Ϊ����������ȥ��\n"); 
       message_vision("$N��ס��ʯ��С�ĵ�������ȥ��\n", me);
        me->move(__DIR__"shishi3");
       tell_room(environment(me), me->name() + "����¶�������������\n", ({ me }));
       return 1;
       
}
int do_jump(string arg)
{
       object me;
       me = this_player(); 
        if (arg != "river" ) return 0;
       if ( !arg ) return 0;
       if (!living(me)) return 0;
       message_vision("$N��������һ��С�ӡ���ѽ����Ҫ��ɱѽ��\n", me);
         me->move(__DIR__"xiaohe1");
       tell_room(environment(me), me->name() + "����¶������˽�����\n", ({ me }));
       return 1;
}

