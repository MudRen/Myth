// hubian.c
// by shilling 97.2

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC "��Ĺ����"NOR);
        set("long", @LONG
����Ҳ�ǿյ�����ûʲô���裬ֻ�������ڶ�����һ������
(pic)��˵��������ԯ���Ļ���һ�����紵��������һ��
΢΢���𣬻���ĺ��������ʲô����......

LONG );
        set ("item_desc", ([
                "pic" : "��ԯ���Ļ���ֻ����һ���������ȣ��ɷ���ǣ���ֹ����
\n"
        ])  ) ;
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"girlbed.c",
  "east" : __DIR__"boybed.c",
  "south" : __DIR__"zhongting.c",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xiaoyao" );
        setup();
}

void init()
{
        add_action("do_push","push");
        add_action("do_zuan",({"zuan","enter"}));
}

int do_push(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg!="pic") return 0;
        write("�㽫����������������......\n");
       if(random((int)me->query("kar")) < 10 )
              if(random((int)me->query("str")) < 10 )
                {
                write("ͻȻ�����ʲô����ҧ��һ�ڣ��㼱æ�������ء�\n");
                return 1;
                };
        write("����󽥽�¶��һ���������ߵĶ�Ѩ(hole)��\n");
        me->set_temp("marks/push",1);
        return 1;
}

int do_zuan(string arg)
{
        object me;
        me = this_player();
        if (!me->query_temp("marks/push")) return 0;
        if ( arg != "hole") return 0;
        message_vision("$NС�ĵ���������Ķ�Ѩ��......��\n", me);
        me->move(__DIR__"bingyu.c");
        return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("marks/push") ) me->delete_temp("marks/push");
        return ::valid_leave();
}

