//Cracked by Roath
//standroom.c used by weiqi...others may hate this format:D
//tingjing.c

inherit ROOM;

void create ()
{
	set ("short", "����ʯ");
	set ("long", @LONG

���ʯͷ(stone)״����ֻ���Եĺ��꣬������ſ�ں�̲�ϡ���˵
���������������ɶ�����ȥ͵�����������Ҫ���Ǽ��¾��ģ�
��������ˮ�彲�⡣���ϣ�������������ȫ���ע�¾������
���ش󺣵�ʱ�䣬���Ϊʯͷ��
LONG);

	set("item_desc", (["stone" : "ʯͷ�Ͽ���һ��ʫ�� \n
		��˵���������飬
		����������̸����
		������·���ʯ��
		���ǵ��겻������\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"***",
		//"north" : __DIR__"wuchang-s",
		"south" : __DIR__"island",
		"north" : __DIR__"shanglu2",
                "east" : "/d/quest/m_weapon/lianzhangshi",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "/d/nanhai");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

