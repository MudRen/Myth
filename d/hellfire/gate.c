inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"�������"NOR);
        set("long", @LONG

����������������������������������������������������������������
������  ���������ˣ�û��һ������Ϊ����û��ǲ�Ҫ�Ҵ�Ŷ��������
����������������������������������������������������������������

LONG);
        set("exits", ([
                "up" : "/d/city/dowmtown1",
                "down" : "/d/hellfire/hellfire1/in.c",
        ]));
        set("objects", ([
                __DIR__"npc/mofashi" : 1,
        ]));
    set("hellfireroom",1);
    set("position_max",4);
        setup();
}
int valid_leave(object me, string dir)
{
        object a;
   if (dir == "down" ) {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("������ס��˵������ֹͨ�С�\n");
        }   
        return ::valid_leave(me, dir);
}
