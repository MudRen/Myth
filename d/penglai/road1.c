//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "ɽ��С·");
  set ("long", @LONG

�������Ϸ�������������Ǻ�ȥ����ɽ���С·�����滨���
��������Ŀ���ޡ��������ɹ��٣���������ͣЪ��ǰ��һ��ʯ
�¸��ʣ��Ϸ���һС�ף�͸���������⡣
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"baiyun19",
  "north": __DIR__"yaxia",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/baiyuan" : 1,
]));

	set("outdoors", 1);
  setup();
}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "north") {
                if(objectp(a=present("bai yuan", environment(me))) && living(a) )
                return notify_fail("��Գ�趯���г���������Ը�����ȥ��\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}

