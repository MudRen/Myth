// sanjie shanlu3.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG
	
��ɽ��·��������ˣ�ǰ����һ��ʯ��(shi bi)��ʯ�ڲ���
���ߣ�������(jump)��ȥ�������ѡ�
LONG);

  set("exits", ([
  "southdown" : __DIR__"shanlu2",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "shi bi") ))
                return notify_fail("��Ҫ��������\n");
        else if(me->query("kee")<50)   
          {
           me->unconcious();
           message_vision("$N����һ������������������ˤȥ��\n",me);
          }
	else
          {
           me->add("kee",-50); 
           message_vision("$N����һԾ�����ɵ�����ʯ�ڡ�\n",me);
           me->move("/d/sanjie/shanlu4");
           tell_room(environment(me),"ֻ��"+me->name()+"����Ծ��������\n", me);
           return 1;
           }
        return 1;
}