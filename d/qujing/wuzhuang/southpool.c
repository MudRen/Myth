//Cracked by Roath

//southpool.c

inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG

�����ϱߡ����б�����ᣬ������������������ݺύ����˺�
����Сľ�ţ���֪��һ����ͨ���԰��ġ�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southwest" : __DIR__"shuoyaopu",
		"southeast" : __DIR__"mudanting",
		"north" : __DIR__"wzgmaze1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	set("outdoors", "wuzhuang");

	setup();
}
