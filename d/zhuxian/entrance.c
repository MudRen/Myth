inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG"���"NOR);
        set("long", @LONG
���������ˣ�û��һ������Ϊ����û��ǲ�Ҫ�Ҵ�Ŷ��
LONG);
        set("exits", ([
                "north" : __DIR__"fenghou",
                "south" : __DIR__"xiaolu1",
        ]));
        set("objects", ([
                __DIR__"npc/guard1" : 2,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        object a;
   if (dir == "north" ) {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("������ס��˵���������Ժ�Ͳ����߳����ˣ����ǲ�Ҫ��ȥΪ�á�\n");
        }   
        return ::valid_leave(me, dir);
}
