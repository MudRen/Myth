#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���������");
  set ("long", @LONG

·�����⽨����£���ɫ����ǽ���������������ϸ���ɫ��Ƭ��
�ֵ��ܿ������������࣬·��ܸɾ�������Ϊɮ�˾�����ɨ��
Ե�ʡ�·����Ӵ������򣬼���Сͯ��·����ˣ��
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"west3",
  "east" : __DIR__"south1",
]));

  setup();
}

