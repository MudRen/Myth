//standroom.c used by weiqi...others may hate this format:D
//xihai.c

inherit ROOM;

void create ()
{
	set ("short", "����֮��");
	set ("long", @LONG

������һ���޼ʵ�ѩԭ��Ρ����ΰ�ı�ɽ��ͻȻ��̲����꣬��
�׳����ˮ��չ������ǰ�����ʱ����һ����������ӿ����ͷ��
ɽ�������ݣ��񣬷·��ǵ�����һ�����硣
LONG);

	//set("item_desc", ([" *** " : " *** \n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xueshan4",
		//"north" : __DIR__"xueshan6",
		"east" : __DIR__"xueshan5",
		//"west" : __DIR__"eroad1",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
  set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/hama" : 1,
	]));


	set("outdoors", "xueshan");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}



