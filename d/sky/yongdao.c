#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "��");
  set ("long", @LONG

��������ʯ�����̵أ���������ʱ��л֮�ɻ���ݣ���طҷ���
�������з�����ɫ��Ʈ�㡣��Χ���������¥���������
�̲���
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"zhanyaotai",
    "west" : __DIR__"yunlougate",
    "south": __DIR__"taizifu",
    "north": __DIR__"yunlou",
  ]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/tong-nan" : 1,
]));


  set("outdoors", 1);
  setup();
}


