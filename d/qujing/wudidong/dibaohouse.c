//dibaohouse.c
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ر���");
        set("long", @LONG

    �ŵر������м������ڴ���������Ǯ�����Ҳ���ɻ��������
���﷢������үƢ�����Ǵ�С�������ˣ��������ҵ������ѣ�Ҳ��˵
��ʰ��ʰ�����˷������ϻ��Ǳ��ӳ����볯�ء�

LONG
        );

	set("exits", ([
                "south" : __DIR__"road1",
        ]));

	set("objects", ([
                __DIR__"npc/dibao" : 1,
        ]));

	setup();
}

