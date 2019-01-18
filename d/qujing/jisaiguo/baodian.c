#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���۱���");
  set ("long", @LONG

�������е�һ��������Ѻܾ�û���Ͻ��ˣ����ϵĽ��´󲿷�
���䣬�������ܻ�������Χ�������޺������ú첼������������
�����ź��Ļҳ��������е�С�ţ�����ͨ���Ҫ���ĵط���
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/kusu" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
//  "enter" : __DIR__"tower1",
  "southdown" : __DIR__"inner3",
]));

  setup();
}

void open_down()
{
        object tower;

        if( !(tower = find_object(__DIR__"tower1")) )
                tower = load_object(__DIR__"tower1");

        if( tower = find_object(__DIR__"tower1") ) 
        {
                set("exits/enter", __DIR__"tower1");
                message("vision", "������ʦ�ͳ���Կ�ף������ϵ�ͭ���򿪡�\n", this_object() );
		message("vision", "С�ű��˴�������ˡ�\n", tower );
        set("long", @LONG
    
�������е�һ��������Ѻܾ�û���Ͻ��ˣ����ϵĽ��´󲿷�
���䣬�������ܻ�������Χ�������޺������ú첼������������
�����ź��Ļҳ��������е�С�ţ��ſ��ţ�����ڶ����ġ�
LONG);
	}
	
        call_out("close_down", 300);
}

void close_down()
{
        object tower;

	message("vision", "С��ž��һ���ֹ����ˡ�\n", this_object() );
	if( tower= find_object(__DIR__"tower1")) {
	message("vision", "С�ű��˹����ˡ�\n", tower);
	tower->delete("exits/out");
	}

        delete("exits/enter");
        set("long", @LONG
    
�������е�һ��������Ѻܾ�û���Ͻ��ˣ����ϵĽ��´󲿷�
���䣬�������ܻ�������Χ�������޺������ú첼������������
�����ź��Ļҳ��������е�С�ţ�����һ��ͭ��������ͨ���
Ҫ���ĵط���
LONG);
}

