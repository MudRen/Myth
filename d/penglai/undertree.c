//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "���ƶ��⣬����֮��");
  set ("long", @LONG

һ�ø������ɵĴ�������ɡ�����ס����գ������ϴ�������
�����ܸ��٣��м�����ЩС������������һ��ʯ̨���������
һ��Χ���̣�ʯ̨��������ʯ�ʡ���������һʯ������ǰʯ��
�Ͽ��š����ƶ����������֡�
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "enter" : "���а������ƣ�ʲôҲ���������\n",
]));
  set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"baiyun0",
  "southdown" : __DIR__"penglai",
]));

  set("objects", ([ 
  __DIR__"npc/shouxing" : 1,
  __DIR__"npc/luxing" : 1,
  __DIR__"npc/fuxing" : 1,
]));
  setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "enter"){
		if(objectp(present("shou xing", environment(me))))
			return notify_fail("����������ס�㣺�������Ϸ����ң���ȥ��ʲô��\n");
        	if(objectp(present("fu xing", environment(me))))
                	return notify_fail("����������ס�㣺�������Ϸ����ң���ȥ��ʲô��\n");  
        	if(objectp(present("lu xing", environment(me))))
                	return notify_fail("»��������ס�㣺�������Ϸ����ң���ȥ��ʲô��\n");  
	return ::valid_leave(me, dir);
	}


return ::valid_leave(me, dir);
}

