
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����������ϱ���÷ɽ�ˣ�����������ɽ��Ψһ��·��·����
������ʯ���ߴ������������������Դ˵ص��������ء�����
�˳´�Ϊ�������裬��Ϊ���������Ѹ�������
LONG);


  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/meishan/erlangwai",
  "east" : __DIR__"fenglin1",
]));

  setup();
}
int valid_leave(object me, string dir)
{       
	if( wizardp(me)) return 1;

	if (dir == "east") {

        if (!me->query_temp("erlangpass") ){
return notify_fail("��������и��˾�ס�㣬�㶯Ҳ�����ˣ�\n");
                }
        return ::valid_leave(me, dir);
        }

        return 1;
}

