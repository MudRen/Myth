#include <room.h>
inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
���廨԰��������֣���ҹ����ʱ�����������ڡ�����ϸ�裬
���΢���������ڴˣ�����֮���Ŷ�ʱ������ɢ��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"  : __DIR__"bamboo2",
          "north"  : __DIR__"bamboo1",
      ]));
      setup();
}

