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
                "east" : __DIR__"no4-enter",
                "north" : __DIR__"no4-wn1",
                "west" : __DIR__"no4-w2",
	]));
	
	set("objects", 
	([
                __DIR__"npc/hudie" : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}

