//xuetang.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ѧ��");
	set("long", @LONG

    ������ػ���־��ֻ��ϧ�뾩ȥ��״Ԫ��������ɽ���װ��˷���
�����̲������ֻ�ûؼ�������ѧ�ã����Һ��ڡ��̵ĵ����ǿ���֮
�飬�����֮����Ҳ��һ��ѧ������߬��֦������ɳ������д���š�
�֣�����ű����֣������л�����ȥ��ǽ�Ϲ���һ��ʫ (poem)����
д�����ɷ���ġ�

LONG
        );

set("item_desc",(["poem":"

\t \t����ҰӪ�и�
\t \t  �ż�����

\t��\tҹ\t��\t��
\t��\t��\t��\t��
\t��\t��\t��\t��
\t��\t��\t��\t��
\t��\t��\tҧ\t��
\t��\t��\t��\t��
                  \n"]));

	set("exits", ([
		"south"  : __DIR__"road3",
        ]));

	set("objects", ([
		__DIR__"npc/xiucai" : 1,
		__DIR__"npc/boy" : 2,
		__DIR__"npc/girl"  : 2,
        ]));

	setup();
}
