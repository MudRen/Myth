//sgzl

#include <room.h>
inherit ROOM;

void create()
{

	set("short", "ˮ������");
	set("long", @LONG
������ǻ���ɽˮ���������ã����ܹ���ư������
��ȫ������һ�Ż�Ƥ���ӣ����ǹ�ˮ��������Ϣ�ġ�
LONG );


	set("exits", ([
	    "west"   : __DIR__"shifang",
	]));


	set("objects", ([
	    __DIR__"npc/mowang" : 1,
	]));



	setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed" );
        add_action("do_bed", "bed");
}


int do_bed()
{       object me;
        me=this_player();
        message_vision("$N��ʯ����һ�ɣ�׼��˯���ˡ�\n\n", me);
        me->move(__DIR__"shichuang");
            message_vision("\n$N��ʯ����վ��������\n", me);
                return 1;
}


int valid_leave(object me, string dir)
{
 
        if (dir == "west") 
        {
                {
                        if(present("hunshi mowang", environment(me) ))
                                return notify_fail("����ħ����������Ц���������ߣ�û��ô���װɣ���\n");
                }



                return ::valid_leave(me,dir);
        }
        return ::valid_leave(me,dir);
}

