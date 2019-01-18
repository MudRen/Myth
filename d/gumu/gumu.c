// hubian.c
// by shilling 97.2

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIB "��ԯ��Ĺ"NOR);
        set("long", @LONG
һ���ܴ�ķ�Ĺ�����������ǰ���ڳ������ϵ�һƬ�ĵ���
�Եø������ɭ�ֲ���һ��Ĺ��(tombstone)�����ڷ�ǰ����
Χ��������ض��˺ü�ʮ����ͷ����Щ��ǰ����Щ���룬��ֽ
�ĺۼ�,��ֻѰʳ��Ұ��������ת�ƣ�ȴʼ�ղ��ҿ����������
Ĺ����ʲô�ֲ��Ĺ��ż�������Ǻ������˾���ë���Ȼ��
LONG );
        set ("item_desc", ([
                "tombstone" : "Ů����¾�����Ů ����槼� ֮Ĺ��\n"
        ])  ) ;
        set("exits", ([ /* sizeof() == 2 */
                "south" : "d/changan/fendui",
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
        if (!arg||arg!="tombstone") return 0;
        write("������˫�ۣ�˫�ַ���Ĺ��������תһ�£��漴������ת\n");
       if(random((int)me->query("kar")) < 10 )
              if(random((int)me->query("str")) < 10 )
                {
                write("�ζ��ζ���һ�£�����һ�μ��ء�\n");
                return 1;
                };
        write("����ת��һ��ʱ��ֻ������ડ�һ��Ĺ����¶��һ���������ߵĶ�Ѩ(hole)��\n");
        me->set_temp("marks/push",1);
        return 1;
}

int do_zuan(string arg)
{
        object me;
        me = this_player();
        if (!me->query_temp("marks/push")) return 0;
        if ( arg != "hole") return 0;
        message_vision("$N���һ��ˣ��������ܲ���Σ�գ���һ���������Ĺ֮�С�����Ѩ�Զ��ϱա�\n", me);
        me->move(__DIR__"yongdao1.c");
        return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("marks/push") ) me->delete_temp("marks/push");
        return ::valid_leave();
}

