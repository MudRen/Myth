
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���Ϲ�ʯ��ᾣ���Ϊ���ߡ�ʯͷ��ɫ��ʣ�Զ�����糯�ƣ���
���ڴˡ���ɽ��������ˮ����һ������������ȥ������ɽ��
ӿ������һƬ��
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/yao" : 1,
  __DIR__"npc/li" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"sengquan",
  "northwest" : __DIR__"jixian",
]));

  setup();
}


