#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����̨");
  set ("long", @LONG

�������зǳ��ķ��������������ǳ��ġ�һ���������ɵĸ�̨��
���������зֿ����Ӹ�̨�Ͽ��Ը���ȫ�ǣ�ֻ����¥����ϣ�
���������˵��¹�¡�أ������񸻺������������Ź�����̨ǰѲ
�ӣ���ֹ�����˵����ڡ�
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/guan" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"centermarket",
  "north" : __DIR__"wufeng",
]));

  set("valid_startroom", 1);
  setup();
}

int valid_leave(object me, string dir)
{       
	object a,b;
        if( wizardp(me)) return 1;
	if( present("shu tie", me) ) return 1;
	if( present("xiazi", me) ) return 1;
        if( present("tooth", me) ) return 1;

        if (dir == "north") {
                if(objectp(a=present("guan", environment(me))) && living(a) )
		return notify_fail("���Źپ��������䵶����ס�����ȥ·��\n");
                if(objectp(b=present("guan 2", environment(me))) && living(b) )
                return notify_fail("���Źپ��������䵶����ס�����ȥ·��\n");

        return ::valid_leave(me, dir);
        }

        return 1;
}

