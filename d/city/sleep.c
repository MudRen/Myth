inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","�͵�˯��");
        set("long", @LONG

��ջ��һ��˯��������ɸɾ�����һ�Ŵ󴲣�����������Ϣ˯����
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);

        set("exits", ([
                "west" : __DIR__"kezhan",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}

