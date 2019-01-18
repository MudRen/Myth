// Room: /d/cloud/cloud21.c southeast of cloud2

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
		"west" 		: __DIR__"cloud23.c",
		"north" 	: __DIR__"cloud21.c",
		"northwest"	: __DIR__"cloud2.c",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	me->add("mana", -10);

	return ::valid_leave(me, dir);
}

