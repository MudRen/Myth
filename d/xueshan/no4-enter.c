//sgzl
inherit ROOM;

void create ()
{
	set ("short", "ѩ��");
	set ("long", @LONG

ãã��ɽ����һ���޼ʵİ�ѩ���������ż���ǳǳ���㼣����Ȼ��
��Ԯ����һ���ѩɽ���ӣ��Ṧ��Ȼʮ���˵��ˡ�
LONG);


	set("exits", 
	([ //sizeof() == 4
                "down" : __DIR__"xuejie-3",
                "west" : __DIR__"no4-w1",
                "east" : __DIR__"no4-e",
                "up" : __DIR__"lingjiu",
	]));
	
	set("objects", 
	([
                __DIR__"npc/chongzi" : 2,
	]));


	set("outdoors", "xueshan");

	setup();
}


