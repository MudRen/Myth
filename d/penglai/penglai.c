//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "�����ɵ�");
  set ("long", @LONG

�������Ϸ�������������Ǻ�ȥ����Զ�����У��̲��羵����ɽ֮
�ϣ�Ρ�����ʡ�ɽ������������������Գ�����������������Ұ�ף�
���������ɽݺ���������ܴ��ң�ʯ�����������Զɽ�����Ƴ��ԣ�
���ֻ�ɫ���ء�
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"undertree",
  "southup":  __DIR__"hongyandong",
]));
	set("outdoors", 1);
  setup();
}
int valid_leave(object me, string dir)
{       
	object room;

	if (dir=="northup"){
		if( room=load_object(__DIR__"yashang")) {
			if( (int)room->query("grow_grass") ) {
			return ::valid_leave(me, dir);
			}
			room->grass_grow();
			room->set("grow_grass",1);
		}
	return ::valid_leave(me, dir);
	}
	return 1;
}
