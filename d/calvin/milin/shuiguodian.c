#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ˮ����");
  set ("long", @LONG

ˮ�������ˮ����డ,��Զ���ŵ�����
���ϰ�˵�����ˮ������������������
�óԵĲ����˵�!
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
       "south" : "/d/calvin/milin/milin3",    
]));

  setup();
}
