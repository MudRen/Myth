//dongmenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "������");
        set("long", @LONG

���˶����ţ��Ѿ����Կ���һ�����칬�����߲�ϼ�⣬��������
����������֮�С�һ�����������������������죬�������߸�
��һ����Ҳ��֪�Ǹ�ʲô�õģ��������Լ�������ߵ���˻
˻������
LONG
        );
 
        set("exits", ([
                "east" : __DIR__"dongtian",
		"north":__DIR__"yumajian",
        ]));
 
        create_door("east", "������", "west", DOOR_CLOSED);
 
        set("objects", ([
                __DIR__"npc/tong-nan" : 2,
        ]));
 
        setup();
}
