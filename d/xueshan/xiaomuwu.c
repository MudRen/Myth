//standroom.c used by weiqi...others may hate this format:D
//xiaomuwu.c

inherit ROOM;

void create ()
{
	set ("short", "Сľ��");
	set ("long", @LONG

�߽����Сľ�ݣ����ֳ���һ���������Ȼů���ģ�������
�ı���ѩ�ط·����������硣���ڿ�ǽ����һȦ���СС�Ļ�
�裬�������Ÿ�ʽ�����в������ӵĻ��ݡ�����ܰ�����ֻ��
һλ��ɫŮ�������Ż�¯��������������������ȵذ���һ����
Ȼ���ּ���������
LONG);

	//set("item_desc", ([" *** " : " *** ", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"xiaomuwu",
		"north" : __DIR__"eroad2",
		//"west" : __DIR__"eroad1",
		//"east" : __DIR__"eroad3",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/kongque-gongzhu" : 1,
	]));


	set("outdoors", "xuesan");

	setup();
}

//void init()
//{
	//add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

void open_down()
{//this open_down() will be called by the NPC "kongque-gongzhu".
	object downroom;

	if( !(downroom = find_object(__DIR__"dixiashi")) )
		downroom = load_object(__DIR__"dixiashi");

	//if( downroom = find_object(__DIR__"dixiashi") ) 
	//{
		set("exits/down", __DIR__"dixiashi");
		downroom->set("exits/up", __FILE__);
		message("vision", "���ӵ���ͻȻ����������������¶��һ�����µĶ��ڣ�������һ�����ݡ�\n", this_object() );
		message("vision", "�컨���Ϻ�Ȼ����������������һ�����ݴ���������\n", downroom );
	//}

	call_out("close_down", 10);
}

void close_down()
{
	object downroom;

	if( !query("exits/down") ) return;

	message("vision", "���ӵ��·��������������������ַ����ˡ�\n", this_object() );

	if( downroom = find_object(__DIR__"dixiashi") ) 
	{
		message("vision", "�컨���Ϸ������������������ݱ�������ȥ��\n", downroom );
		downroom->delete("exits/up");
	}

	delete("exits/down");
}

