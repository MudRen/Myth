//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���");
        set("long", @LONG
        �����Ǻ�������Ĵ������һ�壬�����Ǽ�����������¯�������档
��������Ϣ�ң���������һ��С·ͨ����ɽ���ء�
LONG
        );

        set("exits", ([
                "north" : __DIR__"jisiting",
                "south" : __DIR__"dadian",
                "west" : __DIR__"restroom",
                "northeast" : __DIR__"houshan",
        ]));
        set("objects", ([
                __DIR__"npc/zuidao" : 1,
                __DIR__"npc/qingfeng" : 1,
        ]));
        setup();
        //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

   if (dir == "north" ) {
        if (me->query("family/family_name") != "��ɽ����")
        return notify_fail("��ɽ����ĵط���������ȥ�ĵط���\n");
        }   
        return ::valid_leave(me, dir);
}
