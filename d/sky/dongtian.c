//dongtian.c
//created 4-8-97, pickle

#include <room.h>
#include <ansi.h>
inherit ROOM;

int valid_leave();

void create ()
{
  set ("short", "������");
  set ("long", @LONG

   ���ž������֮�࣬����������˻�����������Щǧ�����Գ�
�������ţ���ʳ���Ϊ�λ�Ҫ�����أ��ǲ�����Ϊ����һչ����
�����쳤̾��

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/tian-ding2" : 1,
  __DIR__"npc/tian-ding1" : 1,
//  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dongmenting",
  "north" : __DIR__"en1",
  "south" : __DIR__"es1",
  "east": __DIR__"yun1",
]));

create_door("west", "������", "east", DOOR_CLOSED);
  setup();
}

int valid_leave(object me, string dir)
{
 
        if (dir == "west") {
		if(member_array("zengzhang tianwang", me->parse_command_id_list())==-1
		&& member_array("huguo tianwang", me->parse_command_id_list())==-1 ){
			if(present("tian ding", environment(me) ))
				return notify_fail("�����춡����һ���֣��µ������������\n");
		}



                return ::valid_leave(me,dir);
        }
	return ::valid_leave(me,dir);
}

