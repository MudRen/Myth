// under2.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ˮɫ��Ļ�����������Χ�ѿ���������ˡ�ż�а���Ϯ������
��������������ϲ�һƬ��ɫ���ƺ���ˮҲȾ���ˡ�
LONG);

  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/kid2" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"under3",
  "south" : __DIR__"maze1",
]));
//      
        set("water", 1);
//  
        setup();
}

void init()
{       
        object me=this_player();

                remove_call_out("greeting");
                call_out("greeting",5, me);
        
}

void greeting(object me)
{
        if( !me || environment(me) != this_object() ) return;

	message_vision("ͻȻһ����ӿ������$N�嵽��ç�����\n", me);
	me->move("/d/sea/maze5");
	return;
}
