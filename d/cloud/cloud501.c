// Room: /d/cloud/cloud501.c west of cloud50

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
		"east"		: __DIR__"cloud50.c",
		"west"		: __DIR__"cloud503.c",
		"south" 	: __DIR__"cloud502.c",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        me->add("mana", -10);
	return ::valid_leave(me, dir);
}


