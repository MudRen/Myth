#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ƽ����·");
  set ("long", @LONG

����һ��������ֱ�Ĵ�ٵ�������ݵ���ʮ���ۡ�����ֱͨ��
������������߾͵��˼��������ϱ�һ����С·����֪ͨ���
��������������������������߹���
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"westgate",
  "west" : __DIR__"pingxi1",
  "southwest" : "/d/qujing/bibotan/yangchang3",
]));

  setup();
}

