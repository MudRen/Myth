//sgzl
inherit ROOM;

void create ()
{
	set ("short", "ѩ·");
	set ("long", @LONG

ããѩҰ�У�Զ��������һ�ˣ��ֳ����У��������ݣ�
��ű���ѩɽ�ɸ���ӭ�͵����Ŵ�ʦ���ˡ�
LONG);


	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"xuejie",
		"west" : __DIR__"wroad1",
		"east" : __DIR__"eroad1",
                "southdown" : __DIR__"xuelu2",
	]));
	
	set("objects", 
	([
//zhang men������ˣ���û�޸�֮ǰ����cut. by seng@2005-1-26
// 24    "/obj/zhangmen/xueshan" : 1, 
	]));


	set("outdoors", "xueshan");

	setup();
}



