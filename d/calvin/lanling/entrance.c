inherit ROOM;
#include <ansi.h>
void create()
{
          set("short", "���������");
        set("long", @LONG

����������������������������������������������������������������
������  ���������ˣ�û��һ������Ϊ����û��ǲ�Ҫ�Ҵ�Ŷ��������
����������������������������������������������������������������

LONG);
        set("exits", ([
                "north" : __DIR__"kingziminggong",
                "south" : "/d/9ct/qy/huayuan",
        ]));
        set("objects", ([
                __DIR__"npc/guard1" : 2,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        object a;
   if (dir == "south" ) {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("������������ס��˵���������켫��Σ�գ����˲�Ҫ���ˣ����ǲ�Ҫ��ȥΪ�á�\n");
        }   
        return ::valid_leave(me, dir);
}
