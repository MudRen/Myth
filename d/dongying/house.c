
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǡ���ȵ������Ĵ�����ֻ��һ�Ű����Ϲ���һ������(duilian)��
�ƺ����������и��ص���
LONG );
	set("valid_startroom", 1);
	set("exits", ([
	"south" : __DIR__"road1",
	]));
	set("item_desc", ([
"duilian":
HIC "\n\n��������  ���Ͻ���ָ����\n" NOR +
HIG "\n��ն�ε�  δ���������ʹ��\n" NOR,
	]));
	set("objects", ([
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "���ȼ�˻��ۣ���������ʯ������һ���ѷ죬�ƺ�������(zuan)��ȥ��\n"
             );
             this_player()->set_temp("marks/��", 1);
             return 1;
       }
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (me->query_temp("marks/��") ) {
            message("vision", me->name() + "����һ�²�֪��ʲô�ط����ȥ�ˡ�\n",
                    environment(me), ({me}) );
            me->move(__DIR__"cave");
            message("vision", me->name() + "��ʯ�������˳�����\n",
                    environment(me), ({me}) );
            this_player()->set_temp("marks/��", 0);

            return 1;
        }
        else {
            write("�������Ķ���?!\n");
            return 1;
        }
}
