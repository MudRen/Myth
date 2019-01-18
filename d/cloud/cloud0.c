// Room: /d/cloud/cloud0.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ƶ�");

	set("long", @LONG

    ��վ���ƶˣ���������ȥ��������һ���޼ʵ��ƺ���ͷ���Ǳ�������ա�
������ȥ��ֻ��һƬ������ɫ��ż����һЩϸϸ�İ��߹ᴩ���С�һֻС��
ݺ���ĵش��ƴ���̽��ͷ�����ܾ��ȵؿ����㡣

LONG
	);

	set("exits", ([
		"east"		: __DIR__"cloud1.c",
		"southeast"	: __DIR__"cloud2.c",
		"south" 	: __DIR__"cloud3.c",
		"southwest" 	: __DIR__"cloud4.c",
		"west"		: __DIR__"cloud5.c",
		"northwest"	: __DIR__"cloud6.c",
		"north"		: __DIR__"cloud7.c",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	me->add("mana", -10);

	return ::valid_leave(me, dir);
}

