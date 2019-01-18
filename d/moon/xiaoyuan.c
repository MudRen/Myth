//Cracked by Roath
// Room: /d/moon/xiaoyuan.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_stand(string temp2);
int do_sit(string temp3);

void create ()
{
  set ("short", "���СԺ");
  set ("long", @LONG

���Χ�ɵ�СԺ�������������滨��ݡ��м���һ��ľ������ֻСľ�ʣ�
���ϰ��Ÿ�ɫ��Ʒ����������������һ�侫�µ�С�ݡ�
LONG);

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/guihuageng" : 1,
  __DIR__"obj/jiudai" : 1,
  __DIR__"npc/yuenu" : 1,
  __DIR__"obj/xueli" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"eroom",
  "north" : __DIR__"nroom",
  "south" : __DIR__"ontop2",
  "west" : __DIR__"wroom",
]));
  set("valid_startroom", 1);

  setup();
  call_other("/obj/board/moon_b", "???");
}

void init()
{
	add_action("do_stand", "stand");
	add_action("do_sit", "sit");
}

int do_sit(string arg)
{     
      object me;

      me=this_player();

	if ( !arg || ((arg != "seat")&&(arg != "deng")&&(arg != "table") ))
		return notify_fail("��Ҫ����ʲô���棿\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ������ˡ�\n");	
      
      if ( arg != "seat"&&arg != "deng")	
	      return notify_fail("�������ϣ�̫���Ź��˰ɡ�\n");
        	
	this_player()->set_temp("marks/sit", 1);
	message_vision("$N�������ɵ�������Сľ�ʡ�\n",me);
      return 1;	
}

int do_stand(string arg)
{
      object me;

      me=this_player();

      if (!this_player()->query_temp("marks/sit"))
          return notify_fail("�㱾����վ�š�\n");

      this_player()->set_temp("marks/sit", 0);
      message_vision("$N���˸�������վ��������\n", me);
      return 1;
}


