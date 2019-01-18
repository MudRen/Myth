// sanjie tianyifu.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "��һ�ɸ�");
  set ("long", @LONG
	
��һ�������˹������Ľ���ͷ������������ʦ�ƺ�����
һ�㶫����û�з��£�����һ�����������˼䣬�İ�������
�����ڵ�����Ե����������
LONG);
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/chunyang": 1 ]) );
  setup();
}
void init()
{
	add_action("do_knock", "knock");
	add_action("do_knock", "qiao");
}

int do_knock(string arg)
{
	object me, outroom;
	
	me=this_player();

	if( !arg || (arg != "wall" && arg != "qiang" && arg != "ǽ" && arg != "ǽ��" ) )
		return notify_fail("��Ҫ��ʲô��\n");       

	call_out("open_out", 1);
	return 1; 
}

void open_out()
{
	object outroom; 

	if( outroom = find_object(__DIR__"tianyidong6") ) 
	{
		set("exits/out", __DIR__"tianyidong6");
		outroom->set("exits/enter", __FILE__);
		message("vision", "ǽ��ͻȻ����������������¶���˳�ȥ��һ�����ڡ�\n", outroom );
		message("vision", "ǽ�ں�Ȼ����������������¶����һ�����ڡ�\n", this_object() );
	}

	call_out("close_up", 10);
}

void close_up()
{
	object outroom;

	if( !query("exits/out") ) return;

	message("vision", "����ͼ���������������������ַ����ˡ�\n", this_object() );

	if( outroom = find_object(__DIR__"tianyidong6") ) 
	{
		message("vision", "����ͼ�������������������ڲ����ˡ�\n", outroom );
		outroom->delete("exits/enter");
	}

	delete("exits/out");
}