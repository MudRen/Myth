
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�཭");
  set ("long", @LONG

�཭ˮ�治����ˮ��������ȥ��������ż�����ּ�ֻ����
��С����һ����·˳�����̣���ֱͨ���཭�볤���Ĺ཭�ڡ�
·��ż�м������ˣ�������ɫ�Ҵң�æ�Ÿ�·��
LONG);


  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/luke" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/meishan/guanjiang2",
  "southeast" : __DIR__"denglong1",
]));

  setup();
}

