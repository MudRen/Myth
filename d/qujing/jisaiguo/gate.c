#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

��ǰ��һ���ң������߸��ֽ���֡��⽨��������¡���������
���Ű��������ͭ��������ܾ�û�д��˵����ӡ�ֻ��ƫ����
��һ�칩�˳��롣ż������ɮ�˽�����Ҳ�ǵ�ͷ�첽����������
ͣ����
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"inner1",
  "west" : __DIR__"south1",
  "east" : __DIR__"south2",
]));
  create_door("north", "ƫ��", "south", DOOR_CLOSED);

  setup();
}
