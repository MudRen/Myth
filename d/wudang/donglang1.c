// donglang1.c ��������
//lpg 19991005

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ�������ϣ������м������ң��������������֡������Ǵ�
LONG );
        set("exits", ([
                "west" : __DIR__"sanqingdian",
        ]));
        setup();
}
