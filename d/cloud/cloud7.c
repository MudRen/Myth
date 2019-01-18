// Room: /d/cloud/cloud7.c north of cloud0

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ƶ�");

	set("long", @LONG

    ��վ���ƶˣ���������ȥ��������һ���޼ʵ��ƺ���ͷ���Ǳ�������ա�
������ȥ��ֻ��һƬ������ɫ��ż����һЩϸϸ�İ��߹ᴩ���С��������
�������ˡ�

LONG
	);

	set("exits", ([
		"southeast"	: __DIR__"cloud1.c",
		"south" 	: __DIR__"cloud0.c",
		"west"		: __DIR__"cloud6.c",
		"north"		: "/d/dntg/sky/nantian",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        me->add("mana", -10);

	return ::valid_leave(me, dir);
}

